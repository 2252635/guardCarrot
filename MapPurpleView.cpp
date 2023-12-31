#include "MapPurpleView.h"

USING_NS_CC;

//���쳡��
Scene* MapPurpleView::createScene()
{
	return MapPurpleView::create();
}

//������
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

	//��ʼ��ť
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

	//���ذ�ť
	MenuItemImage* returnItem = MenuItemImage::create(
		"pictures/scenes/return1.PNG",
		"pictures/scenes/return2.PNG",
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
		float x = origin.x + returnItem->getContentSize().width / 2;
		float y = origin.y + visibleSize.height - returnItem->getContentSize().height / 2;
		returnItem->setPosition(Vec2(x, y));
	}

	//���ذ�ť
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

	//���ְ�ť
	musicItems = MenuItemImage::create(
		"pictures/scenes/music1.PNG",
		"pictures/scenes/music2.PNG",
		CC_CALLBACK_1(MapPurpleView::menuMusic, this)
	);
	if (musicItems == nullptr ||
		musicItems->getContentSize().width <= 0 ||
		musicItems->getContentSize().height <= 0)
	{
		problemLoading("'musicItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - musicItems->getContentSize().width / 2;
		float y = origin.y - musicItems->getContentSize().height / 2 + visibleSize.height;
		musicItems->setPosition(Vec2(x, y));
	}

	// �̳оɳ���������״̬
	isMusicPlaying = SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
	// ��������״̬���ò�ͬ��ͼƬ
	if (isMusicPlaying) {
		musicItems->setNormalImage(Sprite::create("pictures/scenes/music1.PNG"));
		musicItems->setSelectedImage(Sprite::create("pictures/scenes/music2.PNG"));
	}
	else {
		musicItems->setNormalImage(Sprite::create("pictures/scenes/music2.PNG"));
		musicItems->setSelectedImage(Sprite::create("pictures/scenes/music1.PNG"));
	}
	// ���³����и�������״̬���ز�����/��ͣ����
	if (isMusicPlaying) {
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/view2.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/view2.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

	Menu* mu = Menu::create(startMenu, returnItem, tranItem, musicItems, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//���ñ���
	auto background = Sprite::create("pictures/scenes/BackgroundPurple.png");
	background->setScale(3.0);
	if (background == nullptr)
	{
		problemLoading("'BackgroundPurple.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}
	auto sprite = Sprite::create("pictures/scenes/MapPurpleView.PNG");
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	sprite->setScale(2.5);
	this->addChild(sprite);

	//��ס
	if (LevelManager::getInstance()->returnCurrentLevel() < 2) {
		auto locked = Sprite::create("pictures/scenes/lock.PNG");
			locked->setPosition(Vec2(origin.x + visibleSize.width / 4 * 3 + 8, origin.y + visibleSize.height / 4 + 38));
			locked->setScale(1.0);
			this->addChild(locked);
	}
	return true;
}

void  MapPurpleView::menuStartCallBack(cocos2d::Ref* pSender)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (LevelManager::getInstance()->returnCurrentLevel() >= 2) {
		auto Scene = SceneFactory::createScene(MAP_PURPLE);
		Director::getInstance()->replaceScene(Scene);
	}
	else {
		//��ס��ʾ
		auto lockSprite = Sprite::create("pictures/scenes/lock_image.png");
		lockSprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
		lockSprite->setScale(1.0);
		this->addChild(lockSprite);

		auto delayAction = DelayTime::create(1.0f);
		auto removeAction = CallFunc::create([lockSprite]() {
			lockSprite->removeFromParent();
			});
		// ����һ�����ж����������ӳٺ�ɾ������
		auto sequenceAction = Sequence::create(delayAction, removeAction, nullptr);
		// ����������ж���
		lockSprite->runAction(sequenceAction);
	}
}

void  MapPurpleView::menuReturnCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(START);
	Director::getInstance()->replaceScene(Scene);
}

void  MapPurpleView::menuTranCallBack(cocos2d::Ref* pSender)
{
	auto Scene = SceneFactory::createScene(MAP_BLUE_VIEW);
	Director::getInstance()->replaceScene(Scene);
}

void MapPurpleView::menuMusic(cocos2d::Ref* pSender)
{
	// �л�����״̬
	isMusicPlaying = !isMusicPlaying;

	// ��������״̬���ò�ͬ��ͼƬ
	if (isMusicPlaying) {
		musicItems->setNormalImage(Sprite::create("pictures/scenes/music1.PNG"));
		musicItems->setSelectedImage(Sprite::create("pictures/scenes/music2.PNG"));
	}
	else {
		musicItems->setNormalImage(Sprite::create("pictures/scenes/music2.PNG"));
		musicItems->setSelectedImage(Sprite::create("pictures/scenes/music1.PNG"));
	}

	// ������ִ���л����ֵ������߼�
	if (isMusicPlaying) {
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musics/view2.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/view2.mp3", true);
	}
	else {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}
