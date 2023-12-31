#include"BulletBase.h"
#include"PublicSourceDefine.h"
BulletBase* BulletBase::create(int grade,BulletType type, VictimEntityBase* newTarget,Vec2 startPos)
{
	if (type != BOTTLE_BULLET && type != STAR_BULLET && type != SHIT_BULLET)
		return nullptr;
	else {
		switch (type) {
			case BOTTLE_BULLET:
				bulletPanel = Sprite::create(BOTTLEBULLET+std::to_string(grade)+ PHOTOPOSTFIX);
				break;
			case STAR_BULLET:
				bulletPanel = Sprite::create(STARBULLET + std::to_string(grade) + PHOTOPOSTFIX);
				break;
			case SHIT_BULLET:
				bulletPanel = Sprite::create(SHITBULLET+ PHOTOPOSTFIX);
				break;
			default:
				break;
		}
		setParameter();
		bulletPanel->setPosition(startPos);//设置起始位置
		target = newTarget;
		return this;
	}
}

void BulletBase::move()
{
	auto myMove=MoveTo::create(0.2,target->getPosition());
	auto callback = cocos2d::CallFunc::create([this]() {
		this->removeFromParent();
		});
	auto sequence = cocos2d::Sequence::create(myMove, callback, nullptr);
	bulletPanel->runAction(sequence);
}
BulletBase::~BulletBase()
{
	target = nullptr;
	CC_SAFE_RELEASE_NULL(bulletPanel);
}