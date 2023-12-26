
#include"SoundUtil.h"
#include "SimpleAudioEngine.h"

static SoundUtil* getInstance()
{

}

void SoundUtil::playBackgroundSound(const std::string& bgm)
{
    if (!isBackgroundSound) return;

    if (bgm == BACKGROUNDSOUND && isSoundMainBackgroundMusic) 
        return;
    else
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(bgm.c_str(), true);
        if (bgm == BACKGROUNDSOUND) 
            isSoundMainBackgroundMusic = true;
        else isSoundMainBackgroundMusic = false;
    }

}

void SoundUtil::playEffect(const std::string& effectSound)
{
    if (!isEffectSound) 
        return;

    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(effectSound.c_str());
}

void SoundUtil::setIsBackGroundSound(const bool& isSound)
{
    isBackgroundSound = isSound;
    isSoundMainBackgroundMusic = !isSound;
    isBackgroundSound ? playBackgroundSound(BACKGROUNDSOUND) : stopBackGroundSound();
}

void SoundUtil::stopBackGroundSound()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

SoundUtil::SoundUtil() :isEffectSound(true)
{

}

SoundUtil::~SoundUtil()
{

}