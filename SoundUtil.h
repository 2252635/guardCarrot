#pragma once
#ifndef _SOUND_UTIL_
#define _SOUND_UTIL_
#include"PublicDefine.h"
class SoundUtil :public Ref
{
public:

    CREATE_INSTANCE_FUNC(SoundUtil);

    DESTROY_INSTANCE_FUNC();

    void PlayBackgroundSound(const std::string& BgSound);//≤•∑≈±≥æ∞“Ù¿÷
    void PlayEffect(const std::string& EffectSound);//≤•∑≈“Ù–ß
    void SetIsBackgroundSound(const bool& IsSound);//»∑»œ «∑Ò «±≥æ∞“Ù¿÷
    bool GetIsBackgroundSound()const { return IsBackgroundSound; }//ªÒ»° «∑Ò «±≥æ∞“Ù¿÷
    void StopBackgroundSound();//Õ£÷π≤•∑≈±≥æ∞“Ù¿÷

protected:

    virtual bool Initiate() { return true; }


    bool IsBackgroundSound = true;
    bool IsSoundMainBackgroundMusic = false;

    CC_SYNTHESIZE_PASS_BY_REF(bool, IsEffectSound, IsEffectSound);

private:

    SoundUtil();

    virtual ~SoundUtil();

    SoundUtil(const SoundUtil&) = delete;

    SoundUtil& operator=(const SoundUtil&) = delete;
};
#endif

