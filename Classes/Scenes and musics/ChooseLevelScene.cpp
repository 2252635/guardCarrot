#include "ChooseLevelScene.h"

USING_NS_CC;

//创造场景
Scene* ChooseLevelScene::createScene()
{
	return ChooseLevelScene::create();
}

//出错报错
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool ChooseLevelScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//设置背景
	auto background = Sprite::create("pictures/ChooseLevelScene");
	if (background == nullptr)
	{
		problemLoading("'ChooseScene.jpg'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	//设置开始按钮
	const int designNum = 2;
	int levelNum = LevelManager::getInstance()->returnCurrentLevel();
	//可以点击的开始按钮(第一关)
	MenuItemImage* startMenuOne = MenuItemImage::create(
		"pictures/ChooseLevelScene",
		"pictures/ChooseLevelScene",
		CC_CALLBACK_1(ChooseLevelScene::menuStartCallBackOne, this)
	);

	if (startMenuOne == nullptr ||
		startMenuOne->getContentSize().width <= 0 ||
		startMenuOne->getContentSize().height <= 0)
	{
		problemLoading("'startMenu.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - startMenuOne->getContentSize().width / 2;
		float y = origin.y + startMenuOne->getContentSize().height / 2;
		startMenuOne->setPosition(Vec2(x, y));
	}
	//第二关的按钮设置
	if (levelNum == designNum) 
	{
		MenuItemImage* startMenuTwo = MenuItemImage::create(
			"pictures/ChooseLevelScene",
			"pictures/ChooseLevelScene",
			CC_CALLBACK_1(ChooseLevelScene::menuStartCallBackTwo, this)
		);

		if (startMenuTwo == nullptr ||
			startMenuTwo->getContentSize().width <= 0 ||
			startMenuTwo->getContentSize().height <= 0)
		{
			problemLoading("'startMenu.png'");
		}
		else
		{
			float x = origin.x + visibleSize.width - startMenuTwo->getContentSize().width / 2;
			float y = origin.y + startMenuTwo->getContentSize().height / 2;
			startMenuTwo->setPosition(Vec2(x, y));
		}
	}
	else
	{
		MenuItemImage* startMenuTwo = MenuItemImage::create(
			"pictures/ChooseLevelScene",
			"pictures/ChooseLevelScene",
			CC_CALLBACK_1(ChooseLevelScene::menuStay, this)
		);

		if (startMenuTwo == nullptr ||
			startMenuTwo->getContentSize().width <= 0 ||
			startMenuTwo->getContentSize().height <= 0)
		{
			problemLoading("'startMenu.png'");
		}
		else
		{
			float x = origin.x + visibleSize.width - startMenuTwo->getContentSize().width / 2;
			float y = origin.y + startMenuTwo->getContentSize().height / 2;
			startMenuTwo->setPosition(Vec2(x, y));
		}
	}

	return true;
}

void ChooseLevelScene::menuStartCallBackOne(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(11);
	Director::getInstance()->replaceScene(Scene);
}

void ChooseLevelScene::menuStartCallBackTwo(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(22);
	Director::getInstance()->replaceScene(Scene);
}

void ChooseLevelScene::menuStay(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(0);
	Director::getInstance()->replaceScene(Scene);
}


