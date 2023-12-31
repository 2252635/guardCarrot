#pragma once
#ifndef _CARROT_MAP_BLUE_
#define _CARROT_MAP_BLUE_
#include "GameManager.h"
#include "GameScene.h"
#include <vector>

class MapBlue :public Layer
{
private:
    void set();
    void setShuzu();
    void setSingle(BlockType type, int i, int j);
    BlockType isSet[MAP_ROW][MAP_COL];
    Vec2 mousePosition;
    GameManager* gameManager;
    int count = MONSTERMAX;
    int leftcount = MONSTERMAX;

    static const int kTowerSelectMenuTag = 10;
    bool removingTopMostNode = false;
    Menu* menu;
    int isEnd = -1;
    void checkVariableChange(float dt);
    cocos2d::Scheduler* scheduler;
public:
    static Scene* createScene();

    virtual bool init();
    Vector<SceneBlock*>purpleBlock;
    Vector<SceneBlock*>purpleRoad;
    std::vector<Vec2>path;

    void setBarrier();
    void setBlock(Vec2 position, BlockType type);

    CREATE_FUNC(MapBlue);

    /*void showTowerSelectMenu(const Vec2& position, std::string& bottleTower, std::string& starTower, std::string& shitTower);*/
    void onTowerSelected(Ref* sender, TowerType type, Vec2 pos, bool flag);
    void onTowerDestroySelected(Ref* sender, TowerBase* targetTower, bool option, Vec2 targetPos);
    void onCarrotSelected(Ref* sender, Vec2 pos);
    void game();
};
//给地图设置布局
    /*
      0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0 0 0 * 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0 0 1 * 0 0 0 0 0
      0 0 0 1 * * * 0 0 0 0 0 * 0 0 0 0 0
      0 0 0 0 * 1 * 0 0 0 0 0 * 1 1 0 0 0
      0 0 0 0 * 0 * 0 0 0 0 0 * 1 1 0 0 0
      0 0 * * * 0 * 1 1 0 0 0 * 0 0 0 0 0
      0 0 0 0 0 0 * 1 1 0 0 0 * 0 0 0 0 0
      0 0 0 0 0 0 * * * * * * * 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0*/


#endif