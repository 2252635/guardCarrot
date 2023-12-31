#include"BottleBullet.h"
void BottleBullet::setParameter()
{
	myType = BOTTLE_BULLET;
	isSlow = false;
}
void BottleBullet::attack(int attack, bool beSlow)
{
	cocos2d::Vec2 direction = (target->getVictim()->getPosition() - bulletPanel->getPosition()).getNormalized();
	//// �����ӵ�����ת�Ƕȣ�ʹ�䳯��Ŀ�� 
	bulletPanel->setRotation(CC_RADIANS_TO_DEGREES(M_PI + direction.getAngle()));
	// �ƶ��ӵ� 
	auto moveAction = cocos2d::MoveTo::create(0.2f, target->getVictim()->getPosition());

	///*bulletPanel->removeFromParent();*/
	auto callback = CallFunc::create([=]() {
		// �ӵ����й����
		bulletPanel->removeFromParent();
		target->whenHurt(attack, isSlow);
		});

	// ����Sequence����
	auto sequence = Sequence::create(moveAction, callback, nullptr);

	//// ���ж���
	bulletPanel->runAction(sequence);
}