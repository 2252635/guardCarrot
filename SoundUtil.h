#pragma once
#ifndef _CARROT_SOUND_UTIL_
#define _CARROT_SOUND_UTIL_
#include"PublicDefine.h"
class SoundUtil : public Ref
{
public:

    
    static SoundUtil* getInstance();
    void playBackgroundSound(const std::string& bgm);
    void playEffect(const std::string& effectSound);
    void setIsBackGroundSound(const bool& isSound);
    bool getIsBackGroundSound()const { return isBackgroundSound; }
    void stopBackGroundSound();

protected:
    virtual bool init() { return true; }

protected:

    bool isBackgroundSound = true;
    bool isSoundMainBackgroundMusic = false;
    CC_SYNTHESIZE_PASS_BY_REF(bool,isEffectSound, IsEffectSound);

private:

    SoundUtil();
    virtual ~SoundUtil();
    SoundUtil(const SoundUtil&) = delete;
    SoundUtil& operator=(const SoundUtil&) = delete;

};
#endif