#include"GameManager.h"

bool GameManager::init()
{
	monsterManager = new MonsterManager;
	monsterManager->init();
	barrierManager = new BarrierManager;
	barrierManager->init();
	carrot = new Carrot;
	property.init();
	towerManager = new TowerManager;
	/*towerMenu = new TowerMenu;*/
	/*towerMenu->init();*/
	return true;
}

BlockType GameManager::judge(Vector<SceneBlock*>& block, const Vec2 pos,Vec2&targetPos)
{
	BlockType label=NO_TOWER;
	for (auto currentBlock : block) {

		if (pos.x >= (currentBlock->getPos().x - BLOCK_SIZE / 2) && pos.x <= (currentBlock->getPos().x + BLOCK_SIZE / 2)
			&& pos.y >= (currentBlock->getPos().y - BLOCK_SIZE / 2) && pos.y <= (currentBlock->getPos().y + BLOCK_SIZE / 2)) {
			targetPos.x = currentBlock->getPos().x;
			targetPos.y = currentBlock->getPos().y;
			label = static_cast<BlockType>(currentBlock->get_label());
				switch (label) {
				//case TOWER:
				//{
				//	for (auto currentTower : towerManager->getVec())
				//		if (pos.x >= (currentTower->getPos().x - BLOCK_SIZE / 2) && pos.x <= (currentTower->getPos().x + BLOCK_SIZE / 2)
				//			&& pos.y >= (currentTower->getPos().y - BLOCK_SIZE / 2) && pos.y <= (currentTower->getPos().y + BLOCK_SIZE / 2))
				//			//currentTower->upGrade();//给塔进行升级
				//			;
				//}
				//	break;
				case BARRIER:
				{
					for (auto currentBarrier : barrierManager->getVec())
						if (pos.x >= (currentBarrier->getPosition().x - BLOCK_SIZE / 2) && pos.x <= (currentBarrier->getPosition().x + BLOCK_SIZE / 2)
							&& pos.y >= (currentBarrier->getPosition().y - BLOCK_SIZE / 2) && pos.y >= (currentBarrier->getPosition().y + BLOCK_SIZE / 2))
						{
							if (checkTarget()) {
								nowBTarget->unsetVictim();
								nowMTarget->unsetVictim();
							}
							currentBarrier->setVictim(pos);
							nowBTarget = currentBarrier;
						}
				}
					break;
				case ROAD:
				{
					for (auto currentMonster : monsterManager->getVec())
						if (pos.x >= (currentMonster->getPosition().x - BLOCK_SIZE / 2) && pos.x <= (currentMonster->getPosition().x + BLOCK_SIZE / 2)
							&& pos.y >= (currentMonster->getPosition().y - BLOCK_SIZE / 2) && pos.y >= (currentMonster->getPosition().y + BLOCK_SIZE / 2) && !checkTarget()) {
							if (checkTarget()) {
								nowBTarget->unsetVictim();
								nowMTarget->unsetVictim();
							}
							currentMonster->setVictim(pos);
							nowMTarget = currentMonster;
						}
				}
					break;
				default:
					break;
				}
				break;
		}
	}
	return label;
}

bool GameManager::checkTarget()
{
	if (!barrierManager->checkTarget() && !monsterManager->checkTarget())
		return false;
	else return true;
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