#include"BulletBase.h"
BulletBase* BulletBase::create(int grade,BulletType type, VictimEntityBase* newTarget,Vec2 startPos)
{
	if (type != BOTTLE_BULLET && type != STAR_BULLET && type != SHIT_BULLET)
		return nullptr;
	else {
		switch (type) {
			case BOTTLE_BULLET:
				bulletPanel = Sprite::create(ƿ�������ӵ�);
				break;
			case STAR_BULLET:
				bulletPanel = Sprite::create(���������ӵ���;
				break;
			case SHIT_BULLET:
				bulletPanel = Sprite::create(ʺ���ӵ�);
				break;
			default:
				break;
		}
		setParameter();
		setPosition(startPos);//������ʼλ��
		addChild(this);//���Ϊ�ӽ��
		target = newTarget;
		return this;
	}
}
void BulletBase::attack(int attack,bool beSlow )
{
	auto ref = target->getBoundingBox().intersectsRect(bulletPanel->getBoundingBox())
		target->whenHurt(attack,isSlow);
}
void BulletBase::move()
{
	auto myMove=moveTo::create(target->getPosition());
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