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


cocos2d::Scene *
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
    if (! LayerColor::initWithColor(Color4B::BLUE))
    {
        return false;
    }
    
    return true;
}




AppState *
ChessboardScreenCreateState::_react(AppEvent * inEvent)
{
    return this;
}
    
cocos2d::Scene *
ChessboardScreenCreateState::_createScene()
{
    return ChessboardScene::createScene(_getStateMachine());
}
