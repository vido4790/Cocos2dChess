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
	class ChessObject
	{
	public:
		ChessObject();
		virtual ~ChessObject();

		cocos2d::Sprite *			getSprite() { return _sprite; }

		cocos2d::Rect				getBox() const;
		cocos2d::Point 				getMidPoint() const;

	protected:
		void 						_setColor(const Color3B & inColor);
		void						_setImage(const char * imagePath);

	protected:
		cocos2d::Sprite *			_sprite;
	};

	class ChessTile : public ChessObject
	{
	public:
		ChessObject(ChessColor inColor, const cocos2d::Point & inPosition);
	};

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

	class Chessboard
	{
		using ChessTileGrid = cocos2d::vector< cocos2d::vector<ChessTile *> >;

	public:
		Chessboard();

	private:
		ChessTileGrid				_chessTiles;
	};

    class ChessboardScene : public cocos2d::LayerWithColor
	{
	public:
	    static cocos2d::Scene * 	createScene(AppStateMachine * inStateMachine);
	    virtual bool 				init();  
	    CREATE_FUNC(GraphicsScene);
	
	private:
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { _stateMachine = inStateMachine; }
        
        AppStateMachine *           _stateMachine;
        
		Chessboard *				_board;
	};

	class ChessboardScreenCreateState : public SceneState
	{
	public:
		ChessboardScreenCreateState() = default;

		virtual AppState *	        _react(AppEvent * inEvent) override;
        
    private:
        virtual cocos2d::Scene *    _createScene() override;
	};
}
