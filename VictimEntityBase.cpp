#include "VictimEntityBase.h"

VictimEntityBase::~VictimEntityBase()
{
	CC_SAFE_RELEASE_NULL(myHp);
	CC_SAFE_RELEASE_NULL(beLocked);
	
}

bool VictimEntityBase::init()
{
	if (!Node::init())
		return false;
	beSlowTime = 0;
	position = getPosition();
	size = getContentSize();
}

void VictimEntityBase::whenHurt(int atkValue,int slowTime)
{
	myHp->changeHpBy(atkValue);
	beSlowTime = slowTime;
	if (myHp->getNowHp() <= 0) {
		whenDead();
		isDead = true;
	}
	else
		hurtAction();
}

void  VictimEntityBase::whenDead()
{
	if (myHp)
		myHp->removeFromParent();
	if (beLocked)
		beLocked->removeFromParent();
	this->setVisible(false);
	myHp->setVisible(false);
}

void VictimEntityBase::whenLoacked()
{
	beLocked = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("point01.png"));
	CC_SAFE_RETAIN(beLocked);
	beLocked->setPosition(Vec2(position.x, position.y));
	addChild(beLocked, 2);
}

Sprite* VictimEntityBase::setVictim(Vec2 _position)
{
	if (position == _position) {
		IsTarget = true;
	}
}