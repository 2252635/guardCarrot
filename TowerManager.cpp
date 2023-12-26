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
	targetTower->removeFromParent();//���ý��Ӹ��ڵ����Ƴ�
	auto pos=towers->find(targetTower);//�ҵ�����λ��
	CC_SAFE_RELEASE_NULL(targetTower);//��ָ����Ϊ��
	towers->erase(pos);//�����ָ��
}