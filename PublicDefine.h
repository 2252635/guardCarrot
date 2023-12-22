#pragma once
#ifndef _PUBLIC_DEFINE_
#define _PUBLIC_DEFINE_

#include "cocos2d.h"
#include "VisibleRect.h"
#include "PublicSourceDefine.h"
#include "CsvUtil.h"
#include <tuple>
#include <vector>

const static std::string PHOTOPOSTFIX = ".png";
const static std::string PLISTPOSTFIX = ".plist";

//#define TOWER_VECTOR std::vector<Tower*>
using TowerVec = Vector<Tower*>;
using BarrierVec = Vector<BarrierBase*>;



enum CsvPublicProperty
{
    NAME = 1,
    MODELNAME,
    VALUE,
    ANIMATION_COUNT,
    GRADE
};

enum CsvTowerProperty
{
    RANGE = 6,
    SPACE,
    BULLET_ID,
    UP_COST,
    TOWER_BASE,
    IS_ROTATE,
    CREATE_COST
};
enum TowerType
{
    STAR_TOWER,
    PIN_TOWER,
    ROCKET_TOWER
};
enum BarrierType
{
    BALLON,
    CLOUD,
    STONE,
    TREE
};
class AttackProperty
{
public:
    int AttackState = 0;
    int Duration = 0;
    int Attack = 0;
    int BulletType = 0;
};

#define CREATE_INSTANCE_FUNC(__CLASS__) \
private:\
    static __CLASS__ *Instance;\
public:\
static __CLASS__* getInstance()\
{\
    if(!Instance)\
    {\
        Instance = new __CLASS__();\
        if(Instance && Instance->Initiate())\
        {\
            Instance->autorelease();\
            Instance->retain();\
        }\
        else\
        {\
            CC_SAFE_DELETE(Instance);\
        }\
    }\
    return Instance;\
}
#define DESTROY_INSTANCE_FUNC()\
static void DestroyInstance()\
{\
    CC_SAFE_RELEASE_NULL(Instance);\
}
#define NOTIFY cocos2d::NotificationCenter::getInstance()//观察者中心

#endif _PUBLIC_DEFINE
