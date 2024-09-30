#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents/Video/Sprite.hpp"

#include"Entity.hpp"
#include"Vector.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessImageSpecific("/_.png"));
        FTimer = 0.0;
        FScale = 1.0 / 256.0;
        FDistance = 1.0 / 1024;
        std::random_device LGenerator;

        FPosition = std::make_shared<NVector::SVector>();
        FPosition->FXMinimum = 0.0;
        FPosition->FXMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IWidth());
        std::uniform_real_distribution<double> LPositionXDistributor{0.0 , FPositionXLimit};
        FPosition->FX = LPositionXDistributor(LGenerator);
        FPosition->FYMinimum = 0.0;
        FPosition->FYMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight());
        std::uniform_real_distribution<double> LPositionYDistributor{0.0 , FPositionYLimit};
        FPosition->FY = LPositionXDistributor(LGenerator);

        FDirection = std::make_shared<NVector::SVector>();
        FDirection->FXMinimum = -1.0;
        FDirection->FXMaximum = +1.0;
        FDirection->FYMinimum = -1.0;
        FDirection->FYMaximum = +1.0;
        FDirection->IGenerate();
    }

    SEntity* SEntity::IPreupdate()
    {
        std::shared_ptr<NVector::SVector> LDirection{std::make_shared<NVector::SVector>()};
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition.get())->IMeasure() < FDistance)
                {
                    LDirection = LDirection->ISubtract(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition.get()).get());
                    LDirection->INormalize();
                }
            }
        }
        if(LDirection->IValidate())
        {
            FDirection = LDirection;
        }
        else
        {
            if(NTime::GTime.ITimepointAbsolute() / 1'000.0 - FTimer >= 1.0)
            {
                FDirection->IGenerate();
                FTimer = NTime::GTime.ITimepointAbsolute() / 1'000.0;
            }
        }
        FPosition->IAssign(FPosition->FX + FDirection->FX * NTime::GTime.ITimepointRelative() / 1'000.0 , FPosition->FY + FDirection->FY * NTime::GTime.ITimepointRelative() / 1'000.0);
        FSprite->IAccessDestinationXSquareAbsolute(FPosition->FX)->IAccessDestinationYSquareAbsolute(FPosition->FY)
        ->IAccessDestinationWidthSquareAbsolute(FScale)->IAccessDestinationHeightSquareAbsolute(FScale)
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