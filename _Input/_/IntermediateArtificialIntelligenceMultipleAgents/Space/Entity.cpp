#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents/Video/Sprite.hpp"

#include"Entity.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessImageRandom());
        FX = 0;
        FY = 0;
        FScaleX = 0.125;
        FScaleY = 0.125;
    }

    SEntity* SEntity::IPreupdate()
    {
        FSprite->IAccessDestinationXSquareAbsolute(FX)->IAccessDestinationYSquareAbsolute(FY)
        ->IAccessDestinationWidthSquareAbsolute(FScaleX)->IAccessDestinationHeightSquareAbsolute(FScaleY)
        ->IDraw();
        return(this);
    }
    
    std::shared_ptr<NVideo::NSprite::SSprite> const& SEntity::ISprite()
    {
        return(FSprite);
    }

    SEntity* SEntity::ISprite(std::shared_ptr<NVideo::NSprite::SSprite> const& ASprite)
    {
        FSprite = ASprite;
        return(this);
    }

    SEntity* SEntity::IPostupdate()
    {
        return(this);
    }

    SEntity::~SEntity()
    {
    
    }
}