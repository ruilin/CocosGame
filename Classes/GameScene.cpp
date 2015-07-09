/*
 * GameScene.cpp
 *
 *  Created on: 2015年7月7日
 *      Author: Ryan
 */

#include "GameScene.h"

GameScene::GameScene() {
	// TODO Auto-generated constructor stub

}

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameScene::init() {
	winSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	CCLog("XXX  %f  %f", winSize.width, winSize.height);
	addGameBg();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture.plist", "texture.pvr.ccz");
	player = Player::create(Vec2(winSize.width / 4, winSize.height/5));
	this->addChild(player);

	// 获取事件分发器
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	// 创建单点触摸监听器
	auto listener = EventListenerTouchOneByOne::create();
	// 让监听器绑定事件处理函数
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded,this);
	// 将事件监听器添加到事件调度器
	dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	return true;
}

void GameScene::addGameBg(){
    // 添加图片背景，把它放在屏幕正中间
    Sprite* spGameBg = Sprite::create("HelloWorld.png");
    spGameBg->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(spGameBg, -1);

    // 添加地图背景，把它放在屏幕正中间
    map = TMXTiledMap::create("map1.tmx");
    map->setAnchorPoint(Vec2(0.5f, 0.5f));
    map->setPosition(Vec2(winSize.width / 2, winSize.height/2));
    this->addChild(map, -1);

    // 获取 objectGroup 对象（也就是地图中的对象层）
    objectGroup = map->getObjectGroup("object");
    // 计算对象组在 X 方向上的偏移值
    objectPosOffX = -(map->getContentSize().width - winSize.width) / 2;
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
    currTouchPoint = touch->getLocation();
//    if(!currTouchPoint.equals(preTouchPoint)){
//        player->rotateArrow(currTouchPoint);
//    }
    preTouchPoint = currTouchPoint;
    return true;
}

void GameScene::onTouchMoved(Touch *touch, Event *unused_event)
{
    currTouchPoint = touch->getLocation();
    if(!currTouchPoint.equals(preTouchPoint)){
        player->rotateArrow(currTouchPoint);
    }
    preTouchPoint = currTouchPoint;
}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event)
{
    // 射箭，下章内容
}

