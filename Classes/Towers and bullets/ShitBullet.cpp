#include"ShitBullet.h"
void ShitBullet::setParameter()
{
	myType = SHIT_BULLET;
	isSlow = true;
}
void ShitBullet::attack(int hurt, bool beSlow)
{
	//auto targetPos = target->getVictim()->getPosition();
	//auto myPos = bulletPanel->getPosition();//��ȡ�Լ���������λ��

	//auto direction = targetPos - myPos;
	//float angleRadians = atan2(direction.y, direction.x);//���㻡��
	//while (angleRadians < -M_PI)
	//	angleRadians += 2 * M_PI;
	//while (angleRadians > M_PI)
	//	angleRadians -= 2 * M_PI;
	//float angleDegree = CC_RADIANS_TO_DEGREES(angleRadians);//����ת�Ƕ�
	//bulletPanel->setRotation(-angleDegree);//������ת
	auto moveAction = MoveBy::create(2.0, -(target->getVictim()->getPosition()));
	target->whenHurt(hurt, beSlow);
	auto callback = CallFunc::create([=]() {
		// �ӵ����й������߼���������ʧ
		bulletPanel->removeFromParent();
		});
	// ����Sequence����
	auto sequence = Sequence::create(moveAction, callback, nullptr);
	// ���ж���
	bulletPanel->runAction(sequence);
}