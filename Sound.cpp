#include "Sound.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager::AudioManager() {
    preloadSounds();
}

AudioManager* AudioManager::getInstance() {
    if (!instance) {
        instance = new AudioManager();
    }
    return instance;
}

void AudioManager::preloadSounds() {
    SimpleAudioEngine::getInstance()->preloadEffect("musics/attack.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("musics/TowerBuild.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("musics/kill.mp3");
}

void AudioManager::playAttackSound() {
    SimpleAudioEngine::getInstance()->playEffect("musics/attack.mp3");
}

void AudioManager::playBuildSound() {
    SimpleAudioEngine::getInstance()->playEffect("musics/TowerBuild.mp3");
}

void AudioManager::playKillSound() {
    SimpleAudioEngine::getInstance()->playEffect("musics/kill.mp3");
}
