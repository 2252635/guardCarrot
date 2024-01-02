#include"TowerBase.h"
#include"PublicSourceDefine.h"
#include"MonsterManager.h"
TowerBase::~TowerBase()
{
	CC_SAFE_RELEASE_NULL(towerPanel);//�ͷ�ָ������ָ��
	CC_SAFE_RELEASE_NULL(target);//�ͷ�ָ�򹥻�Ŀ���ָ��
	//CC_SAFE_RELEASE_NULL(gradeMark);//�ͷŵȼ���ָ��
}
TowerBase* TowerBase::init(TowerType type, Vec2 targetPos,Sprite*&newTowerBase)
{
	if (type != BOTTLE && type != STAR && type != SHIT)
		return nullptr;
	else {
		switch (type) {
			case BOTTLE:
				towerPanel = Sprite::create(TOWERBOTTLE+std::to_string(1)+PHOTOPOSTFIX);
				towerBase = Sprite::create(BOTTLEBASE);
					break;
			case STAR:
				towerPanel = Sprite::create(TOWERSTAR + std::to_string(1) + PHOTOPOSTFIX);
				towerBase = Sprite::create(STARBASE);
					break;
			case SHIT:
				towerPanel = Sprite::create(TOWERSHIT + std::to_string(1) + PHOTOPOSTFIX);
				towerBase = Sprite::create(SHITBASE);
				break;
			default:
				break;
		}
		towerPanel->setPosition(targetPos);//���þ����λ��
		towerBase->setPosition(targetPos);
		newTowerBase = towerBase;
		setParameter();//���ò���
		target = nullptr;

		return this;//���س�ʼ���ɹ��ı�־
	}
}
bool TowerBase::upGrade(int money)
{
	if (grade <TOWER_MAX_GRADE && checkMoney(money)) {
		grade++;
		//CC_SAFE_RELEASE_NULL(towerPanel);
		//std::string newImage;
		//switch (type) {
		//case BOTTLE:
		//	newImage = TOWERBOTTLE + std::to_string(grade) + PHOTOPOSTFIX;
		//	break;
		//case STAR:
		//	newImage = TOWERSTAR + std::to_string(grade) + PHOTOPOSTFIX;
		//	break;
		//case SHIT:
		//	newImage = TOWERSHIT + std::to_string(grade) + PHOTOPOSTFIX;
		//	break;
		//}
		//towerPanel = Sprite::create(newImage);//�����ȼ���ͼƬ

		attack += dAttack;//���ӹ�����
		setDAttack(dAttack + BOTTLE_EVERY_ATTACK);//���ӹ�����������

		attackRange += dAttackRange;//���ӹ�����Χ
		setDAttackRange(dAttackRange + BOTTLE_EVERY_ATTACK_RANGE);//���ӹ�����Χ������

		upCost += dUpCost;//��������ʱ�Ļ���
		setDUpCost(dUpCost + BOTTLE_EVERY_UP_COST);//��������ʱ�Ļ��ѵ�����

		doUpAction();
		return true;
	}
	else
		return false;
}
bool TowerBase::checkMoney(int money)
{
	if (money >= upCost)
		return true;
	else
		return false;
}
bool TowerBase::isInAttackRange(VictimEntityBase* newTarget)
{
	auto targetPos = newTarget->getVictim()->getPosition();//��ȡĿ���λ��
	auto myPos = towerPanel->getPosition();//��ȡ��������λ��
	auto dis = myPos.distance(targetPos);//�������֮��ľ���
	if (dis <= attackRange)
		return true;
	else
		return false;
}
void TowerBase::setTarget(VictimEntityBase* newTarget)
{
	target = nullptr;
	target = newTarget;//�����µĹ���Ŀ��
	setHaveTarget(true);
}
void TowerBase::chooseTarget(float dt)
{
	Vector<MonsterBase*> &monsters = MonsterManager::getVec();//��ȡ�洢�����vector
	if (!target) {//���û�й���Ŀ��
		for (auto currentMonster : monsters)//��һ�ѹ�����ѡ��һ���ڷ�Χ�ڵĹ���
		{
			if (isInAttackRange(currentMonster)) {//����ù���λ�ڹ�����Χ��
				setTarget(currentMonster);//���ù�����Ϊ����Ŀ��
				setHaveTarget(true);//�����Ƿ���Ŀ���״̬
				break;
			}
		}
	}
}
void TowerBase::fire(float dt)
{
	if (target) {
		if (!target->IsDead()&&isInAttackRange(target))
			fireAction(target->getVictim()->getPosition());
		else 
			missTarget();
	}
}
void TowerBase::missTarget()
{
	target = nullptr;
}
//void TowerBase::showGradeMark()
//{
//	gradeMark->setVisible(true);
//}
//void TowerBase::hideGradeMark()
//{
//	gradeMark->setVisible(false);
//}
