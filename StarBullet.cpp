#include"StarBullet.h"
void StarBullet::setParameter()
{
	myType = STAR_BULLET;
	isSlow = false;
}
void StarBullet::attack(int attack, bool beSlow)
{
	// �����ӵ�����ʼλ�� 
	
	cocos2d::Vec2 direction = (target->getVictim()->getPosition() - bulletPanel->getPosition()).getNormalized(); 
	//// �����ӵ�����ת�Ƕȣ�ʹ�䳯��Ŀ�� 
	//bulletPanel->setRotation(CC_RADIANS_TO_DEGREES(direction.getAngle())); 
	// �ƶ��ӵ� 
	auto moveAction=cocos2d::MoveTo::create(0.2f, target->getVictim()->getPosition()); 

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