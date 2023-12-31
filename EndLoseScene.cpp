#include "EndLoseScene.h"

USING_NS_CC;

//创造场景
Scene* EndLoseScene::createScene()
{
	return  EndLoseScene::create();
}

//出错报错
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool  EndLoseScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//继续按钮
	MenuItemImage* conMenu = MenuItemImage::create(
		"pictures/scenes/return_normal.png",
		"pictures/scenes/return_selected.png",
		CC_CALLBACK_1(EndLoseScene::menuConCallBack, this)
	);

	if (conMenu == nullptr ||
		conMenu->getContentSize().width <= 0 ||
		conMenu->getContentSize().height <= 0)
	{
		problemLoading("'conMenu.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2-50;
		float y = origin.y + visibleSize.height / 2-50;
		conMenu->setPosition(Vec2(x, y));
	}
	Menu* mu = Menu::create(conMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//设置背景
	auto background = Sprite::create("pictures/scenes/HelpBackground.png");
	background->setScale(2.5);
	if (background == nullptr)
	{
		problemLoading("'HelpBackground.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	auto lose = Sprite::create("pictures/scenes/game_lose.png");
	lose->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	lose->setScale(2.0);
	this->addChild(lose);

	return true;
}

void   EndLoseScene::menuConCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(MAP_BLUE_VIEW);
	Director::getInstance()->replaceScene(Scene);
}
