#include"TowerBase.h"
TowerBase::~TowerBase()
{
	CC_SAFE_RELEASE_NULL(towerPanel);//释放指向面板的指针
	CC_SAFE_RELEASE_NULL(target);//释放指向攻击目标的指针
	CC_SAFE_RELEASE_NULL(gradeMark);//释放等级的指针
}
TowerBase* TowerBase::init(TowerType type, Vec2 targetPos)
{
	if (type != BOTTLE && type != STAR && type != SHIT)
		return nullptr;
	else {
		switch (type) {
			case BOTTLE:
				towerPanel = Sprite::create(瓶子塔名字)；
					break;
			case STAR:
				towerPanel = Sprite::create(星星塔名字);
					break;
			case SHIT:
				towerPanel = Sprite::create(屎塔名字);
				break;
			default:
				break;
		}
		towerPanel->setPosition(targetPos);//设置精灵的位置
		this->addChild(towerPanel);//将精灵添加到场景中
		setParameter();//设置参数
		return this;//返回初始化成功的标志
	}
}
bool TowerBase::upGrade(std::string&FileName)
{
	if (grade <= TOWER_MAX_GRADE && checkMoney()) {
		grade++;
		CC_SAFE_RELEASE_NULL(gradeMark);
		gradeMark = Sprite::create(FileName + std::to_string(grade));//更换等级的图片

		attack += dAttack;//增加攻击力
		setDAttack(dAttack + BOTTLE_EVERY_ATTACK);//增加攻击力的增量

		attackRange += dAttackRange;//增加攻击范围
		setDAttackRange(dAttackRange + BOTTLE_EVERY_ATTACK_RANGE);//增加攻击范围的增量

		upCost += dUpCost;//增加升级时的花费
		setDUpCost(dUpCost + BOTTLE_EVERY_UP_COST);//增加升级时的花费的增量
		return true;
	}
	else
		return false;
}
bool TowerBase::checkMoney()
{
	if (getMoney() >= upCost)
		return true;
	else
		return false;
}
bool TowerBase::isInAttackRange(VictimEntityBase* newTarget)
{
	auto targetPos = newTarget->getPosition();//获取目标的位置
	auto myPos = towerPanel->getPosition();//获取防御塔的位置
	auto dis = myPos.distance(targetPos);//计算二者之间的距离
	if (dis <= getAttackRange())
		return true;
	else
		return false;
}
void TowerBase::setTarget(VictimEntityBase* newTarget)
{
	target = nullptr;
	target = newTarget;//设置新的攻击目标
	setHaveTarget(true);
}
void TowerBase::chooseTarget()
{
	MonsterVec& monsters = MonsterManager::getVec();//获取存储怪物的vector
	if (!target) {//如果没有攻击目标
		for (auto currentMonster : monsters)//从一堆怪物中选择一个在范围内的怪物
		{
			if (isInAttackRange(currentMonster)) {//如果该怪物位于攻击范围内
				setTarget(currentMonster);//将该怪物设为攻击目标
				setHaveTarget(true);//更改是否有怪物的状态
				break;
			}
		}
	}
}
void TowerBase::fire()
{
	if (target && !target->getIsDead())
		fireAction();
	else if (target->getIsDead())
		missTarget();
}
void TowerBase::missTarget()
{
	target = nullptr;
}
void TowerBase::showGradeMark()
{
	gradeMark->setVisible(true);
}
void TowerBase::hideGradeMark()
{
	gradeMark->setVisible(false);
}
