/*
 * GameScene.cpp
 *
 *  Created on: 2015��7��7��
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

	// ��ȡ�¼��ַ���
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	// �������㴥��������
	auto listener = EventListenerTouchOneByOne::create();
	// �ü��������¼�������
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded,this);
	// ���¼���������ӵ��¼�������
	dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	return true;
}

void GameScene::addGameBg(){
    // ���ͼƬ����������������Ļ���м�
    Sprite* spGameBg = Sprite::create("HelloWorld.png");
    spGameBg->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(spGameBg, -1);

    // ��ӵ�ͼ����������������Ļ���м�
    map = TMXTiledMap::create("map1.tmx");
    map->setAnchorPoint(Vec2(0.5f, 0.5f));
    map->setPosition(Vec2(winSize.width / 2, winSize.height/2));
    this->addChild(map, -1);

    // ��ȡ objectGroup ����Ҳ���ǵ�ͼ�еĶ���㣩
    objectGroup = map->getObjectGroup("object");
    // ����������� X �����ϵ�ƫ��ֵ
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
    // �������������
}

