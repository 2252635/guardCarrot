#include "Carrot.h"
#include "PublicSourceDefine.h"
bool Carrot::init(Vec2 position)
{
	if (!VictimEntityBase::init())
		return false;
    setCarrotPosition(position);
}

Carrot* Carrot::create(Vec2 position)
{
    pcarrot = Sprite::create(CARROT01);
    pcarrot->setPosition(position);
    myHp = new Hp;
    myHp->init(10);
    myHp->setPosition(Vec2(pcarrot->getContentSize().width / 2, pcarrot->getContentSize().height + 0));
    pcarrot->addChild(myHp);
    victim = pcarrot;
    return this;
}


void Carrot::hurtAction()
{
    auto hurtCarrot = Sprite::create(CARROT02);
    hurtCarrot->setPosition(getCarrotPosition());
    this->addChild(hurtCarrot);
}

bool Carrot::levelUp()
{
    myHp->setNowHp(myHp->getNowHp() * 2);
    return true;
}