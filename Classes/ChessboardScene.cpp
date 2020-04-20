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
#include "ChessEngine.h"


using namespace cocos2d;
using namespace render;
using namespace chessEngine;


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
#pragma mark ChessObjectWithColor
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessObjectWithColor::ChessObjectWithColor(const cocos2d::Color3B & inColor,
                                           const cocos2d::Rect &    inRect)
{
    _init(inColor, inRect);
}

void
ChessObjectWithColor::_init(const cocos2d::Color3B & inColor,
                        const cocos2d::Rect &    inRect)
{
    float width     = inRect.getMaxX() - inRect.getMinX();
    float height    = inRect.getMaxY() - inRect.getMinY();
    
    getSprite()->setPosition(inRect.getMidX(), inRect.getMidY());
    getSprite()->setContentSize(Size(width, height));
    getSprite()->setTextureRect(Rect(inRect.getMidX(), inRect.getMidY(), width, height));
    getSprite()->setColor(inColor);
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
                                   const ChessTile *          inTile)
{
    _init(inColor, inPiece, inTile->getRect());
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
    _color = inColor;
    _name = inPiece;
    
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
#pragma mark ChessTile
////////////////////////////////////////////////////////////////////////////////////////////////////

const cocos2d::Color3B ChessTile::kWhiteTileColor  = Color3B(255, 206, 158);
const cocos2d::Color3B ChessTile::kBlackTileColor  = Color3B(209, 139, 71);

const cocos2d::Color3B ChessTile::kWhiteTileHighlightedColor = Color3B(246, 247, 130);
const cocos2d::Color3B ChessTile::kBlackTileHighlightedColor = Color3B(192, 212, 79);

const cocos2d::Color3B ChessTile::kBackgroundColor = Color3B(49, 46, 43);

ChessTile::ChessTile(attributes::ChessColor inColor,
                     const Rect &           inRect) :
ChessObjectWithColor(((inColor == attributes::ChessColor::kWhite) ?
                      kWhiteTileColor : kBlackTileColor), inRect),
_piece(nullptr)
{
    
}

ChessTile::~ChessTile()
{
    if (_piece != nullptr)
    {
        delete _piece;
    }
}

void
ChessTile::movePiece(ChessPieceObject * inNewPiece)
{
    assert(_piece == nullptr);
    _piece = inNewPiece;
    _piece->move(this);
}

ChessPieceObject *
ChessTile::removePiece()
{
    assert(_piece != nullptr);
    auto tmp = _piece;
    _piece = nullptr;
    return tmp;
}

ChessPieceObject *
ChessTile::replacePiece(ChessPieceObject * inNewPiece)
{
    auto tmp = removePiece();
    movePiece(inNewPiece);
    return tmp;
}

ChessPieceObject *
ChessTile::createChessPieceOnTile(attributes::ChessColor     inColor,
                                  attributes::ChessPieceName inPiece)
{
    assert(_piece == nullptr);
    movePiece(new ChessPieceObject(inColor, inPiece, this));
    return _piece;
}

void
ChessTile::highlight()
{
    assert((getSprite()->getColor() == kWhiteTileColor) ||
           (getSprite()->getColor() == kBlackTileColor));
    
    auto & color = ((getSprite()->getColor() == kWhiteTileColor) ?
                    kWhiteTileHighlightedColor : kBlackTileHighlightedColor);
    
    getSprite()->setColor(color);
}

void
ChessTile::removeHighlight()
{
    assert(isHighlighted());
    
    auto & color = ((getSprite()->getColor() == kWhiteTileHighlightedColor) ?
                    kWhiteTileColor : kBlackTileColor);
    
    getSprite()->setColor(color);
}

bool
ChessTile::isHighlighted()
{
    return ((getSprite()->getColor() == kWhiteTileHighlightedColor) ||
            (getSprite()->getColor() == kBlackTileHighlightedColor));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Chessboard
////////////////////////////////////////////////////////////////////////////////////////////////////

Chessboard::Chessboard(attributes::ChessColor inPlayerColor,
                       const Point &          inBottomLeft,
                       float                  inBoxLen)
{
    assert(inPlayerColor != attributes::ChessColor::kNone);
    
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
    
    static constexpr uint8_t kPawnRowIndex = 1;
    static constexpr uint8_t kMainRowIndex = 0;
    
    static constexpr uint8_t kKnightCols[2] = { 1, 6 };
    static constexpr uint8_t kBishopCols[2] = { 2, 5 };
    static constexpr uint8_t kRookCols[2] = { 0, 7 };
    
    uint8_t whiteRows[2] = { 0, 1 };
    uint8_t blackRows[2] = { 7, 6 };
    
    uint8_t kingCol      = 4;
    uint8_t queenCol     = 3;
    
    if (inPlayerColor == attributes::ChessColor::kBlack)
    {
        blackRows[kMainRowIndex] = 0;
        blackRows[kPawnRowIndex] = 1;
        
        whiteRows[kMainRowIndex] = 7;
        whiteRows[kPawnRowIndex] = 6;
        
        kingCol      = 3;
        queenCol     = 4;
    }
    
    for (auto i = 0; i < 8; i++)
    {
        auto whiteTile = chessTiles[whiteRows[kPawnRowIndex]][i];
        auto blackTile = chessTiles[blackRows[kPawnRowIndex]][i];
        
        whiteTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                          attributes::ChessPieceName::kPawn);
        
        blackTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                          attributes::ChessPieceName::kPawn);
    }
    
    for (auto i = 0; i < 2; i++)
    {
        auto whiteKnightTile = chessTiles[whiteRows[kMainRowIndex]][kKnightCols[i]];
        auto blackKnightTile = chessTiles[blackRows[kMainRowIndex]][kKnightCols[i]];
        
        auto whiteBishopTile = chessTiles[whiteRows[kMainRowIndex]][kBishopCols[i]];
        auto blackBishopTile = chessTiles[blackRows[kMainRowIndex]][kBishopCols[i]];
        
        auto whiteRookTile = chessTiles[whiteRows[kMainRowIndex]][kRookCols[i]];
        auto blackRookTile = chessTiles[blackRows[kMainRowIndex]][kRookCols[i]];
        
        whiteKnightTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                                attributes::ChessPieceName::kKnight);
        blackKnightTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                                attributes::ChessPieceName::kKnight);
        
        whiteBishopTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                                attributes::ChessPieceName::kBishop);
        blackBishopTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                                attributes::ChessPieceName::kBishop);
        
        whiteRookTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                              attributes::ChessPieceName::kRook);
        blackRookTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                              attributes::ChessPieceName::kRook);
    }
    
    auto whiteKingTile = chessTiles[whiteRows[kMainRowIndex]][kingCol];
    auto blackKingTile = chessTiles[blackRows[kMainRowIndex]][kingCol];
    
    auto whiteQueenTile = chessTiles[whiteRows[kMainRowIndex]][queenCol];
    auto blackQueenTile = chessTiles[blackRows[kMainRowIndex]][queenCol];
    
    whiteKingTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                          attributes::ChessPieceName::kKing);
    blackKingTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                          attributes::ChessPieceName::kKing);
    
    whiteQueenTile->createChessPieceOnTile(attributes::ChessColor::kWhite,
                                           attributes::ChessPieceName::kQueen);
    blackQueenTile->createChessPieceOnTile(attributes::ChessColor::kBlack,
                                           attributes::ChessPieceName::kQueen);
}

