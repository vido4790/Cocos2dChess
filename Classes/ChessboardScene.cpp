/***************************************************************************************************
 *
 *  @file       ChessboardScene.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief		Chess board scene
 *
 **************************************************************************************************/

#include "ChessboardScene.h"


using namespace cocos2d;
using namespace render;


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessObject
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessObject::ChessObject() :
_sprite(Sprite::create())
{
    getSprite()->setAnchorPoint(Vec2(0.5, 0.5));
}

Rect
ChessObject::getRect() const
{
    return getSprite()->getBoundingBox();
}

Point
ChessObject::getMidPoint() const
{
    return Point(getSprite()->getBoundingBox().getMidX(), getSprite()->getBoundingBox().getMidY());
}

void
ChessObject::move(const Point & inPoint)
{
    getSprite()->setPosition(inPoint);
}

void
ChessObject::addAsChildTo(Node * inNode)
{
    inNode->addChild(getSprite());
}

void
ChessObject::addAsChildTo(Node * inNode, int inZOrder)
{
    addAsChildTo(inNode);
    inNode->reorderChild(getSprite(), inZOrder);
}

void
ChessObject::_setColor(const Color3B & inColor)
{
    getSprite()->setColor(inColor);
}

void
ChessObject::_setImage(const char * inImagePath)
{
    getSprite()->setTexture(inImagePath);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessObjectWithImage
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessObjectWithImage::ChessObjectWithImage(const char *  inImage,
                                           const Rect &  inRect)
{
    _init(inImage, inRect);
}

void
ChessObjectWithImage::_init(const char *  inImage,
                            const Rect &  inRect)
{
    float width     = inRect.getMaxX() - inRect.getMinX();
    float height    = inRect.getMaxY() - inRect.getMinY();
    
    getSprite()->setTexture(inImage);
    getSprite()->setScaleX(width / getSprite()->getContentSize().width);
    getSprite()->setScaleY(height / getSprite()->getContentSize().height);
    move(Point(inRect.getMidX(), inRect.getMidY()));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessTile
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessTile::ChessTile(attributes::ChessColor inColor,
                     const Rect &           inRect)
{
    if (inColor == attributes::ChessColor::kBlack)
    {
        getSprite()->setColor(Color3B::BLACK);
    }
    else if (inColor == attributes::ChessColor::kWhite)
    {
        getSprite()->setColor(Color3B::WHITE);
    }
    
    float width     = inRect.getMaxX() - inRect.getMinX();
    float height    = inRect.getMaxY() - inRect.getMinY();
    
    getSprite()->setPosition(inRect.getMidX(), inRect.getMidY());
    getSprite()->setContentSize(Size(width, height));
    getSprite()->setTextureRect(Rect(inRect.getMidX(), inRect.getMidY(), width, height));
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessPieceObject
////////////////////////////////////////////////////////////////////////////////////////////////////

const ChessPieceObject::ImageMap ChessPieceObject::_sBlackImageMap = {
    { attributes::ChessPieceName::kPawn,    "BlackPawn.png" },
    { attributes::ChessPieceName::kKnight,  "BlackKnight.png" },
    { attributes::ChessPieceName::kBishop,  "BlackBishop.png" },
    { attributes::ChessPieceName::kRook,    "BlackRook.png" },
    { attributes::ChessPieceName::kQueen,   "BlackQueen.png" },
    { attributes::ChessPieceName::kKing,    "BlackKing.png" }
};

const ChessPieceObject::ImageMap ChessPieceObject::_sWhiteImageMap = {
    { attributes::ChessPieceName::kPawn,    "WhitePawn.png" },
    { attributes::ChessPieceName::kKnight,  "WhiteKnight.png" },
    { attributes::ChessPieceName::kBishop,  "WhiteBishop.png" },
    { attributes::ChessPieceName::kRook,    "WhiteRook.png" },
    { attributes::ChessPieceName::kQueen,   "WhiteQueen.png" },
    { attributes::ChessPieceName::kKing,    "WhiteKing.png" }
};

ChessPieceObject::ChessPieceObject(attributes::ChessColor     inColor,
                                   attributes::ChessPieceName inPiece,
                                   const ChessTile &          inTile)
{
    _init(inColor, inPiece, inTile.getRect());
}

ChessPieceObject::ChessPieceObject(attributes::ChessColor     inColor,
                                   attributes::ChessPieceName inPiece,
                                   const Rect &               inRect)
{
    _init(inColor, inPiece, inRect);
}

void
ChessPieceObject::_init(attributes::ChessColor     inColor,
                        attributes::ChessPieceName inPiece,
                        const Rect &               inRect)
{
    assert(inColor != attributes::ChessColor::kNone);
    
    const ImageMap & imgMap = ((inColor == attributes::ChessColor::kWhite) ?
                               _sWhiteImageMap : _sBlackImageMap);
    
    auto pair = imgMap.find(inPiece);
    assert(pair != imgMap.end());
    
    ChessObjectWithImage::_init(pair->second, inRect);
}

void
ChessPieceObject::move(const ChessTile * inTile)
{
    ChessObject::move(inTile->getMidPoint());
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Chessboard
////////////////////////////////////////////////////////////////////////////////////////////////////

Chessboard::Chessboard(attributes::ChessColor inStartColor,
                       const Point &          inBottomLeft,
                       float                  inBoxLen)
{
    float currY = inBottomLeft.y;
    
    for (uint8_t rowNum = 0; rowNum < 8; rowNum++)
    {
        float currX = inBottomLeft.x;
        
        auto & row = chessTiles[rowNum];
        
        for (uint8_t colNum = 0; colNum < 8; colNum++)
        {
            attributes::ChessColor currTileColor = attributes::ChessColor::kWhite;
            
            if ((rowNum + colNum) % 2 == 0)
            {
                currTileColor = attributes::ChessColor::kBlack;
            }
            
            Rect rect(currX, currY, inBoxLen, inBoxLen);
            
            row[colNum] = new ChessTile(currTileColor, rect);
            
            currX += inBoxLen;
        }
        
        currY += inBoxLen;
    }
}

void
Chessboard::addAsChildrenTo(cocos2d::Node * inNode,
                            int             inZOrder)
{
    for (auto row : chessTiles)
    {
        for (auto tile : row)
        {
            tile->addAsChildTo(inNode, inZOrder);
        }
    }
}

Chessboard::~Chessboard()
{
    for (uint8_t rowNum = 0; rowNum < 8; rowNum++)
    {
        for (uint8_t colNum = 0; colNum < 8; colNum++)
        {
            delete chessTiles[rowNum][colNum];
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScene
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessboardScene::~ChessboardScene()
{
    delete _background;
    delete _board;
}

Scene *
ChessboardScene::createScene(AppStateMachine * inStateMachine)
{
    auto scene = Scene::create();
    auto layer = ChessboardScene::create();
    
    layer->_setStateMachine(inStateMachine);
    
    scene->addChild(layer);
    
    return scene;
}
    
bool
ChessboardScene::init()
{
    if (!LayerColor::initWithColor(Color4B::BLUE))
    {
        return false;
    }
    
    _background = new ChessObjectWithImage("ChessboardSceneBackground.png",
                                           this->getBoundingBox());
    
    _background->addAsChildTo(this);
    
    float totalWidth    = this->getBoundingBox().getMaxX() - this->getBoundingBox().getMinX();
    float totalHeight   = this->getBoundingBox().getMaxY() - this->getBoundingBox().getMinY();
    
    static constexpr uint8_t kNumBoxesWide = 8 + 4;
    static constexpr uint8_t kNumBoxesHigh = 8 + 3;
    
    float boxLen = fmin(totalWidth/kNumBoxesWide, totalHeight/kNumBoxesHigh);
    
    Point bottomLeft(this->getBoundingBox().getMidX() - (boxLen * 4),
                     this->getBoundingBox().getMidY() - (boxLen * 4));
    
    _board = new Chessboard(attributes::ChessColor::kBlack,
                            bottomLeft, boxLen);

    _board->addAsChildrenTo(this, 0);
    
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScreenCreateState
////////////////////////////////////////////////////////////////////////////////////////////////////

AppState *
ChessboardScreenCreateState::_react(AppEvent * inEvent)
{
    return this;
}

Scene *
ChessboardScreenCreateState::_createScene()
{
    return ChessboardScene::createScene(_getStateMachine());
}
