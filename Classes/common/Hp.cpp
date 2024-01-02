#include "Hp.h"

//Hp* Hp::create(int hp)
//{
//	Hp* pHp = new Hp;
//	if (pHp && pHp->init(hp))
//	{
//		return pHp;
//	}
//	else {
//		CC_SAFE_DELETE(pHp);
//		return nullptr;
//	}
//}


bool Hp::init(int hp)
{
	if (!LoadingBar::init())
	{
		return false;
	}

	loadTexture("pictures/items/hp2.png", TextureResType::LOCAL);
	
	maxHp = hp;
	nowHp = hp;
	setPercent(100);//设置进度条为100

	auto background = Sprite::create("pictures/items/hp.png");
	background->setScale(1.0);
	auto size = getContentSize();
	background->setPosition(size / 2);
	background->setOpacity(200);
	this->addChild(background, -1);

	_barRenderer->setZOrder(30);



	return true;
}

void Hp::changeHpBy(int atkValue)
{
	if (nowHp < 0)
	{
		return;
	}

	nowHp -= atkValue;

    if (nowHp < 0)
	{
		nowHp = 0;
	}
	updateHp();
}

void Hp::updateHp()
{
	setPercent(nowHp * 100.0 / maxHp);
}
