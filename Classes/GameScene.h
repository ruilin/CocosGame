/*
 * GameScene.h
 *
 *  Created on: 2015��7��7��
 *      Author: Ryan
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include <cstdio>
#include "Player.h"

USING_NS_CC;

class GameScene : public Layer
{
public:
    GameScene();

    static cocos2d::Scene* createScene();
    virtual bool init();
    void addGameBg();

    CREATE_FUNC(GameScene);

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);  // ��ʼ������Ļʱ��Ӧ
    virtual void onTouchMoved(Touch *touch, Event *unused_event);  // ������Ļ������Ļ�ϻ���ʱ��Ӧ
    virtual void onTouchEnded(Touch *touch, Event *unused_event);  // ��������ʱ��Ӧ

private:
    Player *player;
    Point preTouchPoint;     		 	// ��һ��������
    Point currTouchPoint;    		 	// ��ǰ������
    Size winSize;                  // ���ڳߴ�
    TMXTiledMap *map;              // ��ͼ��������
    TMXObjectGroup * objectGroup;  // ���������
    float objectPosOffX;           // ������X�����ϵ�ƫ��ֵ
};

#endif /* GAMESCENE_H_ */
