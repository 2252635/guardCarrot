#include "Carrot.h"
#include "Sym"

bool Carrot::init(Vec2 position)
{
	if (!VictimEntityBase::init())
		return false;
    setCarrotPosition(position);
}

Carrot* Carrot::create(Vec2 position)
{
    Carrot* pCarrot = new Carrot;
    if (pCarrot && pCarrot->init(position))
    {
        pCarrot->autorelease();
        return pCarrot;
    }
    else {
        CC_SAFE_DELETE(pCarrot);
        return nullptr;
    }
}

void Carrot::setCarrot()
{
    carrot = Sprite::create();
    carrot->setPosition(getCarrotPosition());
    this->addChild(carrot);
}

void Carrot::hurtAction()
{
    auto hurtCarrot = Sprite::create();
    hurtCarrot->setPosition(getCarrotPosition());
    this->addChild(hurtCarrot);
}

bool Carrot::levelUp()
{
    myHp->setNowHp(myHp->getNowHp() * 2);
}