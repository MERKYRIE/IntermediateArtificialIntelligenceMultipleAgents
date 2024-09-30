#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    struct SEntity
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FSprite;
        double FTimer;
        double FDistance;
        double FScaleX;
        double FScaleY;
        double FPositionXMinimum;
        double FPositionXMaximum;
        double FPositionX;
        double FPositionYMinimum;
        double FPositionYMaximum;
        double FPositionY;
        double FRotationX;
        double FRotationY;

        SEntity();
        SEntity* IPreupdate();

        SEntity* IPostupdate();
        ~SEntity();
    };
}