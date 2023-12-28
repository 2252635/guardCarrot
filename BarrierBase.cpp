#include "BarrierBase.h"

bool BarrierBase::init(Vec2 position)
{
	if (!VictimEntityBase::init())
		return false;
    setPutPosition(position);
    setBarrier();
}

BarrierBase* BarrierBase::create(Vec2 position)
{
	BarrierBase* pBarrier = new BarrierBase;
    if (pBarrier && pBarrier->init(position))
    {
        pBarrier->autorelease();
        return pBarrier;
    }
    CC_SAFE_DELETE(pBarrier);
    return nullptr;
}

void BarrierBase::setBarrier()
{
    barrier = Sprite::create("xxxx");
    barrier->setPosition(putPosition);
    this->addChild(barrier);
}

void BarrierBase::hurtAction()
{

}

Sprite* BarrierBase::setVictim(Vec2 position)
{
    VictimEntityBase::setVictim(position);
    if (IsTarget)
        return barrier;
}

void BarrierBase::unsetVictim()
{
    IsTarget = false;

}