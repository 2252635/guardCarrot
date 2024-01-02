#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class AudioManager {
public:
    static AudioManager* getInstance();

    // ���Ź�����Ч
    void playAttackSound();

    // ���Ž�����Ч
    void playBuildSound();

    // ���Ż�ɱ��Ч
    void playKillSound();

    // ֹͣ������Ч
    void stopAllSounds();

    static AudioManager* instance;

private:
    AudioManager();  
    void preloadSounds();
};

#endif