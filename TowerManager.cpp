#include"TowerManager.h"
#include "SoundUtil.h"
#include "PublicSourceDefine.h"
Vector<TowerBase*>* TowerManager::getVec()
{
	return towers;
}
void TowerManager::addTower(TowerType type, Vec2 pos)
{
	auto newTower = new TowerBase;
	SoundUtil mySound;
	mySound->playEffect(BUILDTOWER);
	auto ref=newTower->init(type, pos);
	if (!ref)
		throw "TowerConstructFalse";
	else 
		towers->pushBack(newTower);
}
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