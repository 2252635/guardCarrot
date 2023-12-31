#include"ShitBullet.h"
void ShitBullet::setParameter()
{
	myType = SHIT_BULLET;
	isSlow = true;
}
void ShitBullet::attack(int hurt, bool beSlow)
{
	// 设置子弹的起始位置 

	cocos2d::Vec2 direction = (target->getVictim()->getPosition() - bulletPanel->getPosition()).getNormalized();
	//// 设置子弹的旋转角度，使其朝向目标 
	bulletPanel->setRotation(CC_RADIANS_TO_DEGREES(M_PI + direction.getAngle()));
	// 移动子弹 
	auto moveAction = cocos2d::MoveTo::create(0.2f, target->getVictim()->getPosition());
	
	///*bulletPanel->removeFromParent();*/
	auto callback = CallFunc::create([=]() {
		// 子弹击中怪物后
		bulletPanel->removeFromParent();
		target->whenHurt(hurt, isSlow);
		});

	// 创建Sequence动作
	auto sequence = Sequence::create(moveAction, callback, nullptr);

	//// 运行动作
	bulletPanel->runAction(sequence);
}