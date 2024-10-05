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
        FCohesion = 1.0 / 4.0;
        FSteer = 30.0;

        FPosition = std::make_shared<NVector::SVector>();
        FPosition->IAssign(FPosition->IGenerate(FScale / 2.0 , NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IWidth()) - FScale / 2.0 , FScale / 2.0 , NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight()) - FScale / 2.0));

        FDirection = std::make_shared<NVector::SVector>();
        FDirection->IAssign(FDirection->IGenerate(-1.0 , +1.0 , -1.0 , +1.0)->INormalize());

        FLastDirection = std::make_shared<NVector::SVector>();
        FLastDirection->IAssign(FDirection);
    }

    SEntity* SEntity::IPreupdate()
    {
        std::shared_ptr<NVector::SVector> LDirection{std::make_shared<NVector::SVector>()};
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX)->IMeasure() < FSeparation)
                {
                    LDirection->IAssign(LDirection->ISubtract(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition)));
                }
            }
        }
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition)->IClamp(FSeparation , FCohesion))
                {
                    LDirection->IAssign(LDirection->IAdd(GSpace.FArray[LEntity]->FDirection));
                }
            }
        }
        for(std::int64_t LEntity{0} ; LEntity < GSpace.FNumber ; LEntity++)
        {
            if(GSpace.FArray[LEntity].get() != this)
            {
                if(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition->FX)->IMeasure() > FCohesion)
                {
                    LDirection->IAssign(LDirection->IAdd(GSpace.FArray[LEntity]->FPosition->ISubtract(FPosition)));
                }
            }
        }
        if(NTime::GTime.ITimepointAbsolute() / 1'000.0 - FTimer >= 1.0)
        {
            FLastDirection->IAssign(FDirection);
            FDirection->IAssign(FDirection->IGenerate(-1.0 , +1.0 , -1.0 , +1.0)->INormalize());
            FTimer = NTime::GTime.ITimepointAbsolute() / 1'000.0;
        }
        else
        {
            FDirection = FLastDirection;
        }
        FDirection->IAssign(FDirection->IAdd(LDirection));
        if(std::abs(std::clamp(FDirection->IConvert() - FSprite->IRotation() , -FSteer , +FSteer)) * NTime::GTime.ITimepointRelative() / 1'000 < FSteer)
        {
            FPosition->IAssign(FPosition->IAdd(FDirection->IMultiply(NTime::GTime.ITimepointRelative() / 1'000.0 / 60.0 / 60.0 / 1.0)));
            FPosition->IShrink(FScale / 2.0 , NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IWidth()) - FScale / 2.0 , FScale / 2.0 , NVideo::GVideo.IConvertFromPixelToSquare(NVideo::GVideo.IHeight()) - FScale / 2.0);
        }
        FSprite->IAccessDestinationXSquareAbsolute(FPosition->FX)->IAccessDestinationYSquareAbsolute(FPosition->FY)->IAccessDestinationWidthSquareAbsolute(FScale)->IAccessDestinationHeightSquareAbsolute(FScale)
        ->IRotation(FSprite->IRotation() + std::clamp(FDirection->IConvert() - FSprite->IRotation() , -FSteer , +FSteer) * NTime::GTime.ITimepointRelative() / 1'000)->IDraw();
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