/***************************************************************************************************
 *
 *  @file       AppDelegate.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Cocos2d-x entry point
 *
 **************************************************************************************************/

#pragma once

#include "Chess.h"

#include "cocos2d.h"

namespace render
{
    class AppStateMachine;
}

/**
    @class          AppDelegate

    @brief          Application entry point
 */
class AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    /**
        @brief          Function called when application has launched.

        @discussion     Must be overriden since it's an abstract function.

        @return         bool indicating whether the app was launched correctly.
     */
    virtual bool                applicationDidFinishLaunching() override;

    /**
        @brief          Function called when application is in the background.

        @discussion     Must be overriden since it's an abstract function. Can be used to turn
        off any audio etc.
     */
    virtual void                applicationDidEnterBackground() override;

    /**
        @brief          Function called when application is in the foreground.

        @discussion     Must be overriden since it's an abstract function. Can be used to resume
        any activities stopped when application was set to the background.
     */
    virtual void                applicationWillEnterForeground() override;

    /**
        @brief          Set a new scene, termination the running scene if any.
     */
    void                        setNewScene(cocos2d::Scene * inScene);

    /**
        @brief          Get the application instance.

        @discussion     This is simply a typecast around the base class's getInstance function.

        @return         Singleton instance of this class
     */
    static AppDelegate *        getInstance()
    { dynamic_cast<AppDelegate *>(Application::getInstance()); }

    static cocos2d::Director *  getDirector()
    { return cocos2d::Director::getInstance(); }
    
    static cocos2d::GLView *    getGLView()
    { return getDirector()->getOpenGLView(); }
    
private:
    cocos2d::Scene *            _getRunningScene();

private:
    render::AppStateMachine *   _stateMachine;
};
