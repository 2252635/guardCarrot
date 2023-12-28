/*#include "MapBlue.h"
#include "PublicDefineSource.h"

Scene* MapBlue::createScene()
{
	return MapBlue::create();
}
bool MapBlue::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("mapBlue.png");//创建背景精灵
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);//将背景精灵添加到当前结点中

	layout();//对mapBoard数组进行初始化

	//铺路
	for (int i = 0; i < MAP_ROW; i++)
		for (int j = 0; j < MAP_COL; j++) {
			SceneBlock* newBlock = new SceneBlock;
			BlockType type = mapBoard[i][j];
			newBlock->init(type, BLOCKIMAGE);
			newBlock->getBlock()->setPosition(BLOCK_SIZE / 2 + i * BLOCK_SIZE, BLOCK_SIZE / 2 + j * BLOCK_SIZE);
			newBlock->getBlock()->setContentSize(Size(BLOCK_SIZE, BLOCK_SIZE));
			this->addChild(newBlock);
			block.pushBack(newBlock);
			if (type == ROAD)
				road.pushBack(newBlock);
		}
}
void MapBlue::layout()
{
	//给地图设置布局
	/*  0 1 2 3 4 5 6 7 8 9 1011121314151617
	  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	  1 0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
	  2 0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
	  3 0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
	  4 0 0 0 0 0 0 0 0 0 0 0 1 * 0 0 0 0 0
	  5 0 0 0 1 * * * 0 0 0 0 0 * 0 0 0 0 0
	  6 0 0 0 0 * 1 * 0 0 0 0 0 * 1 1 0 0 0
	  7 0 0 0 0 * 0 * 0 0 0 0 0 * 1 1 0 0 0
	  8 0 0 * * * 0 * 1 1 0 0 0 * 0 0 0 0 0
	  9 0 0 0 0 0 0 * 1 1 0 0 0 * 0 0 0 0 0
	 10 0 0 0 0 0 0 * * * * * * * 0 0 0 0 0
	 11 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	for (int i = 0; i < MAP_ROW; i++)
		for (int j = 0; j < MAP_COL; j++)
			mapBoard[i][j] = BlockType(1);//先全部假设为可以放置防御塔

	//铺路
	for (int i = 2; i < 5; i++)
		mapBoard[8][i] = BlockType(0);//ROAD
	for (int i = 8; i > 4; i--)
		mapBoard[i][4] = BlockType(0);
	for (int i = 4; i < 7; i++)
		mapBoard[5][i] = BlockType(0);
	for (int i = 5; i < 11; i++)
		mapBoard[i][6] = BlockType(0);
	for (int i = 6; i < 13; i++)
		mapBoard[10][i] = BlockType(0);
	for (int i = 10; i >= 0; i--)
		mapBoard[i][12] = BlockType(0);

	//铺障碍物
	mapBoard[5][3] = BlockType(3);//BARRIER
	mapBoard[6][5] = BlockType(3);
	mapBoard[8][7] = BlockType(3);
	mapBoard[8][8] = BlockType(3);
	mapBoard[9][7] = BlockType(3);
	mapBoard[9][8] = BlockType(3);
	mapBoard[4][11] = BlockType(3);
	mapBoard[6][13] = BlockType(3);
	mapBoard[6][14] = BlockType(3);
	mapBoard[7][13] = BlockType(3);
	mapBoard[7][14] = BlockType(3);

	auto mouseListener = EventListenerMouse::create();

	mouseListener->onMouseDown = [=](Event* event) {
		EventMouse* e = dynamic_cast<EventMouse*>(event);
		if (e) {
			mousePosition = Vec2(e->getCursorX(), e->getCursorY());
		}
	};

	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

void MapBlue::setBarrier()
{
	for (int i = 0; i < MAP_ROW; i++) {
		for (int j = 0; j < MAP_COL; j++) {
			if (mapBoard[i][j] == BARRIER) {
				auto pbarrier = new BarrierBase;
				Vec2 _pos(i * BLOCK_SIZE + BLOCK_SIZE / 2, j * BLOCK_SIZE + BLOCK_SIZE / 2);
				pbarrier->setPutPosition(_pos);
				gameManager->getBarrierVec()->addBarrier(pbarrier);
			}
		}
	}
}
*/
