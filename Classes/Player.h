/*
 * Player.h
 *
 *  Created on: 2015年7月8日
 *      Author: Administrator
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class Player: public cocos2d::Sprite {
public:
	Player();
	virtual ~Player();
	bool init(Vec2 playerPos);
	static Player *create(Vec2 playerPos);

	void createPlayer();
	void createPlayerHpBar();
	void rotateArrow(Point touchPoint);
	void createAndShootArrow(Point touchPoint);
	void shootArrow();
	void finishRunAction();
//	void update(float dt);

	CC_SYNTHESIZE(int, playerHp, PlayerHp);					//玩家血量
	CC_SYNTHESIZE(bool, startDraw, StartDraw);			//是否开始画红色的路劲线
	CC_SYNTHESIZE(bool, isRunAction, IsRunAction);	//玩家是否正在执行射箭动画

private:
    Vec2 playerPos;            		// 角色在 tmx 地图上的位置
    Size playerSize;           			// 角色尺寸
    Size winSize;             	 		// 屏幕窗口尺寸
    Sprite* playerbody;        		// 角色身体
    Sprite* playerarrow;       		// 角色的弓箭，也就是会随触摸点旋转的弓和箭部分
    Sprite* hPBgSprite;        		// 角色血条背景精灵
    ProgressTimer* hpBar;      	// 角色血条
//    ccQuadBezierConfig bezier; 	// 路径贝赛尔
    DrawNode* drawNode;        // 这里表示我们的线条对象
};

#endif /* PLAYER_H_ */
