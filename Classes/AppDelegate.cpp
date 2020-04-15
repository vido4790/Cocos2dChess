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

Director *                  
AppDelegate::_getDirector()
{
    return Director::getInstance();
}

GLView *
AppDelegate::_getGLView()
{
    return Director::getInstance()->getOpenGLView();
}

Scene *                  
AppDelegate::_getRunningScene()
{
    return _getDirector()->getRunningScene();
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Public functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void
AppDelegate::setNewScene(Scene * inScene)
{
    auto dir        = _getDirector();

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
    auto dir        = _getDirector();
    auto glView     = _getGLView();

    if (glView != nullptr)
    {
        return false;
    }

    cocos2d::log("Launching app");
    
    glView = GLViewImpl::create("Chess");
    glView->setFrameSize(1280, 960);
    dir->setOpenGLView(glView);

    _stateMachine->init(new ChessAppInitialState());
    
    cocos2d::log("Done launching app");
    
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
