/***************************************************************************************************
 *
 *  @file       WelcomeScene.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Welcome scene
 *
 **************************************************************************************************/

#include "WelcomeScene.h"
#include "ChessboardScene.h"
#include "AppDelegate.h"


using namespace cocos2d;
using namespace render;


static const char * kLogoImage = "logo.png";


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark WelcomeScene
////////////////////////////////////////////////////////////////////////////////////////////////////

Scene *		
WelcomeScene::createScene(AppStateMachine * inStateMachine, WelcomeScene ** outWelcomeScene)
{
	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
    *outWelcomeScene = layer;
    
    layer->_setStateMachine(inStateMachine);

	scene->addChild(layer);

	return scene;
}

bool
WelcomeScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
    
	auto sprite = cocos2d::Sprite::create(kLogoImage);
	sprite->setPosition(getBoundingBox().getMidX(), getBoundingBox().getMidY());
	sprite->setOpacity(0);
	addChild(sprite, 0);
    
    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
    actions.pushBack(cocos2d::DelayTime::create(1));
    actions.pushBack(cocos2d::FadeTo::create(1, 255));
    actions.pushBack(cocos2d::DelayTime::create(1.5));
    actions.pushBack(cocos2d::FadeTo::create(1.5, 0));
    actions.pushBack(cocos2d::CallFunc::create([=] () -> void {
        logger("Sending callback");
        this->_actionsOver();
    }));

	auto sequence = cocos2d::Sequence::create(actions);

	sprite->runAction(sequence);

    auto keyboardEventListner = EventListenerKeyboard::create();
    keyboardEventListner->onKeyPressed = [] (EventKeyboard::KeyCode keyCode, Event * event) {
        dynamic_cast<WelcomeScene *>(event->getCurrentTarget())->_actionsOver();
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardEventListner, this);
    
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener->onTouchBegan = [] (Touch * touch, Event * event) -> bool {
        dynamic_cast<WelcomeScene *>(event->getCurrentTarget())->_actionsOver();
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventListener, this);
    
	return true;
}

void
WelcomeScene::_actionsOver()
{
	auto event = new AppEvent(ChessAppEvents::kWelcomeScreenAnimationOver);
	stateMachine->receiveEvent(event);
    logger("Event sent");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark WelcomeSceneState
////////////////////////////////////////////////////////////////////////////////////////////////////

void
WelcomeSceneState::_enter()
{
    logger("WelcomeSceneState::_enter()");
    
    WelcomeScene * welcomeScene;
    auto scene = WelcomeScene::createScene(_getStateMachine(), &welcomeScene);
    AppDelegate::getInstance()->setNewScene(scene);
    
    logger("WelcomeSceneState::_enter() new scene careated");
}

void
WelcomeSceneState::_exit()
{
    logger("WelcomeSceneState::_exit()");
}

AppState *
WelcomeSceneState::_react(AppEvent * inEvent)
{
    logger("WelcomeSceneState::_react(%d)", inEvent->getID());
    
	switch (inEvent->getID())
	{
        case ChessAppEvents::kWelcomeScreenAnimationOver:
        {
            ChessboardScene * chessboardScene;
            auto scene = ChessboardScene::createScene(_getStateMachine(), &chessboardScene);
            AppDelegate::getInstance()->setNewScene(scene);
            
            return new ChessboardSceneStaticState(chessboardScene);
        }
		default:
			return new ErrorState();
	}
}
