/***************************************************************************************************
 *
 *  @file       AppStateMachine.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief		A generic state machine for an app
 *
 **************************************************************************************************/

#pragma once

#include "Chess.h"

namespace render
{
	class AppState;
	class AppEvent;


	////////////////////////////////////////////////////////////////////////////////////////////////
	#pragma mark -
	#pragma mark AppData
	////////////////////////////////////////////////////////////////////////////////////////////////

	/**
        @class          AppData

        @brief          Application data that is to be passed to the state machine.

        @discussion     Application data such as object pointers etc that needs to be preserved 
        across states.
     */	
	struct AppData
	{
		
	};

	////////////////////////////////////////////////////////////////////////////////////////////////
	#pragma mark -
	#pragma mark AppStateMachine
	////////////////////////////////////////////////////////////////////////////////////////////////

	/**
        @class          AppStateMachine

        @brief          Application state machine

        @discussion     Application graphics state machine. Should contain as little of the game 
        logic as possible.
     */
	class AppStateMachine final
	{
	public:
		AppStateMachine() = default;
		~AppStateMachine();

		/**
			@brief			Initialize the state machine

			@discussion		Should be called by the deriving class in the constructor as the very
			last statement.
         
            @param          inInitialState  initial state for the state machine
		 */
		void						init(AppState * inInitialState);

		/**
			@brief			Receive an event

			@discussion		Performs a state change upon recieving an event. Calls
			state functions as appropriate.

			@param			inEvent			received event
		 */
		void						receiveEvent(AppEvent * inEvent);

		/**
			@brief			Receive an event

			@discussion		Performs a state change upon recieving an event. Calls
			state functions as appropriate.

			@return 		the AppData struct pointer
		 */
		AppData *					getAppData() { return _appData; }

	private:
		AppState *					_currState;
		AppData *					_appData;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////
	#pragma mark -
	#pragma mark AppState
	////////////////////////////////////////////////////////////////////////////////////////////////

	/**
        @class          AppState

        @brief          Application state.

        @discussion     The class should have a trivial constructor and distructor.
     */
	class AppState
	{
        friend AppStateMachine;
        
	public:
		AppState() = default;
		virtual ~AppState() = default;

    private:
        /**
            @brief          Enter into a new state.
         
            @discussion     enter acts as the start of the state lifecycle.
         */
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { _stateMachine = inStateMachine; }
        
    protected:
		/**
	        @brief          Enter into a new state.

	        @discussion     enter acts as the start of the state lifecycle.
		 */
		virtual void				_enter() = 0;

		/**
	        @brief          Exit from a state.

	        @discussion     exit acts as the end of the state lifecycle.
		 */
		virtual void				_exit() = 0;

		/**
	        @brief          React to a state change.

	        @discussion     Receive an event, and react to it as necessary.

	        @param			inEvent			received event

	        @return 		Object of the next state. Can be this if no state change.
		 */
		virtual AppState *			_react(AppEvent * inEvent) = 0;
        
		AppStateMachine *			_getStateMachine() { return _stateMachine; }

	private:
		AppStateMachine *			_stateMachine;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////
	#pragma mark -
	#pragma mark AppEvent
	////////////////////////////////////////////////////////////////////////////////////////////////

	/**
        @class          AppEvent

        @brief          Application event.

        @discussion		The type of the event should be dinstinguished based on the ID.
     */
	class AppEvent
	{
	public:
		using ID = uint32_t;

	public:
		AppEvent(ID inID) : _ID(inID) { }
		virtual ~AppEvent() = default;

		/**
	        @brief          Get the event ID.

	        @return 		the event ID.
		 */
		ID 							getID() { return _ID; }

	private:
		ID 							_ID;
	};
}