void
Chessboard::addAsChildrenTo(cocos2d::Node * inNode)
{
    for (auto row : chessTiles)
    {
        for (auto tile : row)
        {
            tile->addAsChildTo(inNode, 0);
            
            if (tile->getPiece() != nullptr)
            {
                tile->getPiece()->addAsChildTo(inNode, 1);
            }
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

bool
Chessboard::getPointBoardLocation(const cocos2d::Point & inPoint,
                                  uint8_t * outRow, uint8_t * outCol) const
{
    auto left   = chessTiles[0][0]->getRect().getMinX();
    auto bottom = chessTiles[0][0]->getRect().getMinY();
    auto right  = chessTiles[7][7]->getRect().getMaxX();
    auto top    = chessTiles[7][7]->getRect().getMaxY();
    
    auto len    = (top - bottom) / 8;
    
    Rect boardRect(left, bottom, right - left, top - bottom);
    
    if (!boardRect.containsPoint(inPoint))
    {
        return false;
    }
    
    *outRow = static_cast<uint8_t>((inPoint.y - bottom) / len);
    *outCol = static_cast<uint8_t>((inPoint.x - left) / len);
    
    assert(chessTiles[*outRow][*outCol]->getRect().containsPoint(inPoint));
    
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScene
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessboardScene::~ChessboardScene()
{
    delete background;
    delete board;
    delete engine;
}

Scene *
ChessboardScene::createScene(AppStateMachine * inStateMachine,
                             ChessboardScene **  outChessBoardScene)
{
    auto scene = Scene::create();
    auto layer = ChessboardScene::create();
    *outChessBoardScene = layer;
    
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
    
    engine     = new ChessEngine();
    background = new ChessObjectWithColor(ChessTile::kBackgroundColor,
                                           this->getBoundingBox());
    
    background->addAsChildTo(this);
    
    float totalWidth    = this->getBoundingBox().getMaxX() - this->getBoundingBox().getMinX();
    float totalHeight   = this->getBoundingBox().getMaxY() - this->getBoundingBox().getMinY();
    
    static constexpr uint8_t kNumBoxesWide = 8 + 4;
    static constexpr uint8_t kNumBoxesHigh = 8 + 3;
    
    float boxLen = fmin(totalWidth/kNumBoxesWide, totalHeight/kNumBoxesHigh);
    
    Point bottomLeft(this->getBoundingBox().getMidX() - (boxLen * 4),
                     this->getBoundingBox().getMidY() - (boxLen * 4));
    
    board = new Chessboard(attributes::ChessColor::kBlack,
                            bottomLeft, boxLen);
    
    board->addAsChildrenTo(this);
    
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->onTouchBegan = [] (Touch * touch, Event * event) -> bool {
        auto scene = dynamic_cast<ChessboardScene *>(event->getCurrentTarget());
        scene->_touchReact(touch->getLocation());
        return true;
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
    return true;
}

void
ChessboardScene::_touchReact(cocos2d::Point inTouchLocation)
{
    uint8_t row, col;
    
    if (board->getPointBoardLocation(inTouchLocation, &row, &col))
    {
        auto event = new ChessboardTouchEvent(row, col);
        stateMachine->receiveEvent(event);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardSceneStaticState
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessboardSceneStaticState::ChessboardSceneStaticState(ChessboardScene * inScene) :
_scene(inScene)
{
    
}

void
ChessboardSceneStaticState::_enter()
{
    
}

void
ChessboardSceneStaticState::_exit()
{
    
}

AppState *
ChessboardSceneStaticState::_react(AppEvent * inEvent)
{
    switch (inEvent->getID())
    {
        case ChessAppEvents::kChessboardTileClicked:
        {
            auto clickEvent = dynamic_cast<ChessboardTouchEvent *>(inEvent);
            auto tile       = _scene->board->chessTiles[clickEvent->rowIndex][clickEvent->colIndex];
            
            cocos2d::log("Touch on %d, %d\n\n", clickEvent->rowIndex, clickEvent->colIndex);
            
            if (tile->hasPiece())
            {
                return new ChessboardScenePieceClickedState(_scene, clickEvent->rowIndex,
                                                            clickEvent->colIndex);
            }
            
            return this;
        }
        default:
        {
            return new ErrorState();
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardTouchEvent
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessboardTouchEvent::ChessboardTouchEvent(uint8_t inRowIndex, uint8_t inColIndex) :
AppEvent(ChessAppEvents::kChessboardTileClicked), rowIndex(inRowIndex), colIndex(inColIndex)
{
    
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScenePieceClickedState
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessboardScenePieceClickedState::ChessboardScenePieceClickedState(ChessboardScene * inScene,
                                                                   uint8_t inRowIndex,
                                                                   uint8_t inColIndex) :
_scene(inScene), _rowIndex(inRowIndex), _colIndex(inColIndex)
{
    
}

void
ChessboardScenePieceClickedState::_enter()
{
    auto tile       = _scene->board->chessTiles[_rowIndex][_colIndex];
    assert(tile->hasPiece());
    
    tile->highlight();
}

void
ChessboardScenePieceClickedState::_exit()
{
    auto tile       = _scene->board->chessTiles[_rowIndex][_colIndex];
    
    tile->removeHighlight();
}

AppState *
ChessboardScenePieceClickedState::_react(AppEvent * inEvent)
{
    switch (inEvent->getID())
    {
        case ChessAppEvents::kChessboardTileClicked:
        {
            auto clickEvent = dynamic_cast<ChessboardTouchEvent *>(inEvent);
            auto newTile    = _scene->board->chessTiles[clickEvent->rowIndex][clickEvent->colIndex];
            auto tile       = _scene->board->chessTiles[_rowIndex][_colIndex];
            
            cocos2d::log("Touch on %d, %d\n\n", clickEvent->rowIndex, clickEvent->colIndex);
            
            if ((newTile->hasPiece()) &&
                (newTile->getPiece()->getColor() == tile->getPiece()->getColor()))
            {
                return new ChessboardScenePieceClickedState(_scene, clickEvent->rowIndex,
                                                            clickEvent->colIndex);
            }
            
            //if (
            
            return this;
        }
        default:
        {
            return new ErrorState();
        }
    }
}
