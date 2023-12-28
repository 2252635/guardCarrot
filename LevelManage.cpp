#include "GameScene.h"
#include "LevelManage.h"
#include "PublicDefine.h"

USING_NS_CC;

void LevelManager::startGame()
{
	auto scene = SceneFactory::createScene(MAP_BLUE_VIEW);
	Director::getInstance()->replaceScene(scene);
}


void LevelManager::unlockedNextLevel()
{
	currentLevel++;
}

int LevelManager::returnCurrentLevel()
{
	return currentLevel;
}

LevelManager* LevelManager::getInstance() {
	static LevelManager instance; // ��̬ʵ����ֻ�ڵ�һ�ε���ʱ����
	return &instance;
}

LevelManager::LevelManager()
{
	currentLevel = 1;
}