#include "StartGameScene.h"

USING_NS_CC;

//���쳡��
Scene* StartGame::createScene()
{
	return StartGame::create();
}

//������
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

	//��ʼ��ť
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

	//������ť
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

	//������ť
	MenuItemImage* helpItem = MenuItemImage::create(
		"pictures/scenes/HelpBtn1.png",
		"pictures/scenes/HelpBtn2.png",
		CC_CALLBACK_1(StartGame::menuHelpCall, this)
	);
	if (helpItem == nullptr ||
		helpItem->getContentSize().width <= 0 ||
		helpItem->getContentSize().height <= 0)
	{
		problemLoading("'helpItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 4 - helpItem->getContentSize().width / 2;
		float y = origin.y + helpItem->getContentSize().height / 2 + visibleSize.height / 3 * 2;
		helpItem->setPosition(Vec2(x, y));
	}

	//���ְ�ť
	musicItem = MenuItemImage::create(
		"pictures/scenes/music1.PNG",
		"pictures/scenes/music2.PNG",
		CC_CALLBACK_1(StartGame::menuMusic, this)
	);
	if (musicItem == nullptr ||
		musicItem->getContentSize().width <= 0 ||
		musicItem->getContentSize().height <= 0)
	{
		problemLoading("'musicItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width/4*3 - musicItem->getContentSize().width / 2;
		float y = origin.y + musicItem->getContentSize().height / 2 + visibleSize.height / 3 * 2;
		musicItem->setPosition(Vec2(x, y));
	}
	
	Menu* mu = Menu::create(startMenu, closeItem, helpItem, musicItem,NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);


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
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/BGMusic.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/BGMusic.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}


	//���ñ���
	auto background = Sprite::create("pictures/scenes/MainBG.PNG");
	background->setScale(2.0);
	if (background == nullptr)
	{
		problemLoading("'MainBG.PNG'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	// �����������
	auto sprite = Sprite::create("pictures/scenes/MainTitle.PNG");
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	sprite->setScale(2.0);
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
void StartGame::menuHelpCall(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(HELP);
	Director::getInstance()->replaceScene(Scene);
}

void StartGame::menuMusic(cocos2d::Ref* pSender)
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
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/BGMusic.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/BGMusic.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}