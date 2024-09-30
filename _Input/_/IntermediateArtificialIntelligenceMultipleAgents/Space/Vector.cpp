#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Vector.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NVector
{
    SVector::SVector()
    {
        FX = 0.0;
        FXMinimum = std::numeric_limits<double>::min();
        FXMaximum = std::numeric_limits<double>::max();
        FY = 0.0;
        FYMinimum = std::numeric_limits<double>::min();
        FYMaximum = std::numeric_limits<double>::max();
    }

    SVector* SVector::IReset()
    {
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SVector* SVector::IAssign(SVector* const& AVector)
    {
        FX = std::clamp(AVector->FX , FXMinimum , FXMaximum);
        FY = std::clamp(AVector->FY , FYMinimum , FYMaximum);
        return(this);
    }

    std::shared_ptr<SVector> SVector::IAdd(SVector* const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX + AVector->FX;
        LVector->FY = FY + AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::ISubtract(SVector* const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX - AVector->FX;
        LVector->FY = FY - AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IMultiply(SVector* const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX * AVector->FX;
        LVector->FY = FY * AVector->FY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IDivide(SVector* const& AVector)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(AVector->FX)
        {
            LVector->FX = FX / AVector->FX;
        }
        if(AVector->FY)
        {
            LVector->FY = FY / AVector->FY;
        }
        return(LVector);
    }

    bool SVector::IValidate()
    {
        return(FX || FY);
    }

    double SVector::IMeasure()
    {
        return(std::sqrt(FX * FX + FY * FY));
    }

    SVector* SVector::INormalize()
    {
        if(IValidate())
        {
            FX /= IMeasure();
            FY /= IMeasure();
        }
        return(this);
    }

    SVector* SVector::IGenerate(double const& AMinimum , double const& AMaximum)
    {
        std::random_device LGenerator;
        std::uniform_real_distribution<double> LDirectionDistributor{AMinimum , AMaximum};
        FX = LDirectionDistributor(LGenerator);
        FY = LDirectionDistributor(LGenerator);
        INormalize();
        return(this);
    }

    SVector::~SVector()
    {
    
    }
}