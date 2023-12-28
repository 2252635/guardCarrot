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
                            currentTower->upGrade(property.getMoney());//������������
                    break;
                case NO_TOWER:
                {std::string bottleImage, starImage, shitImage;
                if (property.getMoney() >= BOTTLE_PRICE)
                    bottleImage = "ƿ�����ɹ���ͼƬ";
                else
                    bottleImage = "ƿ�������ɹ���ͼƬ";
                if (property.getMoney() >= STAR_PRICE)
                    starImage = "�������ɹ���ͼƬ";
                else
                    starImage = "���������ɹ���ͼƬ";
                if (property.getMoney() >= SHIT_PRICE)
                    shitImage = "shi���ɹ���ͼƬ";
                else
                    shitImage = "shi�����ɹ���ͼƬ";
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