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
    pcarrot->setScale(1.5);
    pcarrot->setPosition(position);
    level = 0;
    myHp = new Hp;
    myHp->init(10);
    myHp->setPosition(Vec2(pcarrot->getContentSize().width / 2, pcarrot->getContentSize().height + 0));
    myHp->setScale(0.3);
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
    if (level < CARROT_MAX_LEVEL) {
        auto parent = pcarrot->getParent();
        auto position = pcarrot->getPosition();
        level++;
        pcarrot->removeFromParent();
        switch (level) {
            case 1:pcarrot=Sprite::create("pictures/items/level1.png"); break;
            case 2:pcarrot=Sprite::create("pictures/items/level2.png"); break;
            default:break;
        }
        pcarrot->setScale(1.5);
        pcarrot->setPosition(position);
        parent->addChild(pcarrot, MONSTER_LAYER);
        myHp->setMaxHp(myHp->getMaxHp() * 2);
        myHp->setNowHp(myHp->getNowHp() * 2);
        pcarrot->addChild(myHp);
        return true;
    }
    else
        return false;
}