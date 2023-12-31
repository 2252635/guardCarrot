#include "HelpScene.h"

USING_NS_CC;

//���쳡��
Scene* HelpScene::createScene()
{
	return HelpScene::create();
}

//������
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool HelpScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//���ذ�ť
	MenuItemImage* returnItem = MenuItemImage::create(
		"pictures/scenes/return1.PNG",
		"pictures/scenes/return2.PNG",
		CC_CALLBACK_1(HelpScene::menuCallBack, this)
	);

	if (returnItem == nullptr ||
		returnItem->getContentSize().width <= 0 ||
		returnItem->getContentSize().height <= 0)
	{
		problemLoading("'returnItem.png'");
	}
	else
	{
		float x = origin.x + returnItem->getContentSize().width / 2;
		float y = origin.y + visibleSize.height - returnItem->getContentSize().height / 2;
		returnItem->setPosition(Vec2(x, y));
	}

	//���ְ�ť
	musicItem = MenuItemImage::create(
		"pictures/scenes/music1.PNG",
		"pictures/scenes/music2.PNG",
		CC_CALLBACK_1(HelpScene::menuMusic, this)
	);
	if (musicItem == nullptr ||
		musicItem->getContentSize().width <= 0 ||
		musicItem->getContentSize().height <= 0)
	{
		problemLoading("'musicItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - musicItem->getContentSize().width / 2;
		float y = origin.y - musicItem->getContentSize().height/2+ visibleSize.height;
		musicItem->setPosition(Vec2(x, y));
	}

	Menu* mu = Menu::create(returnItem, musicItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//���ñ���
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

	//��������˵��ͼƬ
	auto star = Sprite::create("pictures/scenes/star.png");
	star->setPosition(Vec2(origin.x + visibleSize.width / 6, origin.y + visibleSize.height / 2));
	star->setScale(2.0);
	this->addChild(star);

	auto shit = Sprite::create("pictures/scenes/shit.png");
	shit->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	shit->setScale(2.0);
	this->addChild(shit);

	auto bottle = Sprite::create("pictures/scenes/bottle.png");
	bottle->setPosition(Vec2(origin.x + visibleSize.width/2+480, origin.y + visibleSize.height / 2));
	bottle->setScale(2.0);
	this->addChild(bottle);

	// �̳оɳ���������״̬
	isMusicPlaying = SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
	// ��������״̬���ò�ͬ��ͼƬ
	if (isMusicPlaying) {
		musicItem->setNormalImage(Sprite::create("pictures/scenes/music1.PNG"));
		musicItem->setSelectedImage(Sprite::create("pictures/scenes/music2.PNG"));
	}
	else {
		musicItem->setNormalImage(Sprite::create("pictures/scenes/music2.PNG"));
		musicItem->setSelectedImage(Sprite::create("pictures/scenes/music1.PNG"));
	}
	// ���³����и�������״̬���ز�����/��ͣ����
	if (isMusicPlaying) {
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/Help.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/Help.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

	
	return true;
}

void  HelpScene::menuCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(START);
	Director::getInstance()->replaceScene(Scene);
}

void  HelpScene::menuReturn(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(START);
	Director::getInstance()->replaceScene(Scene);
}

void HelpScene::menuMusic(cocos2d::Ref* pSender)
{
	// �л�����״̬
	isMusicPlaying = !isMusicPlaying;

	// ��������״̬���ò�ͬ��ͼƬ
	if (isMusicPlaying) {
		musicItem->setNormalImage(Sprite::create("pictures/scenes/music1.PNG"));
		musicItem->setSelectedImage(Sprite::create("pictures/scenes/music2.PNG"));
	}
	else {
		musicItem->setNormalImage(Sprite::create("pictures/scenes/music2.PNG"));
		musicItem->setSelectedImage(Sprite::create("pictures/scenes/music1.PNG"));
	}

	// ������ִ���л����ֵ������߼�
	if (isMusicPlaying) {
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/Help.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/Help.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}