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
        kChessboardTileClicked,
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
}
