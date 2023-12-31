#include"TowerManager.h"
#include "PublicSourceDefine.h"
#include"DynamicProperty.h"
Vector<TowerBase*>* TowerManager::towers;

Vector<TowerBase*>& TowerManager::getVec()
{
	return *towers;
}
Sprite* TowerManager::addTower(TowerType type,Vec2 pos, Sprite* &towerBase)
{
	TowerBase* newTower;
	switch (type) {
	case BOTTLE:
		newTower = new TowerBottle;
		break;
	case STAR:
		newTower = new TowerStar;
		break;
	case SHIT:
		newTower = new TowerShit;
		break;
	default:
		break;
	}
	auto ref=newTower->init(type,pos,towerBase);
	if (!ref)
		throw "TowerConstructFalse";
	else
		towers->pushBack(newTower);
	AudioManager::getInstance()->playBuildSound();
	return newTower->getTowerPanel();
}
bool TowerManager::setTarget(VictimEntityBase* newTarget)
{
	for (auto currentTower : *towers)
		if (currentTower->isInAttackRange(newTarget)) {
			currentTower->setTarget(newTarget);//���÷������Ĺ���Ŀ����Ϊ
			return true;
		}
	return false;
}
TowerManager::~TowerManager()
{
	
}
void TowerManager::destroyTower(TowerBase*targetTower)
{
	targetTower->removeFromParent();//���ý��Ӹ��ڵ����Ƴ�
	auto pos=towers->find(targetTower);//�ҵ�����λ��
	CC_SAFE_RELEASE_NULL(targetTower);//��ָ����Ϊ��
	towers->erase(pos);//�����ָ��
}