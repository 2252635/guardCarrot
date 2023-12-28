#include "Hp.h"

Hp* Hp::create(int hp)
{
	Hp* pHp = new Hp;
	if (pHp && pHp->init(hp))
	{
		pHp->autorelease();
		return pHp;
	}
	else {
		CC_SAFE_DELETE(pHp);
		return nullptr;
	}
}


bool Hp::init(int hp)
{
	if (!LoadingBar::init())
	{
		return false;
	}

	loadTexture("xxxxxxx", TextureResType::LOCAL);
	maxHp = hp;
	nowHp = hp;
	setPercent(100);//设置进度条为100

	auto background = Sprite::create("xxxxxxxxxx");
	auto size = getContentSize();
	background->setPosition(size / 2);
	background->setOpacity(200);
	addChild(background, -1);

	_barRenderer->setZOrder(1);


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
