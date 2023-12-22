#pragma once
#ifndef _BARRIER_LAYER_
#define _BARRIER_LAYER_
class BarrierLayer :public EtityLayerBase
{
public:
    CREATE_FUNC(BarrierLayer);

protected:
    virtual bool Initiate();
};
#endif
