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


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark SceneState
////////////////////////////////////////////////////////////////////////////////////////////////////

void
SceneState::_enter()
{
    cocos2d::log("SceneState::_enter()");
    _scene = _createScene();
	AppDelegate::getInstance()->setNewScene(_scene);
    cocos2d::log("SceneState::_enter() new scene careated");
}

void
SceneState::_exit()
{
    cocos2d::log("SceneState::_exit()");
}
