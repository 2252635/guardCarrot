#include "MapBlue.h"
#include "PublicSourceDefine.h"
using namespace std;

Scene* MapBlue::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MapBlue::create();

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

bool MapBlue::init()
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
    auto background = Sprite::create("pictures/scenes/BackgroundBlue.png");
    background->setScale(2.5);
    if (background == nullptr)
    {
        problemLoading("'BackgroundBlue.png'");
    }
    else
    {
        background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(background, BACKGROUND_LAYER);
    }

    /*this->addChild(gameManager->getProperty().getMoneyLabel(), 100);*/
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
                    bool bottleFlag, starFlag, shitFlag;
                    std::string bottleImage, starImage, shitImage;
                    if (gameManager->getMoney() > BOTTLE_PRICE) {
                        bottleImage = BOTTLECANBUY;
                        bottleFlag = 1;
                    }
                    else {
                        bottleImage = BOTTLECANNOTBUY;
                        bottleFlag = 0;
                    }
                    if (gameManager->getMoney() > STAR_PRICE) {
                        starImage = STARCANBUY;
                        starFlag = 1;
                    }
                    else {
                        starImage = STARCANNOTBUY;
                        starFlag = 0;
                    }
                    if (gameManager->getMoney() > SHIT_PRICE) {
                        shitImage = SHITCANBUY;
                        shitFlag = 1;
                    }
                    else {
                        shitImage = SHITCANNOTBUY;
                        shitFlag = 0;
                    }
                    auto towerOption1 = MenuItemImage::create(bottleImage + PHOTOPOSTFIX, bottleImage + PHOTOPOSTFIX, CC_CALLBACK_1(MapBlue::onTowerSelected, this, TowerType::BOTTLE, targetPos, bottleFlag));
                    auto towerOption2 = MenuItemImage::create(starImage + PHOTOPOSTFIX, starImage + PHOTOPOSTFIX, CC_CALLBACK_1(MapBlue::onTowerSelected, this, TowerType::STAR, targetPos, starFlag));
                    auto towerOption3 = MenuItemImage::create(shitImage + PHOTOPOSTFIX, shitImage + PHOTOPOSTFIX, CC_CALLBACK_1(MapBlue::onTowerSelected, this, TowerType::SHIT, targetPos, shitFlag));
                    removingTopMostNode = true;
                    menu->addChild(towerOption1);
                    menu->addChild(towerOption2);
                    menu->addChild(towerOption3);
                    menu->alignItemsHorizontally();
                    // 设置菜单的位置和标签
                    menu->setPosition(Vec2(targetPos.x, targetPos.y + 50));
                    menu->setTag(kTowerSelectMenuTag);

                    auto cancelOption = MenuItemImage::create(
                        CANCELBUTTONNORMAL,
                        CANCELBUTTONSELECTED,
                        [=](Ref* sender) {
                            // 移除菜单
                            Node* topMostNode = this->getChildByTag(kTowerSelectMenuTag);

                            topMostNode->removeFromParent();
                        }
                    );

                    // 设置取消选项的位置（可根据需要调整）
                    cancelOption->setPosition(Vec2(0, -50));
                    // ... 添加其他防御塔选项 ...
                    menu->addChild(cancelOption);

                    // 设置菜单的位置和标签
                    menu->setTag(kTowerSelectMenuTag);
                    this->addChild(menu, MENU_LAYER);
                }
                else if (label == TOWER) {
                    auto towerVec = gameManager->getTowerManager()->getVec();
                    TowerBase* targetTower;
                    for (auto currentTower : towerVec)
                        if (currentTower->getPos() == targetPos) {
                            targetTower = currentTower;
                            break;
                        }
                    menu = Menu::create();
                std:string towerImage;
                    TowerType targetType = targetTower->getType();
                    std::string upGradeImage = gameManager->getMoney() > targetTower->getUpCost() ? "pictures/items/carrotup.png" : "pictures/items/carrotupfalse.png";//towerImage + std::to_string((targetTower->getGrade()+1)%4) + PHOTOPOSTFIX;
                    if (targetTower->getGrade() >= TOWER_MAX_GRADE)
                        upGradeImage = "pictures/items/carrotupfalse.png";
                    auto towerOption1 = MenuItemImage::create(upGradeImage, upGradeImage, CC_CALLBACK_1(MapBlue::onTowerDestroySelected, this, targetTower, 1, targetPos));
                    auto towerOption2 = MenuItemImage::create(TOWERDEADBUTTON, TOWERDEADBUTTON, CC_CALLBACK_1(MapBlue::onTowerDestroySelected, this, targetTower, 0, targetPos));

                    removingTopMostNode = true;
                    menu->addChild(towerOption1);
                    menu->addChild(towerOption2);
                    menu->alignItemsHorizontally();
                    // 设置菜单的位置和标签
                    menu->setPosition(Vec2(targetPos.x, targetPos.y + 50));
                    menu->setTag(kTowerSelectMenuTag);

                    auto cancelOption = MenuItemImage::create(
                        CANCELBUTTONNORMAL,
                        CANCELBUTTONSELECTED,
                        [=](Ref* sender) {
                            // 移除菜单
                            Node* topMostNode = this->getChildByTag(kTowerSelectMenuTag);

                            topMostNode->removeFromParent();
                        }
                    );

                    // 设置取消选项的位置（可根据需要调整）
                    cancelOption->setPosition(Vec2(0, -50));
                    // ... 添加其他防御塔选项 ...
                    menu->addChild(cancelOption);

                    // 设置菜单的位置和标签
                    menu->setTag(kTowerSelectMenuTag);

                    this->addChild(menu, MENU_LAYER);
                }
                else if (label == CARROT) {

                    menu = Menu::create();

                    std::string upImage = (gameManager->getMoney() > CARROT_PRICE) ? "pictures/items/carrotup.png" : "pictures/items/carrotupfalse.png";
                    if (gameManager->getCarrot()->getLevel() >= CARROT_MAX_LEVEL)
                        upImage = "pictures/items/carrotupfalse.png";
                    auto carrotOption = MenuItemImage::create(upImage, upImage, CC_CALLBACK_1(MapBlue::onCarrotSelected, this, targetPos));

                    removingTopMostNode = true;
                    menu->addChild(carrotOption);
                    menu->alignItemsHorizontally();
                    // 设置菜单的位置和标签
                    menu->setPosition(Vec2(targetPos.x, targetPos.y + 20));
                    menu->setTag(kTowerSelectMenuTag);

                    auto cancelOption = MenuItemImage::create(
                        CANCELBUTTONNORMAL,
                        CANCELBUTTONSELECTED,
                        [=](Ref* sender) {
                            // 移除菜单
                            Node* topMostNode = this->getChildByTag(kTowerSelectMenuTag);

                            topMostNode->removeFromParent();
                        }
                    );
                    cancelOption->setPosition(Vec2(0, -50));
                    // ... 添加其他防御塔选项 ...
                    menu->addChild(cancelOption);

                    // 设置菜单的位置和标签
                    menu->setTag(kTowerSelectMenuTag);
                    this->addChild(menu, MENU_LAYER);
                }
                else if (label == BARRIER) {
                    for (auto currentBarrier : gameManager->getBarrierVec()->getVec())
                        if ((currentBarrier->getBarrier() != nullptr) && targetPos.x >= (currentBarrier->getBarrier()->getPosition().x - BLOCK_SIZE / 2) && targetPos.x <= (currentBarrier->getBarrier()->getPosition().x + BLOCK_SIZE / 2)
                            && targetPos.y >= (currentBarrier->getBarrier()->getPosition().y - BLOCK_SIZE / 2) && targetPos.y <= (currentBarrier->getBarrier()->getPosition().y + BLOCK_SIZE / 2))
                        {
                            if (gameManager->checkTarget()) {
                                gameManager->getBTarget()->unsetVictim();
                                gameManager->getMTarget()->unsetVictim();
                            }
                            currentBarrier->setVictim(targetPos);
                            gameManager->setBTarget(currentBarrier);
                            gameManager->getTowerManager()->setTarget(gameManager->getBTarget());
                        }
                }
                else if (label == ROAD) {
                    for (auto currentMonster : gameManager->getMonsterVec()->getVec())
                        if ((currentMonster->getMonster() != nullptr) && targetPos.x >= (currentMonster->getMonster()->getPosition().x - BLOCK_SIZE / 2) && targetPos.x <= (currentMonster->getMonster()->getPosition().x + BLOCK_SIZE / 2)
                            && targetPos.y >= (currentMonster->getMonster()->getPosition().y - BLOCK_SIZE / 2) && targetPos.y <= (currentMonster->getMonster()->getPosition().y + BLOCK_SIZE / 2)) {
                            if (gameManager->checkTarget()) {
                                gameManager->getBTarget()->unsetVictim();
                                gameManager->getMTarget()->unsetVictim();
                            }
                            currentMonster->setVictim(targetPos);
                            gameManager->setMTarget(currentMonster);
                            gameManager->getTowerManager()->setTarget(gameManager->getMTarget());
                        }
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
    this->addChild((gameManager->getCarrot())->getCarrotSprite(), MONSTER_LAYER);

    std::function<void(float)> Addmonster = [this](float)
    {
        auto monster = new MonsterBase;
        monster->create(path[0]);
        monster->startPosition = path[0];
        monster->getMonster()->setPosition(path[0]);
        this->addChild(monster->getMonster(), MONSTER_LAYER);
        (gameManager->getMonsterVec()->getVec()).pushBack(monster);
        monster->monsterMove(path, NORMAL);

        count--;
        if (count == 0)
            this->unschedule("Addmonster");
    };
    this->schedule(Addmonster, 1.0f, "Addmonster");

    cocos2d::Scheduler* scheduler = getScheduler();
    schedule(CC_SCHEDULE_SELECTOR(MapBlue::checkVariableChange, "update", 0.1f, -1, 0));
    this->removeChild(gameManager->getProperty().getMoneyLabel());
    return true;
}

