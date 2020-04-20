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


namespace chessEngine
{
    class ChessEngine;
    struct Position;
    struct Move;
}

namespace render
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessObject
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessObject
     
     @brief          A chess object that contains a srpite
     */
    class ChessObject
	{
	public:
		ChessObject();
		virtual ~ChessObject() = default;

        /**
         @brief          Get the underlying sprite
         */
		cocos2d::Sprite *			getSprite() const { return _sprite; }

        /**
         @brief          Get the rect showing the sprite boundary
         */
		cocos2d::Rect				getRect() const;
        
        /**
         @brief          Get the midpoint of the sprite
         */
		cocos2d::Point 				getMidPoint() const;

        /**
         @brief          Move the sprite to a location
         
         @param            inPoint              point to which it has to be moved
         */
        void                        move(const cocos2d::Point & inPoint);
        
        /**
         @brief          Add as a child to a node
         
         @param            inNode               the parent node
         */
        void                        addAsChildTo(cocos2d::Node * inNode);
        
        /**
         @brief          Remove sprite as child
         */
        void                        removeAsChild();
        
        /**
         @brief          Add as child with a Z Oder
         
         @param            inEvent              the parent node
         @param            inZOrder             the z order
         */
        void                        addAsChildTo(cocos2d::Node * inNode, int inZOrder);
        
	protected:
        /**
         @brief          Set a sprite color
         
         @param            inColor              color
         */
        void 						_setColor(const cocos2d::Color3B & inColor);
        
        /**
         @brief          Set a sprite image
         
         @param            inImagePath          image path
         */
		void						_setImage(const char * inImagePath);

	protected:
		cocos2d::Sprite *			_sprite;
	};


    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessObjectWithColor
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessObjectWithColor
     
     @brief          A chess object that has color
     */
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
    
    /**
     @class          ChessObjectWithImage
     
     @brief          A chess object that has an image as texture
     */
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
    
    /**
     @class          ChessPieceObject
     
     @brief          A chess piece
     */
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
        
        /**
         @brief          Get the name of the chess piece
         */
        attributes::ChessPieceName  getName() const { return _name; }
        
        /**
         @brief          Get the color of the piece
         */
        attributes::ChessColor      getColor() const { return _color; }
        
        /**
         @brief          Move the piece onto a tile
         */
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
    
    /**
     @class          ChessTile
     
     @brief          A chess tile that may or may not contain a piece
     */
    class ChessTile : public ChessObjectWithColor
	{
	public:
		ChessTile(attributes::ChessColor inColor,
                  const cocos2d::Rect &  inRect);
        virtual ~ChessTile();
        
        /**
         @brief          Get the piece on the tile
         */
        ChessPieceObject *          getPiece() const { return _piece; }
        
        /**
         @brief          Check if the tile has a piece
         */
        bool                        hasPiece() const { return getPiece() != nullptr; }
        
        /**
         @brief          Move the piece from this tile to another
         */
        void                        movePiece(ChessPieceObject * inNewPiece);
        
        /**
         @brief          Remove a piece from this tile
         
         @return         The current piece
         */
        ChessPieceObject *          removePiece();
        
        /**
         @brief          Replace an existing piece from this tile
         
         @return         The removed piece
         */
        ChessPieceObject *          replacePiece(ChessPieceObject * inNewPiece);
        
        /**
         @brief          Create a new chess piece on a tile
         
         @return         The created piece
         */
        ChessPieceObject *          createChessPieceOnTile(attributes::ChessColor     inColor,
                                                           attributes::ChessPieceName inPiece);
        
        /**
         @brief          Highlight a tile
         */
        void                        highlight();
        
        /**
         @brief          Remove tile highlight
         */
        void                        removeHighlight();
        
        /**
         @brief          Check if a tile is highlighted
         */
        bool                        isHighlighted();
        
        static const cocos2d::Color3B kWhiteTileColor;
        static const cocos2d::Color3B kBlackTileColor;
        static const cocos2d::Color3B kWhiteTileHighlightedColor;
        static const cocos2d::Color3B kBlackTileHighlightedColor;
        static const cocos2d::Color3B kBackgroundColor;
        
    private:
        ChessPieceObject *          _piece;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark Chessboard
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          Chessboard
     
     @brief          A chess board that has all the tiles
     */
    class Chessboard
	{
	public:
        using ChessTileGrid = std::array<std::array<ChessTile *, 8>, 8>;
        using ChessPieceObjectVector = std::vector<ChessPieceObject *>;
        
        Chessboard(attributes::ChessColor inPlayerColor,
                   const cocos2d::Point & inBottomLeft,
                   float                  inBoxLen);
        virtual ~Chessboard();
        
        /**
         @brief         Add all the tiles and pieces as children to node
         
         @param     inNode      the parent node
         */
        void                        addAsChildrenTo(cocos2d::Node * inNode);
        
        /**
         @brief          Get the point's board location in terms of row and column
         
         @param     inPoint     the point to be checked
         @param     outRow      the row where the point is
         @param     outCol      the column where the point is
         */
        bool                        getPointBoardLocation(const cocos2d::Point & inPoint,
                                                          uint8_t * outRow, uint8_t * outCol) const;
        
        /**
         @brief          Move a piece
         
         @discussion     The function expects the destination to be empty. If the destination is
         outside the board, i.e. inDest.isRemoved() is true, the piece will be deleted.
         @todo           Move the piece onto the side of the board if inDest is outside instead
         of deleting it.
         
         @param     inSrc       the source square where the piece is
         @param     inDst       the destination of the move
         */
        void                        movePiece(const chessEngine::Position & inSrc,
                                              const chessEngine::Position & inDst);
        
		ChessTileGrid				chessTiles;
        ChessPieceObjectVector *    chessPieces;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardScene
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessboardScene
     
     @brief          The actual chessboard scene
     */
    class ChessboardScene : public cocos2d::LayerColor
	{
	public:
        virtual ~ChessboardScene();
        
	    static cocos2d::Scene * 	createScene(AppStateMachine *  inStateMachine,
                                                ChessboardScene ** outChessBoardScene);
	    
        virtual bool 				init();
	    
        CREATE_FUNC(ChessboardScene);
        
	private:
        void                        _setStateMachine(AppStateMachine * inStateMachine)
        { stateMachine = inStateMachine; }
        
        void                        _touchReact(cocos2d::Point inTouchLocation);
        
    public:
        AppStateMachine *           stateMachine;
        
        Chessboard *                board;
        ChessObjectWithColor *      background;
        
        chessEngine::ChessEngine *  engine;
	};
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardSceneStaticState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessboardSceneStaticState
     
     @brief          Steady state with no action going on
     */
    class ChessboardSceneStaticState : public AppState
    {
    public:
        ChessboardSceneStaticState(ChessboardScene * inScene);
        
    private:
        virtual void                _enter() override;
        virtual void                _exit() override;
        virtual AppState *          _react(AppEvent * inEvent) override;
        
        ChessboardScene *           _scene;
    };
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardTouchEvent
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessboardTouchEvent
     
     @brief          An event where a tile has been clicked
     */
    class ChessboardTouchEvent : public AppEvent
    {
    public:
        ChessboardTouchEvent(uint8_t inRowIndex, uint8_t inColIndex);
        
        const uint8_t               rowIndex;
        const uint8_t               colIndex;
    };

    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    #pragma mark -
    #pragma mark ChessboardScenePieceClickedState
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     @class          ChessboardScenePieceClickedState
     
     @brief          State where a chess piece has been clicked
     */
    class ChessboardScenePieceClickedState : public AppState
    {
    public:
        ChessboardScenePieceClickedState(ChessboardScene * inScene,
                                         uint8_t inRowIndex, uint8_t inColIndex);
        
    private:
        virtual void                _enter() override;
        virtual void                _exit() override;
        virtual AppState *          _react(AppEvent * inEvent) override;
        
        void                        _movePiece(const chessEngine::Move & inMove);
        
        ChessboardScene *           _scene;
        
        const uint8_t               _rowIndex;
        const uint8_t               _colIndex;
    };
}
