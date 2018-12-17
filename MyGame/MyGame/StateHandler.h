#pragma once
#include <stack>
#include <memory>
#include "State.h"

//Pointer that auto manages itself.
typedef std::unique_ptr<State> StateRef;

class StateHandler
{
private:
	//States container
	std::stack<StateRef> _states;
	//State to add
	StateRef _newState;
	//Tracker
	bool _isReplacingTop, _isAdding, _isRemoving;
public:
	StateHandler() {}
   ~StateHandler() {}

	//Handler logic
	void AddState(StateRef newState, bool isReplacingTop = true);
	void RemoveState();
	void ProcessStateChanges();
	//Getters
	StateRef &getActiveState();
};