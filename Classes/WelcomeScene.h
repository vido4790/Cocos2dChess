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
		static cocos2d::Scene *		createScene(AppStateMachine * inStateMachine);

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
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
	class WelcomeScreenState : public SceneState
	{
	public:
		WelcomeScreenState() = default;

    private:
		virtual AppState *	        _react(AppEvent * inEvent) override;
        virtual cocos2d::Scene *    _createScene() override;
	};

	using ChessAppInitialState = WelcomeScreenState;
}
