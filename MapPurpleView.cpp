#include "MapPurpleView.h"
#include "GameScene.h"
#include "PublicDefine.h"

USING_NS_CC;

//创造场景
Scene* MapPurpleView::createScene()
{
	return MapPurpleView::create();
}

//出错报错
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool MapPurpleView::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//开始按钮
	MenuItemImage* startMenu = MenuItemImage::create(
		"pictures/scenes/Begin1.PNG",
		"pictures/scenes/Begin2.PNG",
		CC_CALLBACK_1(MapPurpleView::menuStartCallBack, this)
	);

	if (startMenu == nullptr ||
		startMenu->getContentSize().width <= 0 ||
		startMenu->getContentSize().height <= 0)
	{
		problemLoading("'startMenu.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 5;
		startMenu->setPosition(Vec2(x, y));
	}

	//返回按钮
	MenuItemImage* returnItem = MenuItemImage::create(
		"pictures/",
		"pictures/",
		CC_CALLBACK_1(MapPurpleView::menuReturnCallBack, this)
	);

	if (returnItem == nullptr ||
		returnItem->getContentSize().width <= 0 ||
		returnItem->getContentSize().height <= 0)
	{
		problemLoading("'returnItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - returnItem->getContentSize().width / 2;
		float y = origin.y + returnItem->getContentSize().height / 2;
		returnItem->setPosition(Vec2(x, y));
	}

	//换关按钮
	MenuItemImage* tranItem = MenuItemImage::create(
		"pictures/scenes/tran3.PNG",
		"pictures/scenes/tran4.PNG",
		CC_CALLBACK_1(MapPurpleView::menuTranCallBack, this)
	);

	if (tranItem == nullptr ||
		tranItem->getContentSize().width <= 0 ||
		tranItem->getContentSize().height <= 0)
	{
		problemLoading("'tranItem.png'");
	}
	else
	{
		float x = origin.x + tranItem->getContentSize().width / 2;
		float y = origin.y + tranItem->getContentSize().height / 2 + visibleSize.height / 2;
		tranItem->setPosition(Vec2(x, y));
	}

	Menu* mu = Menu::create(startMenu, returnItem, tranItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//设置背景
	auto background = Sprite::create("pictures/scenes/BackgroundPurple.png");
	if (background == nullptr)
	{
		problemLoading("'BackgroundPurple.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	// 创建精灵对象
	auto sprite = Sprite::create("pictures/scenes/MapPurpleView.PNG");
	// 设置精灵的位置
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	// 设置精灵的缩放
	sprite->setScale(1.5);
	// 将精灵添加到场景中
	this->addChild(sprite);

	return true;



}

void  MapPurpleView::menuStartCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(MAP_PURPLE);
	Director::getInstance()->replaceScene(Scene);
}

void  MapPurpleView::menuReturnCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(0);
	Director::getInstance()->replaceScene(Scene);
}

void  MapPurpleView::menuTranCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(MAP_BLUE_VIEW);
	Director::getInstance()->replaceScene(Scene);
}