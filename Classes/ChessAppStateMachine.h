/***************************************************************************************************
 *
 *  @file       ChessAppStateMachine.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief      App-wide states and events
 *
 **************************************************************************************************/

#pragma once

#include "cocos2d.h"

#include "Chess.h"
#include "AppStateMachine.h"

namespace render
{
	enum ChessAppEvents : AppEvent::ID
	{
		kWelcomeScreenAnimationOver,
        kChessboardTileClicked,
        kChessboardClickedInEmptySpace
	};

    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ErrorState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ErrorState
     
     @brief          A state that crashes the application with an error
     */
	class ErrorState : public AppState
	{
	public:
		ErrorState() = default;

		virtual void				_enter() override;
		virtual void				_exit() override;
		virtual AppState *			_react(AppEvent * inEvent) override;
	};
}
