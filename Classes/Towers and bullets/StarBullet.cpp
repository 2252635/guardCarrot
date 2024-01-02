#include"StarBullet.h"
void StarBullet::setParameter()
{
	myType = STAR_BULLET;
	isSlow = false;
}
void StarBullet::attack(int attack, bool beSlow)
{
	/*auto targetPos = target->getVictim()->getPosition();
	auto myPos=bulletPanel->getPosition();*/
	auto moveAction = MoveBy::create(0.5, -(target->getVictim()->getPosition()));
	/*bulletPanel->runAction(moveAction);
	auto ref = target->getBoundingBox().intersectsRect(bulletPanel->getBoundingBox());*/
	target->whenHurt(attack, isSlow);
	/*bulletPanel->removeFromParent();*/
	auto callback = CallFunc::create([=]() {
		// �ӵ����й������߼���������ʧ
		bulletPanel->removeFromParent();
		});

	// ����Sequence����
	auto sequence = Sequence::create(moveAction, callback, nullptr);

	// ���ж���
	bulletPanel->runAction(sequence);
}