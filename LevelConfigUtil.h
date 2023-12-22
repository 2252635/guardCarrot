#pragma once
#ifndef _LEVEL_CONFIG_UTIL_
#define _LEVEL_CONFIG_UTIL_

#include "PublicDefine.h"

class LevelConfigUtil :public Ref
{
public:

    CREATE_INSTANCE_FUNC(LevelConfigUtil);

    DESTROY_INSTANCE_FUNC();

    virtual void LoadLevelConfig();

    virtual std::tuple<int, int, int, std::vector<std::string>> GetLevelConfig()const;

    virtual std::vector<std::string> GetCurLevelTowersInfo()const;

    virtual int GetCurLevelMonsterBatchCount()const;

    virtual void BuildLevelConfig();

    virtual int GetCurLevelMoney()const;

protected:

    virtual bool Initiate();

protected:

    int CurPageIndex = 0;

    int CurLevelIndex = 0;

    int CurLevelMoney = 0;

    int MonsterBatchCount = 0;

    std::vector<std::string>* EffectTowers = nullptr;

private:

    LevelConfigUtil();

    virtual ~LevelConfigUtil();

    LevelConfigUtil(const LevelConfigUtil&) = delete;

    LevelConfigUtil& operator=(const LevelConfigUtil&) = delete;
};
#endif
