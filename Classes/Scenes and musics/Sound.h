#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class AudioManager {
public:
    static AudioManager* getInstance();

    // 播放攻击音效
    void playAttackSound();

    // 播放建造音效
    void playBuildSound();

    // 播放击杀音效
    void playKillSound();

    // 停止所有音效
    void stopAllSounds();

    static AudioManager* instance;

private:
    AudioManager();  
    void preloadSounds();
};

#endif