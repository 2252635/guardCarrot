#include "BarrierLayer.h"

bool BarrierLayer::Initiate()
{
    bool Ret = false;
    do {
        CC_BREAK_IF(!EntityLayerBase::Init());
        Ret = true;
    } while (0);

    return true;
}