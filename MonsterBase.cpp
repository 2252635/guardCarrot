#include "MonsterBase.h"
#include "base/CCScheduler.h"
#include "CocosDeshion"
#include ""

MonsterBase* MonsterBase::create(std::vector<Vec2> _path,Vec2 position)
{
	MonsterBase* pMonster = new MonsterBase;
	if (pMonster && pMonster->init(_path,position))
	{
		pMonster->autorelease();
		return pMonster;
	}
	else {
		CC_SAFE_DELETE(pMonster);
		return nullptr;
	}

}

bool MonsterBase::init(std::vector<Vec2> _path, Vec2 position)
{
	if (!VictimEntityBase::init())
		return false;
	path = _path;
	startPosition = position;
	switch (nowMonsterType)
	{
	case normal:normSpeed = 5; slowSpeed = normSpeed / 2; nowSpeed = normSpeed; myHp->create(50); break;
	case fast:normSpeed = 7; slowSpeed = normSpeed / 2; nowSpeed = normSpeed; myHp->create(40); break;
	case slow:normSpeed = 3; slowSpeed = normSpeed / 2;  nowSpeed = normSpeed; myHp->create(70); break;
	}
	setMonster();

}


void MonsterBase::setMonster()
{
	monster = Sprite::create("xxxxx");
	monster->setPosition(startPosition);
	this->addChild(monster);
}

void MonsterBase::hurtAction()
{
	std::function<void(float)> slowDown = [this](float)
		{
			setNormSpeed(getSlowSpeed());
			setBeSlowTime(getBeSlowTime()-1);
			if (getBeSlowTime() == 0)
				unschedule("Slowdown");
		};
	this->schedule(slowDown, 1.0f, "Slowdown");
}

void MonsterBase::move(float dt)
{
	auto animation = Animation::create();//创建移动动画
	for (int i = 1; i <= 3; ++i) {
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("frame%d.png", i));
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(0.2f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	for (int i = 0; i < path.size() - 1; i++) {
		auto moveAction = MoveTo::create(nowSpeed, path[i]);//创建移动
		auto spawnAction = Spawn::create(moveAction, animate);//创建同时动作
		this->runAction(spawnAction);
	}
}

void MonsterBase::whenDead()
{
	VictimEntityBase::whenDead();

	SimpleAudioEngine::getInstance()->playEffect("sound_effect.mp3");
}

Sprite* MonsterBase::setVictim(Vec2 _position)
{
	VictimEntityBase::setVictim(_position);
	if (IsTarget)
		return monster;
}

void MonsterBase::unsetVictim()
{
	IsTarget = false;
}
