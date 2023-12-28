#include "EndWinScene.h"
#include "GameScene.h"
#include "LevelManage.h"

USING_NS_CC;

//创造场景
Scene* EndWinScene::createScene()
{
	return EndWinScene::create();
}

//出错报错
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool EndWinScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//继续按钮
	MenuItemImage* conMenu = MenuItemImage::create(
		"pictures/",
		"pictures/",
		CC_CALLBACK_1(EndWinScene::menuConCallBack, this)
	);

	if (conMenu == nullptr ||
		conMenu->getContentSize().width <= 0 ||
		conMenu->getContentSize().height <= 0)
	{
		problemLoading("'conMenu.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2;
		conMenu->setPosition(Vec2(x, y));
	}

	//设置背景
	auto background = Sprite::create("pictures/StartGameScene/startGameScene.jpg");
	if (background == nullptr)
	{
		problemLoading("'startGameScene.jpg'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	return true;
}

void  EndWinScene::menuConCallBack(cocos2d::Ref* pSender)
{
	LevelManager::getInstance()->unlockedNextLevel();
	auto Scene = SceneFactory::createScene(0);
	Director::getInstance()->replaceScene(Scene);
}
