/***************************************************************************************************
 *
 *  @file       WelcomeScene.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#pragma once

#include "cocos2d.h"

#include "ChessAppStateMachine.h"

namespace render
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScene
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
	class WelcomeScene : public cocos2d::Layer
	{
	public:
		static cocos2d::Scene *		createScene(AppStateMachine * inStateMachine,
                                                WelcomeScene **   outWelcomeScene);

		virtual bool 				init() override;

		CREATE_FUNC(WelcomeScene);

	private:
		void						_actionsOver();
        
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { _stateMachine = inStateMachine; }
        
        AppStateMachine *           _stateMachine;
	};

    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeSceneState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
	class WelcomeSceneState : public AppState
	{
	public:
		WelcomeSceneState() = default;

    private:
        virtual void                _enter() override;
        virtual void                _exit() override;
        virtual AppState *          _react(AppEvent * inEvent) override;
	};
    
	using ChessAppInitialState = WelcomeSceneState;
}
