/*
 * Player.h
 *
 *  Created on: 2015��7��8��
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

	CC_SYNTHESIZE(int, playerHp, PlayerHp);					//���Ѫ��
	CC_SYNTHESIZE(bool, startDraw, StartDraw);			//�Ƿ�ʼ����ɫ��·����
	CC_SYNTHESIZE(bool, isRunAction, IsRunAction);	//����Ƿ�����ִ���������

private:
    Vec2 playerPos;            		// ��ɫ�� tmx ��ͼ�ϵ�λ��
    Size playerSize;           			// ��ɫ�ߴ�
    Size winSize;             	 		// ��Ļ���ڳߴ�
    Sprite* playerbody;        		// ��ɫ����
    Sprite* playerarrow;       		// ��ɫ�Ĺ�����Ҳ���ǻ��津������ת�Ĺ��ͼ�����
    Sprite* hPBgSprite;        		// ��ɫѪ����������
    ProgressTimer* hpBar;      	// ��ɫѪ��
//    ccQuadBezierConfig bezier; 	// ·��������
    DrawNode* drawNode;        // �����ʾ���ǵ���������
};

#endif /* PLAYER_H_ */
