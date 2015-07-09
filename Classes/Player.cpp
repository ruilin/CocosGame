/*
 * Player.cpp
 *
 *  Created on: 2015年7月8日
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
    createPlayer();        // 创建角色
//    createPlayerHpBar();   // 创建角色血量条
    scheduleUpdate();
    return true;
}

void Player::createPlayer() {
//    playerbody = Sprite::createWithSpriteFrameName("playerbody.png");
    playerbody = Sprite::create("playerbody.png");
    playerSize = Size(playerbody->getContentSize().width/2, playerbody->getContentSize().height / 3*2);  // 设置Player的尺寸，大小略小于playerbody的尺寸，这样利于我们后面更准确的进行碰撞设置。
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
    // 创建血条底，即进度条的底背景
    hPBgSprite = Sprite::createWithSpriteFrameName("hpbg.png");
    hPBgSprite->setPosition(Vec2(playerbody->getContentSize().width / 2, playerbody->getContentSize().height));
    playerbody->addChild(hPBgSprite);
    // 创建血条
    hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("hp1.png"));
    hpBar->setType(ProgressTimer::Type::BAR); // 设置进度条样式（条形或环形）
    hpBar->setMidpoint(Vec2(0, 0.5f));        // 设置进度条的起始点，（0，y）表示最左边，（1，y）表示最右边，（x，1）表示最上面，（x，0）表示最下面。
    hpBar->setBarChangeRate(Vec2(1, 0));      // 设置进度条变化方向，（1,0）表示横方向，（0,1）表示纵方向。
    hpBar->setPercentage(100);                // 设置当前进度条的进度
    hpBar->setPosition(Vec2(hPBgSprite->getContentSize().width / 2, hPBgSprite->getContentSize().height / 2 ));
    hPBgSprite->addChild(hpBar);
    hPBgSprite->setVisible(false);   // 设置整个血条不可见，我们将在Player 遭受攻击的时候再显示血条。
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
