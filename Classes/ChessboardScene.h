/***************************************************************************************************
 *
 *  @file       ChessboardScene.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief		Chess board scene
 *
 **************************************************************************************************/

#pragma once

#include <unordered_map>

#include "cocos2d.h"

#include "Chess.h"
#include "ChessAppStateMachine.h"

namespace render
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessObject
	{
	public:
		ChessObject();
		virtual ~ChessObject() = default;

		cocos2d::Sprite *			getSprite() { return _sprite; }

		cocos2d::Rect				getBox() const;
		cocos2d::Point 				getMidPoint() const;

	protected:
        void 						_setColor(const cocos2d::Color3B & inColor);
		void						_setImage(const char * inImagePath);

	protected:
		cocos2d::Sprite *			_sprite;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessTile : public ChessObject
	{
	public:
		ChessTile(attributes::ChessColor inColor, const cocos2d::Point & inPosition);
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessPieceObject : public ChessObject
	{
		using ImageMap = std::unordered_map<attributes::ChessPieceName, const char *>;

	public:
		ChessPieceObject(attributes::ChessPieceName inPiece);

		void 						move(const cocos2d::Point & inPoint);

	private:
		attributes::ChessPieceName 	_name;

		static ImageMap				_sImageMap;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class Chessboard
	{
		using ChessTileGrid = cocos2d::Vector< cocos2d::Vector<ChessTile *> >;

	public:
		Chessboard();

	private:
		ChessTileGrid				_chessTiles;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessboardScene : public cocos2d::LayerColor
	{
	public:
	    static cocos2d::Scene * 	createScene(AppStateMachine * inStateMachine);
	    
        virtual bool 				init();
	    
        CREATE_FUNC(ChessboardScene);
	
	private:
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { _stateMachine = inStateMachine; }
        
        AppStateMachine *           _stateMachine;
        
		Chessboard *				_board;
        
        cocos2d::Sprite *           _background;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark WelcomeScreenState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessboardScreenCreateState : public SceneState
	{
	public:
		ChessboardScreenCreateState() = default;

    private:
        virtual AppState *          _react(AppEvent * inEvent) override;
        virtual cocos2d::Scene *    _createScene() override;
	};
}
