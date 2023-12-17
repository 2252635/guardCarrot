#pragma once
#ifndef _PUBLIC_DEFINE_
#define _PUBLIC_DEFINE_

#define PHOTOPOSTFIX .png
//#define TOWER_VECTOR std::vector<Tower*>
using TowerVec = std::vector<Tower*>;

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

#define CREATE_INSTANCE_FUNC(CLASS) \
private:\
    static CLASS *Instance;\
public:\
static CLASS* GetInstance()\
{\
    if(!Instance)\
    {\
        Instance = new CLASS();\
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
#define NOTIFY cocos2d::NotificationCenter::getInstance()

#endif _PUBLIC_DEFINE
