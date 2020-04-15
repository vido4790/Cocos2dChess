/***************************************************************************************************
 *
 *  @file       ChessAppStateMachine.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#pragma once

#include "cocos2d.h"

#include "AppStateMachine.h"

namespace render
{
	enum ChessAppEvents : AppEvent::ID
	{
		kWelcomeScreenAnimationOver,
	};

    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ErrorState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
	class ErrorState : public AppState
	{
	public:
		ErrorState() = default;

		virtual void				_enter() override;
		virtual void				_exit() override;
		virtual AppState *			_react(AppEvent * inEvent) override;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark SceneState
    ////////////////////////////////////////////////////////////////////////////////////////////////

	class SceneState : public AppState
	{
	protected:
		cocos2d::Scene *			_scene;

	protected:
		SceneState() = default;
        
        virtual cocos2d::Scene *    _createScene() = 0;

	public:
		virtual void				_enter() override;
		virtual void				_exit() override;
	};
}
