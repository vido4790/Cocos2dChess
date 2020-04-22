/***************************************************************************************************
 *
 *  @file       AppDelegate.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Cocos2d-x entry point
 *
 **************************************************************************************************/

// Standard includes
#include <assert.h>

// Cocos includes


// App includes
#include "AppDelegate.h"
#include "WelcomeScene.h"


using namespace cocos2d;
using namespace render;


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Constructors
////////////////////////////////////////////////////////////////////////////////////////////////////

AppDelegate::AppDelegate()
{
    _stateMachine   = new AppStateMachine();
}

AppDelegate::~AppDelegate()
{
    delete _stateMachine;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Setters/Getters
////////////////////////////////////////////////////////////////////////////////////////////////////

Scene *                  
AppDelegate::_getRunningScene()
{
    return getDirector()->getRunningScene();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Public functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void
AppDelegate::setNewScene(Scene * inScene)
{
    auto dir        = getDirector();

    if (_getRunningScene() == nullptr)
    {
        dir->runWithScene(inScene);
    }
    else
    {
        dir->replaceScene(inScene);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Overloaded functions
////////////////////////////////////////////////////////////////////////////////////////////////////

bool
AppDelegate::applicationDidFinishLaunching()
{
    auto dir        = getDirector();
    auto glView     = getGLView();

    if (glView != nullptr)
    {
        return false;
    }

    logger("Launching app");
    
    glView = GLViewImpl::createWithRect("Chess", Rect(0, 0, 1280, 720));
    dir->setOpenGLView(glView);

    _stateMachine->init(new ChessAppInitialState());
    
    logger("Done launching app");
    
    return true;
}

void
AppDelegate::applicationDidEnterBackground()
{
    
}

void
AppDelegate::applicationWillEnterForeground()
{
    
}
