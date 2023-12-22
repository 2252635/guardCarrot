#include"TowerLayer.h"
#include "TowerManager.h"
#include "Tower.h"

bool TowerLayer::Initiate()
{
	bool Ret = false;

	do
	{
		CC_BREAK_IF(!Layer::Init());//如果图层初始化失败，直接返回false
		//否则
		auto Cache = SpriteFrameCache::getInstance();//获取精灵帧缓存实例
		for (auto& IterSource : TOWERS)//遍历Towers数组，添加每一个图片到精灵帧
			Cache->addSpriteFramesWithFile(IterSource + PLISTPOSTFIX, IterSource + PHOTOPOSTFIX);
		schedule(schedule_selector(TowerLayer::CheckTowerGrade));//定期检查防御塔等级
		Ret = true;
	} while (0);

	return Ret;
}

void TowerLayer::CheckTowerGrade(float Delta) {
	for (auto& Item : TowerManager::getInstance()->GetTowerVec()) {
		if (Item->getAttackUp() <= 1) {
			if (Item->getUpCost() <= TowerManager::getInstance()->GetMoney()) 
				Item->ShowGrade();
			else  
				Item->HideGrade();
		}
	}
}
