#include"BottleBullet.h"
void BottleBullet::setParameter()
{
	myType = BOTTLE_BULLET;
	isSlow = false;
}
void BottleBullet::attack(int attack, bool beSlow)
{
	/*auto targetPos = target->getVictim()->getPosition();
	auto myPos=bulletPanel->getPosition();*/
	auto moveAction = MoveBy::create(0.5, -(target->getVictim()->getPosition()));
	/*bulletPanel->runAction(moveAction);
	auto ref = target->getBoundingBox().intersectsRect(bulletPanel->getBoundingBox());*/
	target->whenHurt(attack, isSlow);
	/*bulletPanel->removeFromParent();*/
	auto callback = CallFunc::create([=]() {
		// 子弹击中怪物后的逻辑，比如消失
		bulletPanel->removeFromParent();
		});

	// 创建Sequence动作
	auto sequence = Sequence::create(moveAction, callback, nullptr);

	// 运行动作
	bulletPanel->runAction(sequence);
}