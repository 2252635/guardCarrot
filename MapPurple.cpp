#include "MapPurple.h"

Scene* MapPurple::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MapPurple::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MapPurple::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    return true;
}

void MapPurple::setShuzu()
{
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            isSet[i][j] = BlockType(2);//NO_TOWER
        }
    }

    for (int i = 0; i < 10; i++) {
        isSet[1][10 - i] = BlockType(0);//ROAD
    }
    for (int i = 0; i < 4; i++) {
        isSet[2 + i][1] = BlockType(0);
    }
    for (int i = 0; i < 4; i++) {
        isSet[5][2 + i] = BlockType(0);
    }
    for (int i = 0; i < 4; i++) {
        isSet[6 + i][5] = BlockType(0);
    }
    for (int i = 0; i < 3; i++) {
        isSet[9][4 - i] = BlockType(0);
    }
    for (int i = 0; i < 7; i++) {
        isSet[10 + i][2] = BlockType(0);
    }
    for (int i = 0; i < 5; i++) {
        isSet[16][3 + i] = BlockType(0);
    }
    isSet[2][8] = BlockType(3);//BARRIER
    isSet[0][5] = BlockType(3);
    isSet[2][2] = BlockType(3);
    isSet[5][6] = BlockType(3);
    isSet[8][3] = BlockType(3);
    isSet[13][3] = BlockType(3);
    isSet[14][6] = BlockType(3);

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

void MapPurple::setSingle(BlockType type, int i, int j)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto newBlock = new SceneBlock;
    newBlock->init(type, "xxxxx");
    newBlock->setPosition(origin.x + BLOCK_SIZE * i + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2);
    this->addChild(newBlock, 0);
    purpleBlock.pushBack(newBlock);
}

void MapPurple::set()
{
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            setSingle(isSet[i][j], i, j);
        }
    }

}

void MapPurple::setBarrier()
{
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            if (isSet[i][j] == BARRIER) {
                auto pbarrier = new BarrierBase;
                Vec2 _pos(i * BLOCK_SIZE + BLOCK_SIZE / 2, j * BLOCK_SIZE + BLOCK_SIZE / 2);
                pbarrier->setPutPosition(_pos);
                gameManager->getBarrierVec()->addBarrier(pbarrier);
            }
        }
    }
}