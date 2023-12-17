#pragma once
#ifndef _SOUND_UTIL_
#define _SOUND_UTIL_
#include"PublicDefine.h"
class SoundUtil :public Ref
{
public:

    CREATE_INSTANCE_FUNC(SoundUtil);

    DESTROY_INSTANCE_FUNC();

    void PlayBackgroundSound(const std::string& BgSound);//���ű�������
    void PlayEffect(const std::string& EffectSound);//������Ч
    void SetIsBackgroundSound(const bool& IsSound);//ȷ���Ƿ��Ǳ�������
    bool GetIsBackgroundSound()const { return IsBackgroundSound; }//��ȡ�Ƿ��Ǳ�������
    void StopBackgroundSound();//ֹͣ���ű�������

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

