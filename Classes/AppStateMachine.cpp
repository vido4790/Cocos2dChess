/***************************************************************************************************
 *
 *  @file       AppStateMachine.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief		A generic state machine for an app
 *
 **************************************************************************************************/
 
#include <assert.h>

#include "AppStateMachine.h"
#include "AppDelegate.h"

using namespace render;


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark AppStateMachine
////////////////////////////////////////////////////////////////////////////////////////////////////

AppStateMachine::~AppStateMachine()
{
	if (_currState != nullptr)
	{
		_currState->_exit();
		delete _currState;
	}
}

void
AppStateMachine::init(AppState * inInitialState)
{
    _currState = inInitialState;
    _currState->_setStateMachine(this);
	_currState->_enter();
}

void
AppStateMachine::receiveEvent(AppEvent * inEvent)
{
    logger("AppStateMachine::receiveEvent(%d)", inEvent->getID());
    
    AppState * newState = _currState->_react(inEvent);
    
	if (newState != _currState)
	{
		_currState->_exit();
		delete _currState;

		_currState = newState;
        _currState->_setStateMachine(this);
		_currState->_enter();
	}
}
