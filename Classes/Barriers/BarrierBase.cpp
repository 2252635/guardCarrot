#include "BarrierBase.h"
#include "PublicSourceDefine.h"

bool BarrierBase::init()
{
    if (!VictimEntityBase::init())

        return false;
}

void  BarrierBase::create(Vec2 _pos)
{
    void srand(unsigned int seed);
    int type;
    type = (rand() % 4) + 0;
    switch (static_cast<BarrierType>(type)) {
    case BALL_ONE: barrier = Sprite::create(BARRIER01); break;
    case BALL_TWO: barrier = Sprite::create(BARRIER02); break;
    case CLOUD_BLUE: barrier = Sprite::create(BARRIER03); break;
    case CLOUD_PURPLE: barrier = Sprite::create(BARRIER04); break;
    default:break;
    }
    barrier->setPosition(_pos);
    myHp = new Hp;
    myHp->init(100);
    myHp->setPosition(Vec2(barrier->getContentSize().width / 2, barrier->getContentSize().height +0));
    barrier->addChild(myHp);
    victim = barrier;
}

void BarrierBase::hurtAction()
{

}

Sprite* BarrierBase::setVictim(Vec2 _position)
{
    if (position == _position) {
        IsTarget = true;
    }
    if (IsTarget)
        return barrier;
}

void BarrierBase::unsetVictim()
{
    IsTarget = false;

}
