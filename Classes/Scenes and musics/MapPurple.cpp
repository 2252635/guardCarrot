#include "MapPurple.h"
#include "PublicSourceDefine.h"
using namespace std;

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

//出错报错
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool MapPurple::init()
{
    if (!Layer::init())
    {
        return false;
    }
    gameManager = new GameManager;
    gameManager->init();

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

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

    auto mouseListener = EventListenerMouse::create();

    mouseListener->onMouseDown = [=](Event* event) {
        EventMouse* e = dynamic_cast<EventMouse*>(event);
        if (e) {
            mousePosition = Vec2(e->getCursorX(), e->getCursorY());
            // 检查是否正在移除顶层节点
            if (removingTopMostNode) {
                removingTopMostNode = false;
            }
            
            else {
                Vec2 targetPos;
                BlockType label = gameManager->judge(purpleBlock, mousePosition, targetPos);
                if (label == NO_TOWER) {

                    menu = Menu::create();

                    std::string bottleImage = (gameManager->getMoney() > BOTTLE_PRICE) ? BOTTLECANBUY+std::to_string(1) : BOTTLECANNOTBUY + std::to_string(1);
                    std::string starImage = (gameManager->getMoney() > STAR_PRICE) ? STARCANBUY + std::to_string(1) : STARCANNOTBUY + std::to_string(1);
                    std::string shitImage = (gameManager->getMoney() > SHIT_PRICE) ? SHITCANBUY + std::to_string(1) : SHITCANNOTBUY + std::to_string(1);

                    auto towerOption1 = MenuItemImage::create(bottleImage, BOTTLECANBUY, CC_CALLBACK_1(MapPurple::onTowerSelected, this, TowerType::BOTTLE, targetPos));
                    auto towerOption2 = MenuItemImage::create(starImage, STARCANBUY, CC_CALLBACK_1(MapPurple::onTowerSelected, this, TowerType::STAR, targetPos));
                    auto towerOption3 = MenuItemImage::create(shitImage, SHITCANBUY, CC_CALLBACK_1(MapPurple::onTowerSelected, this, TowerType::SHIT, targetPos));
                    removingTopMostNode = true;
                    menu->addChild(towerOption1);
                    menu->addChild(towerOption2);
                    menu->addChild(towerOption3);
                    menu->alignItemsHorizontally();
                    // 设置菜单的位置和标签
                    menu->setPosition(Vec2(targetPos.x, targetPos.y + 20));
                    menu->setTag(kTowerSelectMenuTag);
                    this->addChild(menu, 100);
                    setBlock(targetPos, TOWER);
                }
                else if (label == TOWER) {
                    auto towerVec = gameManager->getTowerManager()->getVec();
                    TowerBase* targetTower;
                    for(auto currentTower:towerVec)
                        if (currentTower->getPos() == targetPos) {
                            targetTower = currentTower;
                            break;
                        }
                    menu = Menu::create();
                    std:string towerImage;
                    switch (targetTower->getType()) {
                    case BOTTLE:
                        towerImage = gameManager->getMoney() > targetTower->getUpCost() ? BOTTLECANBUY : BOTTLECANNOTBUY;
                        break;
                    case STAR:
                        towerImage = gameManager->getMoney() > targetTower->getUpCost() ? STARCANBUY : STARCANNOTBUY;
                        break;
                    case SHIT:
                        towerImage = gameManager->getMoney() > targetTower->getUpCost() ? SHITCANBUY : SHITCANNOTBUY;
                        break;
                    }
                    std::string upGradeImage = towerImage + std::to_string((targetTower->getGrade()+1)%4) + PHOTOPOSTFIX;

                    
                    auto towerOption1 = MenuItemImage::create(upGradeImage, upGradeImage, CC_CALLBACK_1(MapPurple::onTowerDestroySelected, this, targetTower, 1));
                    auto towerOption2 = MenuItemImage::create(CANCELBUTTONNORMAL, CANCELBUTTONSELECTED, CC_CALLBACK_1(MapPurple::onTowerDestroySelected, this, targetTower, 0));

                    removingTopMostNode = true;
                    menu->addChild(towerOption1);
                    menu->addChild(towerOption2);
                    menu->alignItemsHorizontally();
                    // 设置菜单的位置和标签
                    menu->setPosition(Vec2(targetPos.x, targetPos.y + 20));
                    menu->setTag(kTowerSelectMenuTag);
                    this->addChild(menu, 100);
                }
            }
        }
        };

    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

    setShuzu();
    set();
    setBarrier();
    gameManager->getCarrot()->create(path[34]);
    this->addChild((gameManager->getCarrot())->getCarrotSprite());

  

    std::function<void(float)> Addmonster = [this](float)
        {
            auto monster = new MonsterBase;
            monster->create(path[0]);
            monster->startPosition = path[0];
            monster->getMonster()->setPosition(path[0]);
            this->addChild(monster->getMonster(),50);
            (gameManager->getMonsterVec()->getVec()).pushBack(monster);
            monster->monsterMove(path, NORMAL);
            count--;
            if (count == 0)
                this->unschedule("Addmonster");
        };
    this->schedule(Addmonster, 1.0f, "Addmonster");


    return true;
}

