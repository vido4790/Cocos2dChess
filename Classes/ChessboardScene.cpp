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

ChessObject::ChessObject()
{
    _sprite = Sprite::create();
}

Rect
ChessObject::getBox() const
{
    return _sprite->getBoundingBox();
}

Point
ChessObject::getMidPoint() const
{
    return Point(_sprite->getBoundingBox().getMidX(), _sprite->getBoundingBox().getMidY());
}

void
ChessObject::_setColor(const Color3B & inColor)
{
    _sprite->setColor(inColor);
}

void
ChessObject::_setImage(const char * inImagePath)
{
    _sprite->setTexture(inImagePath);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScene
////////////////////////////////////////////////////////////////////////////////////////////////////

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
    
    _background = Sprite::create("ChessboardSceneBackground.png");
    _background->setAnchorPoint(Vec2(0.5, 0.5));
    _background->setScale(this->getBoundingBox().getMaxX() / _background->getContentSize().width,
                          this->getBoundingBox().getMaxY() / _background->getContentSize().height);
    _background->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    
    this->addChild(_background);
    
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
