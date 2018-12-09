#include "pch.h"
#include "StateHandler.h"

void StateHandler::addState(StateRef newState, bool isReplacingTop)
{
	_isAdding = true;
	_isReplacingTop = isReplacingTop;

	_newState = std::move(newState);
}

void StateHandler::removeState()
{
	_isRemoving = true;
}

void StateHandler::processStateChanges()
{
	//If we were to remove
	if (_isRemoving && !_states.empty())
	{
		_states.pop();

		if (!_states.empty())
		{
			//Put the top state to run
			_states.top()->resume();
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
				_states.top()->pause();
			}
		}
		//Add state to pile
		_states.push(std::move(_newState));
		//Init the added state
		_states.top()->init();
		_isAdding = false;
	}
}

StateRef &StateHandler::getActiveState()
{
	return _states.top();
}