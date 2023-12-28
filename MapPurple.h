/*#pragma once
#include "PublicDefine.h"
#include "SceneBlock.h"
#include "GameManager.h"

class MapPurple :public Layer
{
private:
    void set();

    void setShuzu();

    void setSingle(BlockType type, int i, int j);

    BlockType isSet[MAP_ROW][MAP_COL];

    Vec2 mousePosition;

    GameManager* gameManager;

public:
    static Scene* createScene();

    virtual bool init();

    Vector<SceneBlock*>purpleBlock;

    void setBarrier();

    CREATE_FUNC(MapPurple);

};
*/

