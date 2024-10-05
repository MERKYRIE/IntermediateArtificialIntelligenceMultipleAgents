#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    struct SEntity
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FSprite;
        double FTimer;
        double FScale;
        double FSeparation;
        double FCohesion;
        double FSteer;
        std::shared_ptr<NVector::SVector> FPosition;
        std::shared_ptr<NVector::SVector> FDirection;
        std::shared_ptr<NVector::SVector> FLastDirection;

        SEntity();
        SEntity* IPreupdate();

        SEntity* IPostupdate();
        ~SEntity();
    };
}