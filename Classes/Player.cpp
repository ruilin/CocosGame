/*
 * Player.cpp
 *
 *  Created on: 2015��7��8��
 *      Author: Administrator
 */

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub
}

Player::~Player() {
	// TODO Auto-generated constructor stub
}

Player * Player::create(Vec2 playerPos)
{
    Player *pRet  = new Player();
    if (pRet && pRet->init(playerPos)) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Player::init(Vec2 playerPos) {
    if (!Sprite::init()) {
        return false;
    }
    this->playerPos = playerPos;
    createPlayer();        // ������ɫ
//    createPlayerHpBar();   // ������ɫѪ����
    scheduleUpdate();
    return true;
}

void Player::createPlayer() {
//    playerbody = Sprite::createWithSpriteFrameName("playerbody.png");
    playerbody = Sprite::create("playerbody.png");
    playerSize = Size(playerbody->getContentSize().width/2, playerbody->getContentSize().height / 3*2);  // ����Player�ĳߴ磬��С��С��playerbody�ĳߴ磬�����������Ǻ����׼ȷ�Ľ�����ײ���á�
    playerbody->setAnchorPoint(Vec2(0.7f, 0.4f));
    this->addChild(playerbody);
    this->setPosition(Vec2(playerPos.x/*+ GameManager::getInstance()->getObjectPosOffX()*/, playerPos.y + playerSize.height * 0.4f));

//    playerarrow = Sprite::createWithSpriteFrameName("playerarrow.png");
    playerarrow = Sprite::create("playerarrow.png");
    playerarrow->setPosition(Vec2(0, 0));
    playerarrow->setAnchorPoint(Vec2(0.3f, 0.5f));
    this->addChild(playerarrow);
}

void Player::createPlayerHpBar() {
    // ����Ѫ���ף����������ĵױ���
    hPBgSprite = Sprite::createWithSpriteFrameName("hpbg.png");
    hPBgSprite->setPosition(Vec2(playerbody->getContentSize().width / 2, playerbody->getContentSize().height));
    playerbody->addChild(hPBgSprite);
    // ����Ѫ��
    hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("hp1.png"));
    hpBar->setType(ProgressTimer::Type::BAR); // ���ý�������ʽ�����λ��Σ�
    hpBar->setMidpoint(Vec2(0, 0.5f));        // ���ý���������ʼ�㣬��0��y����ʾ����ߣ���1��y����ʾ���ұߣ���x��1����ʾ�����棬��x��0����ʾ�����档
    hpBar->setBarChangeRate(Vec2(1, 0));      // ���ý������仯���򣬣�1,0����ʾ�᷽�򣬣�0,1����ʾ�ݷ���
    hpBar->setPercentage(100);                // ���õ�ǰ�������Ľ���
    hpBar->setPosition(Vec2(hPBgSprite->getContentSize().width / 2, hPBgSprite->getContentSize().height / 2 ));
    hPBgSprite->addChild(hpBar);
    hPBgSprite->setVisible(false);   // ��������Ѫ�����ɼ������ǽ���Player ���ܹ�����ʱ������ʾѪ����
}

void Player::rotateArrow(Point touchPoint) {
    // 1
    auto playerPos = this->getPosition();
    auto pos = playerPos + playerarrow->getPosition();
    // 2
    Point vector = touchPoint - pos;
    auto rotateRadians = vector.getAngle();
    auto rotateDegrees = CC_RADIANS_TO_DEGREES( -1 * rotateRadians);
    // 3
    if (rotateDegrees >= -180 && rotateDegrees <= -90){
        rotateDegrees = -90;
    }
    else if (rotateDegrees >= 90 && rotateDegrees <= 180){
        rotateDegrees = 90;
    }
    // 4
    auto speed = 0.5 / M_PI;
    auto rotateDuration = fabs(rotateRadians * speed);
    // 5
    playerarrow->runAction( RotateTo::create(rotateDuration, rotateDegrees));
}