void MapBlue::checkVariableChange(float dt)
{
    game();
    if (isEnd == 1) {
        auto Scene = SceneFactory::createScene(END_WIN);
        Director::getInstance()->replaceScene(Scene);
    }
    else if (isEnd == 0) {
        auto Scene = SceneFactory::createScene(END_LOSE);
        Director::getInstance()->replaceScene(Scene);
    }
}

void MapBlue::onTowerDestroySelected(Ref* sender, TowerBase* targetTower, bool option, Vec2 pos)
{

    Node* topMostNode = this->getChildByTag(kTowerSelectMenuTag);

    if (topMostNode) {
        EventCustom customEvent("onTopMostNodeClicked");
        customEvent.setUserData(&pos); // 传递点击位置
        topMostNode->getEventDispatcher()->dispatchEvent(&customEvent);
    }

    topMostNode->removeFromParent();
    if (option) {
        if (targetTower->upGrade(gameManager->getMoney()))
            gameManager->getProperty().towerBuild(targetTower->getUpCost());
    }
    else {
        gameManager->getProperty().towerDead(targetTower->getPrice());
        targetTower->cleanUp();
        setBlock(pos, NO_TOWER);
        gameManager->getTowerManager()->destroyTower(targetTower);
    }
}

void MapBlue::onTowerSelected(Ref* sender, TowerType type, Vec2 pos, bool flag) {
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
    if (flag) {
        Sprite* towerBase;
        auto newChild = TowerManager::addTower(type, pos, towerBase);
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
        this->addChild(towerBase, TOWER_BASE_LAYER);
        this->addChild(newChild, TOWER_PANEL_LAYER);
        setBlock(pos, TOWER);
    }
}

