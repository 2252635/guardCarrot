#include "EndLoseScene.h"
#include "GameScene.h"

USING_NS_CC;

//���쳡��
Scene* EndLoseScene::createScene()
{
	return  EndLoseScene::create();
}

//������
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

	//������ť
	MenuItemImage* conMenu = MenuItemImage::create(
		"pictures/",
		"pictures/",
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
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2;
		conMenu->setPosition(Vec2(x, y));
	}

	//���ñ���
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

void   EndLoseScene::menuConCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(0);
	Director::getInstance()->replaceScene(Scene);
}
