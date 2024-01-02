#pragma once
#ifndef _CARROT_MAP_PURPLE_
#define _CARROT_MAP_PURPLE_
#include "GameManager.h"
#include <vector>

class MapPurple :public Layer
{
private:
    void set();
    void setShuzu();
    void setSingle(BlockType type, int i, int j);
    BlockType isSet[MAP_ROW][MAP_COL];
    Vec2 mousePosition;
    GameManager* gameManager;
    int count = MONSTERMAX;


    static const int kTowerSelectMenuTag = 10;
    bool removingTopMostNode = false;
    Menu* menu;
public:
    static Scene* createScene();

    virtual bool init();
    Vector<SceneBlock*>purpleBlock;
    Vector<SceneBlock*>purpleRoad;
    std::vector<Vec2>path;

    void setBarrier();
    void setBlock(Vec2 position,BlockType type);

    CREATE_FUNC(MapPurple);

    /*void showTowerSelectMenu(const Vec2& position, std::string& bottleTower, std::string& starTower, std::string& shitTower);*/
    void onTowerSelected(Ref* sender, TowerType type, Vec2 pos);
    void onTowerDestroySelected(Ref* sender, TowerBase*targetTower,bool option);
};

#endif

