#include"TowerManager.h"
#include "SoundUtil.h"
#include "PublicSourceDefine.h"
<<<<<<< HEAD
Vector<TowerBase*>* TowerManager::getVec()
{
	return towers;
}
void TowerManager::addTower(TowerType type, Vec2 pos)
=======
#include"DynamicProperty.h"
Vector<TowerBase*>& TowerManager::getVec()
{
	return *towers;
}
void TowerManager::addTower(TowerType type,Vec2 pos)
>>>>>>> 3cc07b4 (lyy2)
{
	auto newTower = new TowerBase;
	SoundUtil mySound;
	mySound->playEffect(BUILDTOWER);
<<<<<<< HEAD
	auto ref=newTower->init(type, pos);
	if (!ref)
		throw "TowerConstructFalse";
	else 
		towers->pushBack(newTower);
}
=======
	auto ref=newTower->init(type,pos);
	if (!ref)
		throw "TowerConstructFalse";
	else
		towers->pushBack(newTower);
}
bool TowerManager::setTarget(VictimEntityBase* newTarget)
{
	for (auto currentTower : *towers)
		if (currentTower->isInAttackRange(newTarget))
			currentTower->setTarget(newTarget);//将该防御塔的攻击目标设为
}
>>>>>>> 3cc07b4 (lyy2)
TowerManager::~TowerManager()
{
	
}
void TowerManager::destroyTower(TowerBase*targetTower)
{
	SoundUtil mySound;
	mySound->playEffect(SELLTOWER);
	targetTower->removeFromParent();//将该结点从父节点上移除
	auto pos=towers->find(targetTower);//找到塔的位置
	CC_SAFE_RELEASE_NULL(targetTower);//将指针置为空
	towers->erase(pos);//清除该指针
}