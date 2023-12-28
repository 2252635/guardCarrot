#include"GameManager.h"

void GameManager::judge(const Vector<SceneBlock*>& block, const Vec2 pos)
{
    for (auto currentBlock : block) {
        if (pos.x >= (currentBlock->getPos().x - BLOCK_SIZE / 2) && pos.x <= (currentBlock->getPos().x + BLOCK_SIZE / 2)
            && pos.y >= (currentBlock->getPos().y - BLOCK_SIZE / 2) && pos.y >= (currentBlock->getPos().y + BLOCK_SIZE / 2))
            switch (currentBlock->getLabel()) {
                case TOWER:
                    for (auto currentTower : towerManager->getVec())
                        if (pos.x >= (currentTower->getPos().x - BLOCK_SIZE / 2) && pos.x <= (currentTower->getPos().x + BLOCK_SIZE / 2)
                            && pos.y >= (currentTower->getPos().y - BLOCK_SIZE / 2) && pos.y >= (currentTower->getPos().y + BLOCK_SIZE / 2))
                            currentTower->upGrade(property.getMoney());//¸øËþ½øÐÐÉý¼¶
                    break;
                case NO_TOWER:
                {std::string bottleImage, starImage, shitImage;
                if (property.getMoney() >= BOTTLE_PRICE)
                    bottleImage = "Æ¿×ÓËþ¿É¹ºÂòÍ¼Æ¬";
                else
                    bottleImage = "Æ¿×ÓËþ²»¿É¹ºÂòÍ¼Æ¬";
                if (property.getMoney() >= STAR_PRICE)
                    starImage = "ÐÇÐÇËþ¿É¹ºÂòÍ¼Æ¬";
                else
                    starImage = "ÐÇÐÇËþ²»¿É¹ºÂòÍ¼Æ¬";
                if (property.getMoney() >= SHIT_PRICE)
                    shitImage = "shiËþ¿É¹ºÂòÍ¼Æ¬";
                else
                    shitImage = "shiËþ²»¿É¹ºÂòÍ¼Æ¬";
                towerMenu->showTowerSelectMenu(pos, bottleImage, starImage, shitImage);
                break;
                }
                case BARRIER:
                default:
                    break;
            }
}

bool GameManager::checkTarget()
{
    if (!barrierManager->checkTarget() && !monsterManager->checkTarget())
        return false;
    else return true;
}

void GameManager::produceMonster(const Vector<SceneBlock*>& road)
{
    Vec2 position;
    position = (road.front())->getPos();
    auto monster = new MonsterBase;
    monster->startPosition = position;
    monsterManager->monsterVecMove(monster);

}

bool GameManager::gameEnd()
{
    if (carrot->IsDead())
        return false;
    if (!monsterManager->deadAction())
        return true;
}

void GameManager::gameStart(const Vector<SceneBlock*>& road)
{
    Vec2 position = road.front()->getPosition();
    carrot->create(position);
}