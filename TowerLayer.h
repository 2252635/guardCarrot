#pragma once
#ifndef _TOWER_LAYER_
#define _TOWER_LAYER_
#include"EntityLayerBase.h"
class TowerLayer :public EntityLayerBase
{
public:

    CREATE_FUNC(TowerLayer);

protected:
    virtual void CheckTowerGrade(float Delta);
    virtual bool Initiate();


};
#endif _TOWER_LAYER_
