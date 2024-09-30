#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    struct SEntity
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FSprite;
        double FX;
        double FY;
        double FScaleX;
        double FScaleY;

        SEntity();
        SEntity* IPreupdate();

        std::shared_ptr<NVideo::NSprite::SSprite> const& ISprite();

        SEntity* ISprite(std::shared_ptr<NVideo::NSprite::SSprite> const& ASprite);

        SEntity* IPostupdate();
        ~SEntity();
    };
}