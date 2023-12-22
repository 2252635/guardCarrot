#include"TowerLayer.h"
#include "TowerManager.h"
#include "Tower.h"

bool TowerLayer::Initiate()
{
	bool Ret = false;

	do
	{
		CC_BREAK_IF(!Layer::Init());//���ͼ���ʼ��ʧ�ܣ�ֱ�ӷ���false
		//����
		auto Cache = SpriteFrameCache::getInstance();//��ȡ����֡����ʵ��
		for (auto& IterSource : TOWERS)//����Towers���飬���ÿһ��ͼƬ������֡
			Cache->addSpriteFramesWithFile(IterSource + PLISTPOSTFIX, IterSource + PHOTOPOSTFIX);
		schedule(schedule_selector(TowerLayer::CheckTowerGrade));//���ڼ��������ȼ�
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
