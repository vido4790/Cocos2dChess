/***************************************************************************************************
 *
 *  @file       WelcomeScene.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief
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
WelcomeScene::createScene(AppStateMachine * inStateMachine)
{
	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
    
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
        cocos2d::log("Sending callback");
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
	_stateMachine->receiveEvent(event);
    cocos2d::log("Event sent");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark WelcomeScreenState
////////////////////////////////////////////////////////////////////////////////////////////////////

Scene *
WelcomeScreenState::_createScene()
{
    return WelcomeScene::createScene(_getStateMachine());
}

AppState *
WelcomeScreenState::_react(AppEvent * inEvent)
{
    cocos2d::log("WelcomeScreenState::_react(%d)", inEvent->getID());
    
	switch (inEvent->getID())
	{
        case ChessAppEvents::kWelcomeScreenAnimationOver:
            return new ChessboardScreenCreateState();
		default:
			return new ErrorState();
	}
}
