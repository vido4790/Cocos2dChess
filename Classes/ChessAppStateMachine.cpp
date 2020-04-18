/***************************************************************************************************
 *
 *  @file       ChessAppStateMachine.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#include <assert.h>

#include "ChessAppStateMachine.h"
#include "AppDelegate.h"


using namespace render;
using namespace cocos2d;


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ErrorState
////////////////////////////////////////////////////////////////////////////////////////////////////

void
ErrorState::_enter()
{
	assert(true);
}

void
ErrorState::_exit()
{
	assert(true);
}

AppState *			
ErrorState::_react(AppEvent * inEvent)
{
	assert(true);
	return nullptr;
}