void MapBlue::onCarrotSelected(Ref* sender, Vec2 pos) {
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
    //int price = CARROT_PRICE;
    ////
    gameManager->getCarrot()->levelUp();

}


void MapBlue::setShuzu()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            isSet[i][j] = BlockType(2);//NO_TOWER
        }
    }
    for (int i = 0; i < 13; i++) {
        isSet[1+i][10] = BlockType(0);//ROAD
        Vec2 position(origin.x + (1 + i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + 10 * BLOCK_SIZE + BLOCK_SIZE / 2 );
        path.push_back(position);
    }
    for (int i = 0; i < 2; i++) {
        isSet[13][9-i] = BlockType(0);
        Vec2 position(origin.x + (13) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (9 - i) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i < 12; i++) {
        isSet[12-i][8] = BlockType(0);
        Vec2 position(origin.x + (12 - i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (8) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i <5; i++) {
        isSet[1][7-i] = BlockType(0);
        Vec2 position(origin.x + BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (7 - i) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
    for (int i = 0; i <3; i++) {
        isSet[2+i][3] = BlockType(0);
        Vec2 position(origin.x + (2 + i) * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + (3) * BLOCK_SIZE + BLOCK_SIZE / 2);
        path.push_back(position);
    }
   
    isSet[4][3] = BlockType(4);

    isSet[4][9] = BlockType(3);//BARRIER
    isSet[7][9] = BlockType(3);
    isSet[2][6] = BlockType(3);
    isSet[2][4] = BlockType(3);
    isSet[6][2] = BlockType(3);
    isSet[6][7] = BlockType(3);

}

void MapBlue::setSingle(BlockType type, int i, int j)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto newBlock = new SceneBlock;
    newBlock->init(type, 1);
    newBlock->setPos(Vec2(origin.x + BLOCK_SIZE * i + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2));
    newBlock->getBlock()->setPosition(origin.x + BLOCK_SIZE * i + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2);
    this->addChild(newBlock->getBlock(), BLOCK_LAYER);
    purpleBlock.pushBack(newBlock);
    if (type == ROAD) {
        purpleRoad.pushBack(newBlock);
    }
}

void MapBlue::set()
{
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            setSingle(isSet[i][j], i, j);
        }
    }

}

void MapBlue::setBarrier()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    for (int i = 0; i < MAP_ROW; i++) {
        for (int j = 0; j < MAP_COL; j++) {
            if (isSet[i][j] == BARRIER) {
                auto pbarrier = new BarrierBase;
                Vec2 _pos(origin.x + i * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + j * BLOCK_SIZE + BLOCK_SIZE / 2);
                pbarrier->create(_pos);
                /*pbarrier->addChild(pbarrier->myHp);*/
                gameManager->getBarrierVec()->addBarrier(pbarrier, BALL_ONE);
                this->addChild(pbarrier->getBarrier(), BARRIER_LAYER);
            }
        }
    }
}
void MapBlue::setBlock(Vec2 position, BlockType type)
{
    for (auto currentBlock : purpleBlock)
        if (currentBlock->getPos() == position)
            currentBlock->set_label(type);
}

void MapBlue::game()
{
    auto& vec = gameManager->getMonsterVec()->getVec();
    int left = leftcount;

    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    const float epsilon = 10; // 可以根据实际情况调整

    Vec2 targetPosition(origin.x + 4 * BLOCK_SIZE + BLOCK_SIZE / 2, origin.y + 3 * BLOCK_SIZE + BLOCK_SIZE / 2);

    for (auto currentmonster : vec) {
        if (currentmonster->getMonster()) {
            Vec2 monsterPosition(currentmonster->getMonster()->getPosition());

            if (std::abs(monsterPosition.x - targetPosition.x) < epsilon &&
                std::abs(monsterPosition.y - targetPosition.y) < epsilon) {
                // 怪物到达目标位置
                gameManager->hurtCarrot();
                currentmonster->whenHurt(1000, 0);
                if (gameManager->getCarrot()->IsDead()) {
                    isEnd = 0;
                }
            }
        }
        else {
            left--;
            if (!left) {
                isEnd = 1;
            }
        }
    }
}
