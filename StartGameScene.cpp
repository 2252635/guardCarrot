#include "LevelManage.h"
#include "StartGameScene.h"

USING_NS_CC;

//创造场景
Scene* StartGame::createScene()
{
	return StartGame::create();
}

//出错报错
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool StartGame::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//开始按钮
	MenuItemImage* startMenu = MenuItemImage::create(
		"pictures/scenes/Btn_NormalModle.PNG",
		"pictures/scenes/Btn_NormalModleLight.PNG",
		CC_CALLBACK_1(StartGame::menuStartCallBack, this)
	);

	if (startMenu == nullptr ||
		startMenu->getContentSize().width <= 0 ||
		startMenu->getContentSize().height <= 0)
	{
		problemLoading("'Btn_NormalModle.PNG'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 5;
		startMenu->setPosition(Vec2(x, y));
	}

	//结束按钮
	MenuItemImage* closeItem = MenuItemImage::create(
		"pictures/scenes/CloseNormal.png",
		"pictures/scenes/CloseSelected.png",
		CC_CALLBACK_1(StartGame::menuEndCallBack, this)
	);

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'closeItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	Menu* mu = Menu::create(startMenu, closeItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//设置背景
	auto background = Sprite::create("pictures/scenes/MainBG.PNG");
	if (background == nullptr)
	{
		problemLoading("'MainBG.PNG'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	// 创建精灵对象
	auto sprite = Sprite::create("pictures/scenes/MainTitle.PNG");
	// 设置精灵的位置
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	// 设置精灵的缩放
	sprite->setScale(1.0);
	// 将精灵添加到场景中
	this->addChild(sprite);

	return true;
}

void StartGame::menuStartCallBack(cocos2d::Ref* pSender)
{
	LevelManager::getInstance()->startGame();
}

void StartGame::menuEndCallBack(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();

}