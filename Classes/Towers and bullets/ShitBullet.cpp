#include"ShitBullet.h"
void ShitBullet::setParameter()
{
	myType = SHIT_BULLET;
	isSlow = true;
}
void ShitBullet::attack(int hurt, bool beSlow)
{
	//auto targetPos = target->getVictim()->getPosition();
	//auto myPos = bulletPanel->getPosition();//获取自己防御塔的位置

	//auto direction = targetPos - myPos;
	//float angleRadians = atan2(direction.y, direction.x);//计算弧度
	//while (angleRadians < -M_PI)
	//	angleRadians += 2 * M_PI;
	//while (angleRadians > M_PI)
	//	angleRadians -= 2 * M_PI;
	//float angleDegree = CC_RADIANS_TO_DEGREES(angleRadians);//弧度转角度
	//bulletPanel->setRotation(-angleDegree);//进行旋转
	auto moveAction = MoveBy::create(2.0, -(target->getVictim()->getPosition()));
	target->whenHurt(hurt, beSlow);
	auto callback = CallFunc::create([=]() {
		// 子弹击中怪物后的逻辑，比如消失
		bulletPanel->removeFromParent();
		});
	// 创建Sequence动作
	auto sequence = Sequence::create(moveAction, callback, nullptr);
	// 运行动作
	bulletPanel->runAction(sequence);
}