void MapPurple::onTowerDestroySelected(Ref* sender, TowerBase* targetTower, bool option)
{
    if (option) {
        if (targetTower->upGrade(gameManager->getMoney()))
            gameManager->getProperty().towerBuild(targetTower->getUpCost());
    }
    else {
        gameManager->getProperty().towerDead(targetTower->getPrice());
        targetTower->cleanup();
    }
}

void MapPurple::onTowerSelected(Ref* sender, TowerType type, Vec2 pos) {
    // 从 sender 获取菜单项和菜单
    // 移除菜单
    Node* topMostNode = this->getChildByTag(kTowerSelectMenuTag);

    if (topMostNode) {
        EventCustom customEvent("onTopMostNodeClicked");
        customEvent.setUserData(&pos); // 传递点击位置
        topMostNode->getEventDispatcher()->dispatchEvent(&customEvent);
    }
    
    topMostNode->removeFromParent();
    /*removingTopMostNode = true;*/
    //this->removeChild(menu);
 /*   menu->removeFromParentAndCleanup(true);*/
    Sprite* towerBase;
    auto newChild=TowerManager::addTower(type, pos, towerBase);
    int price;
    switch (type) {
    case BOTTLE:
        price = BOTTLE_PRICE;
        break;
    case STAR:
        price = STAR_PRICE;
        break;
    case SHIT:
        price = SHIT_PRICE;
        break;
    }
    (gameManager->getProperty()).towerBuild(price);
    this->addChild(towerBase);
    this->addChild(newChild,40);
    
}

void MapPurple::setShuzu()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            isSet[i][j] = BlockType(2);//NO_TOWER
        }
    }
    for (int i = 1; i < 10; i++) {
        isSet[1][10 - i] = BlockType(0);//ROAD
        Vec2 position (origin.x+1*BLOCK_SIZE +BLOCK_SIZE/2, origin.y+10 * BLOCK_SIZE+ BLOCK_SIZE/2 - i * BLOCK_SIZE);
        path.push_back(position);
    }
    for (int i = 0; i < 4; i++) {
        isSet[2 + i][1] = BlockType(0);
        Vec2 position(origin.x + (2+i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + 1 * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 4; i++) {
        isSet[5][2 + i] = BlockType(0);
        Vec2 position(origin.x + (5) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (2+i) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 4; i++) {
        isSet[6 + i][5] = BlockType(0);
        Vec2 position(origin.x + (6 + i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + 5 * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 3; i++) {
        isSet[9][4 - i] = BlockType(0);
        Vec2 position(origin.x + (9) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (4-i) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 7; i++) {
        isSet[10 + i][2] = BlockType(0);
        Vec2 position(origin.x + (10 + i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + 2 * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 4; i++) {
        isSet[16][3 + i] = BlockType(0);
        Vec2 position(origin.x + (16) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (3+i) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    isSet[2][8] = BlockType(3);//BARRIER
    isSet[0][5] = BlockType(3);
    isSet[2][2] = BlockType(3);
    isSet[5][6] = BlockType(3);
    isSet[8][3] = BlockType(3);
    isSet[13][3] = BlockType(3);
    isSet[14][6] = BlockType(3);
}

void MapPurple::setSingle(BlockType type, int i, int j)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto newBlock = new SceneBlock;
    newBlock->init(type);
    newBlock->setPos(Vec2(origin.x + BLOCK_SIZE * i + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2));
    newBlock->getBlock()->setPosition(origin.x + BLOCK_SIZE * i + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2);
    this->addChild(newBlock->getBlock(),1);
    purpleBlock.pushBack(newBlock);
    if (type == ROAD) {
        purpleRoad.pushBack(newBlock);
    }
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
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            if (isSet[i][j] == BARRIER) {
                auto pbarrier = new BarrierBase;
                Vec2 _pos(origin.x+i * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y+j * BLOCK_SIZE + BLOCK_SIZE / 2);
                pbarrier->create(_pos);
                /*pbarrier->addChild(pbarrier->myHp);*/
                gameManager->getBarrierVec()->addBarrier(pbarrier, BALL_ONE);
                this->addChild(pbarrier->getBarrier(),2);
            }
        }
    }
}
void MapPurple::setBlock(Vec2 position, BlockType type)
{
    for (auto currentBlock : purpleBlock)
        if (currentBlock->getPos() == position)
            currentBlock->set_label(type);
}