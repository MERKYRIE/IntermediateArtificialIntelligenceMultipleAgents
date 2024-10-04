#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents/Video/Sprite.hpp"

#include"Entity.hpp"
#include"Vector.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NEntity
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessImageSpecific("/Fish.png"));
        FTimer = 0.0;
        FScale = 1.0 / 64.0;
        FSeparation = 1.0 / 16.0;
        FAlignment = 1.0 / 4.0;
        FCohesion = 1.0 / 1.0;
        FSteer = 30.0;

        FPosition = std::make_shared<NVector::SVector>();
        FPosition->FXMinimum = FScale / 2.0;
        FPosition->FXMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IWidth()) - FScale / 2.0;
        FPosition->FYMinimum = FScale / 2.0;
        FPosition->FYMaximum = NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight()) - FScale / 2.0;
        FPosition->IGenerate();

        FDirection = std::make_shared<NVector::SVector>();
        FDirection->FXMinimum = -1.0;
        FDirection->FXMaximum = +1.0;
        FDirection->FYMinimum = -1.0;
        FDirection->FYMaximum = +1.0;
        FDirection->IGenerate(true);
    }

    SEntity* SEntity::IPreupdate()
    {
        std::shared_ptr<NVector::SVector> LDirection{std::make_shared<NVector::SVector>()};
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(GSpace.FArray[LEntity]->FPosition->IMeasure(FPosition->FX , FPosition->FY) < FSeparation)
                {
                    LDirection
                    =
                    LDirection->ISubtract
                    (
                        GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->FX , GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->FY
                    );
                }
            }
        }
        if(!LDirection->IValidate())
        {
            for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
            {
                if(GSpace.FArray[LEntity].get() != this)
                {
                    if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->IClamp(FSeparation , FAlignment))
                    {
                        LDirection = LDirection->IAdd(GSpace.FArray[LEntity]->FDirection->FX , GSpace.FArray[LEntity]->FDirection->FY);
                    }
                }
            }
            for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
            {
                if(GSpace.FArray[LEntity].get() != this)
                {
                    if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->IClamp(FAlignment , FCohesion))
                    {
                        LDirection
                        =
                        LDirection->IAdd
                        (
                            GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->FX , GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX , FPosition->FY)->FY
                        );
                    }
                }
            }
            if(NTime::GTime.ITimepointAbsolute() / 1'000.0 - FTimer >= 1.0)
            {
                FDirection->IGenerate(true);
                FTimer = NTime::GTime.ITimepointAbsolute() / 1'000.0;
            }
            LDirection = LDirection->IAdd(FDirection->FX , FDirection->FY);
        }
        if(std::abs(std::clamp(LDirection->IConvert() - FSprite->IRotation() , -FSteer , +FSteer)) * NTime::GTime.ITimepointRelative() / 1'000 < FSteer)
        {
            FPosition->IAssign(FPosition->FX + LDirection->FX * NTime::GTime.ITimepointRelative() / 1'000.0 , FPosition->FY + LDirection->FY * NTime::GTime.ITimepointRelative() / 1'000.0);
        }
        FSprite->IAccessDestinationXSquareAbsolute(FPosition->FX)->IAccessDestinationYSquareAbsolute(FPosition->FY)
        ->IAccessDestinationWidthSquareAbsolute(FScale)->IAccessDestinationHeightSquareAbsolute(FScale)
        ->IRotation(FSprite->IRotation() + std::clamp(LDirection->IConvert() - FSprite->IRotation() , -FSteer , +FSteer) * NTime::GTime.ITimepointRelative() / 1'000)->IDraw();
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