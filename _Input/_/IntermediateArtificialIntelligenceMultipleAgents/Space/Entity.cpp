#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents/Video/Sprite.hpp"

#include"Entity.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessImageSpecific("/_.png"));
        FTimer = 0.0;
        FDistance = 1.0 / 256.0;
        FScaleX = 1.0 / 256.0;
        FScaleY = 1.0 / 256.0;
        FPositionXMinimum = 0.0;
        FPositionXMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IWidth()) - FSprite->IAccessDestinationWidthSquare();
        std::random_device LGenerator;
        std::uniform_real_distribution<double> LPosition{-1.0 / 16.0 , +1.0 / 16.0};
        FPositionX = std::clamp(LPosition(LGenerator) , FPositionXMinimum , FPositionXMaximum);
        FPositionYMinimum = 0,0;
        FPositionYMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight()) - FSprite->IAccessDestinationHeightSquare();
        FPositionY = 0;
        std::uniform_real_distribution<double> LRotation{-1.0 / 16.0 , +1.0 / 16.0};
        FRotationX = LRotation(LGenerator);
        FRotationY = LRotation(LGenerator);
    }

    SEntity* SEntity::IPreupdate()
    {
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(std::sqrt((GSpace.FArray[LEntity]->FPositionX - FPositionX) * (GSpace.FArray[LEntity]->FPositionX - FPositionX) + (GSpace.FArray[LEntity]->FPositionY - FPositionY) + (GSpace.FArray[LEntity]->FPositionY - FPositionY)) < FDistance)
                {
                    FRotationX -= GSpace.FArray[LEntity]->FPositionX - FPositionX;
                    FRotationY -= GSpace.FArray[LEntity]->FPositionY - FPositionY;
                }
            }
        }
        if(!FRotationX && !FRotationY)
        {
            if(NTime::GTime.ITimepointAbsolute() / 1000.0 - FTimer >= 1.0)
            {
                std::random_device LGenerator;
                std::uniform_real_distribution<double> LDistributor{-1.0 / 16.0 , +1.0 / 16.0};
                FRotationX = LDistributor(LGenerator);
                FRotationY = LDistributor(LGenerator);
                FTimer = NTime::GTime.ITimepointAbsolute() / 1000.0;
            }
        }
        FPositionX = std::clamp(FPositionX + FRotationX * NTime::GTime.ITimepointRelative() / 1000.0 , FPositionXMinimum , FPositionXMaximum);
        FPositionY = std::clamp
        (
            FPositionY + FRotationY * NTime::GTime.ITimepointRelative() / 1000.0 , 0.0 , NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight()) - FSprite->IAccessDestinationHeightSquare()
        );
        FSprite->IAccessDestinationXSquareAbsolute(FPositionX)->IAccessDestinationYSquareAbsolute(FPositionY)
        ->IAccessDestinationWidthSquareAbsolute(FScaleX)->IAccessDestinationHeightSquareAbsolute(FScaleY)
        ->IDraw();
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