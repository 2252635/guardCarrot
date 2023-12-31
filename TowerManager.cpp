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
			currentTower->setTarget(newTarget);//将该防御塔的攻击目标设为
			return true;
		}
	return false;
}
TowerManager::~TowerManager()
{
	
}
void TowerManager::destroyTower(TowerBase*targetTower)
{
	targetTower->removeFromParent();//将该结点从父节点上移除
	auto pos=towers->find(targetTower);//找到塔的位置
	CC_SAFE_RELEASE_NULL(targetTower);//将指针置为空
	towers->erase(pos);//清除该指针
}