#include "pch.h"
#include "StateHandler.h"

void StateHandler::AddState(StateRef newState, bool isReplacingTop)
{
	_isAdding = true;
	_isReplacingTop = isReplacingTop;

	_newState = std::move(newState);
}

void StateHandler::RemoveState()
{
	_isRemoving = true;
}

void StateHandler::ProcessStateChanges()
{
	//If we were to remove
	if (_isRemoving && !_states.empty())
	{
		_states.pop();

		if (!_states.empty())
		{
			//Put the top state to run
			_states.top()->Resume();
		}

		_isRemoving = false;
	}

	//If we were to add
	if (_isAdding)
	{
		if (!_states.empty())
		{
			//Replace for a new one
			if (_isReplacingTop)
			{
				_states.pop();
			}
			else
			{
				//Pause top as it will no longer be on top
				_states.top()->Pause();
			}
		}
		//Add state to pile
		_states.push(std::move(_newState));
		//Init the added state
		_states.top()->Init();
		_isAdding = false;
	}
}

StateRef &StateHandler::getActiveState()
{
	return _states.top();
}