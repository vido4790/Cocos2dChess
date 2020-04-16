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

#include <array>
#include <unordered_map>

#include "cocos2d.h"

#include "Chess.h"
#include "ChessAppStateMachine.h"

namespace render
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessObject
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessObject
	{
	public:
		ChessObject();
		virtual ~ChessObject() = default;

		cocos2d::Sprite *			getSprite() const { return _sprite; }

		cocos2d::Rect				getRect() const;
		cocos2d::Point 				getMidPoint() const;

        void                        move(const cocos2d::Point & inPoint);
        void                        addAsChildTo(cocos2d::Node * inNode);
        void                        addAsChildTo(cocos2d::Node * inNode, int inZOrder);
        
	protected:
        void 						_setColor(const cocos2d::Color3B & inColor);
		void						_setImage(const char * inImagePath);

	protected:
		cocos2d::Sprite *			_sprite;
	};


    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessObjectWithColor
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessObjectWithColor : public ChessObject
    {
    public:
        ChessObjectWithColor() = default;
        ChessObjectWithColor(const cocos2d::Color3B & inColor,
                             const cocos2d::Rect &    inRect);
        
    protected:
        void                        _init(const cocos2d::Color3B & inColor,
                                          const cocos2d::Rect &    inRect);
    };
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessObjectWithImage
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessObjectWithImage : public ChessObject
    {
    public:
        ChessObjectWithImage() = default;
        ChessObjectWithImage(const char *           inImage,
                             const cocos2d::Rect &  inRect);
        
    protected:
        void                        _init(const char *           inImage,
                                          const cocos2d::Rect &  inRect);
    };
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessPieceObject
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessTile;
    
    class ChessPieceObject : public ChessObjectWithImage
    {
        using ImageMap = std::unordered_map<attributes::ChessPieceName, const char *,
        attributes::EnumClassHash>;
        
    public:
        ChessPieceObject(attributes::ChessColor     inColor,
                         attributes::ChessPieceName inPiece,
                         const ChessTile *          inTile);
        
        ChessPieceObject(attributes::ChessColor     inColor,
                         attributes::ChessPieceName inPiece,
                         const cocos2d::Rect &      inRect);
        
        attributes::ChessPieceName  getName() const { return _name; }
        attributes::ChessColor      getColor() const { return _color; }
        
        void                        move(const ChessTile * inTile);
        
    private:
        void                        _init(attributes::ChessColor     inColor,
                                          attributes::ChessPieceName inPiece,
                                          const cocos2d::Rect &      inRect);
        
        attributes::ChessPieceName  _name;
        attributes::ChessColor      _color;
        
        const static ImageMap       _sBlackImageMap;
        const static ImageMap       _sWhiteImageMap;
    };
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessTile
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessTile : public ChessObjectWithColor
	{
	public:
		ChessTile(attributes::ChessColor inColor,
                  const cocos2d::Rect &  inRect);
        virtual ~ChessTile();
        
        ChessPieceObject *          getPiece() const { return _piece; }
        
        void                        movePiece(ChessPieceObject * inNewPiece);
        ChessPieceObject *          removePiece();
        ChessPieceObject *          replacePiece(ChessPieceObject * inNewPiece);
        
        ChessPieceObject *          createChessPieceOnTile(attributes::ChessColor     inColor,
                                                           attributes::ChessPieceName inPiece);
        
        static const cocos2d::Color3B kWhiteTileColor;
        static const cocos2d::Color3B kBlackTileColor;
        static const cocos2d::Color3B kBackgroundColor;
        
    private:
        ChessPieceObject *          _piece;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark Chessboard
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class Chessboard
	{
	public:
        using ChessTileGrid = std::array<std::array<ChessTile *, 8>, 8>;
        using ChessPieceObjectVector = std::vector<ChessPieceObject *>;
        
        Chessboard(attributes::ChessColor inPlayerColor,
                   const cocos2d::Point & inBottomLeft,
                   float                  inBoxLen);
        virtual ~Chessboard();
        
        void                        addAsChildrenTo(cocos2d::Node * inNode);
        
		ChessTileGrid				chessTiles;
        ChessPieceObjectVector *    chessPieces;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardScene
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ChessboardScene : public cocos2d::LayerColor
	{
	public:
        virtual ~ChessboardScene();
        
	    static cocos2d::Scene * 	createScene(AppStateMachine * inStateMachine);
	    
        virtual bool 				init();
	    
        CREATE_FUNC(ChessboardScene);
	
	private:
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { _stateMachine = inStateMachine; }
        
        AppStateMachine *           _stateMachine;
        
		Chessboard *				_board;
        ChessObjectWithColor *      _background;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardScreenCreateState
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
