#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Vector.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NVector
{
    SVector::SVector()
    {
        FX = 0.0;
        FY = 0.0;
    }

    void SVector::IAssign(std::shared_ptr<SVector> const& AVector)
    {
        FX = AVector->FX;
        FY = AVector->FY;
    }

    bool SVector::IValidate()
    {
        return(FX || FY);
    }

    bool SVector::IClamp(double const& AMinimum , double const& AMaximum)
    {
        return(std::sqrt(FX * FX + FY * FY) == std::clamp(std::sqrt(FX * FX + FY * FY) , AMinimum , AMaximum));
    }

    double SVector::IMeasure()
    {
        return(std::sqrt(FX * FX + FY * FY));
    }

    double SVector::IConvert()
    {
        if(FX || FY)
        {
            return(std::atan2(FY/ std::sqrt(FX * FX + FY * FY) , FX/ std::sqrt(FX * FX + FY * FY)) * 180.0 / std::numbers::pi);
        }
        else
        {
            return(0.0);
        }
    }

    std::shared_ptr<SVector> SVector::INormalize()
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(FX || FY)
        {
            LVector->FX = FX / std::sqrt(FX * FX + FY * FY);
            LVector->FY = FY / std::sqrt(FX * FX + FY * FY);
        }
        else
        {
            LVector->FX = FX;
            LVector->FY = FY;
        }
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IShrink(double const& AMinimumX , double const& AMaximumX , double const& AMinimumY , double const& AMaximumY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = std::clamp(FX , AMinimumX , AMaximumX);
        LVector->FY = std::clamp(FY , AMinimumY , AMaximumY);
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IGenerate(double const& AMinimumX , double const& AMaximumX , double const& AMinimumY , double const& AMaximumY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        std::random_device LGenerator;
        std::uniform_real_distribution<double> LXDistributor{AMinimumX , AMaximumX};
        std::uniform_real_distribution<double> LYDistributor{AMinimumY , AMaximumY};
        LVector->FX = LXDistributor(LGenerator);
        LVector->FY = LYDistributor(LGenerator);
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IInvert()
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(FX && FY)
        {
            LVector->FX = 1.0 / FX;
            LVector->FY = 1.0 / FY;
        }
        else
        {
            LVector->FX = FX;
            LVector->FY = FY;
        }
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IAdd(double const& AValue)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX + AValue;
        LVector->FY = FY + AValue;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::ISubtract(double const& AValue)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX - AValue;
        LVector->FY = FY - AValue;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IMultiply(double const& AValue)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX * AValue;
        LVector->FY = FY * AValue;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IDivide(double const& AValue)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(AValue)
        {
            LVector->FX = FX / AValue;
            LVector->FY = FY / AValue;
        }
        else
        {
            LVector->FX = FX;
            LVector->FY = FY;
        }
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IAdd(std::shared_ptr<SVector> const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX + AVector->FX;
        LVector->FY = FY + AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::ISubtract(std::shared_ptr<SVector> const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX - AVector->FX;
        LVector->FY = FY - AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IMultiply(std::shared_ptr<SVector> const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX * AVector->FX;
        LVector->FY = FY * AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IDivide(std::shared_ptr<SVector> const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(AVector->FX && AVector->FY)
        {
            LVector->FX = FX / AVector->FX;
            LVector->FY = FY / AVector->FY;
        }
        else
        {
            LVector->FX = FX;
            LVector->FY = FY;
        }
        return(LVector);
    }

    SVector::~SVector()
    {
    
    }
}