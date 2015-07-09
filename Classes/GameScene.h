/*
 * GameScene.h
 *
 *  Created on: 2015年7月7日
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

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);  // 开始触摸屏幕时响应
    virtual void onTouchMoved(Touch *touch, Event *unused_event);  // 触摸屏幕并在屏幕上滑动时响应
    virtual void onTouchEnded(Touch *touch, Event *unused_event);  // 触摸结束时响应

private:
    Player *player;
    Point preTouchPoint;     		 	// 上一个触摸点
    Point currTouchPoint;    		 	// 当前触摸点
    Size winSize;                  // 窗口尺寸
    TMXTiledMap *map;              // 地图背景对象
    TMXObjectGroup * objectGroup;  // 对象组对象
    float objectPosOffX;           // 对象组X方向上的偏移值
};

#endif /* GAMESCENE_H_ */
