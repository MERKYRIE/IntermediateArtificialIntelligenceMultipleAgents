#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Vector.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NVector
{
    SVector::SVector()
    {
        FXMinimum = -std::numeric_limits<double>::min();
        FXMaximum = std::numeric_limits<double>::max();
        FX = 0.0;
        FYMinimum = -std::numeric_limits<double>::min();
        FYMaximum = std::numeric_limits<double>::max();
        FY = 0.0;
    }

    void SVector::IAssign(double const& AX , double const& AY)
    {
        FX = std::clamp(AX , FXMinimum , FXMaximum);
        FY = std::clamp(AY , FYMinimum , FYMaximum);
    }

    void SVector::INormalize()
    {
        if(IValidate())
        {
            FX /= IMeasure();
            FY /= IMeasure();
        }
    }

    void SVector::IGenerate(bool const& ANormalization)
    {
        std::random_device LGenerator;
        std::uniform_real_distribution<double> LXDistributor{FXMinimum , FXMaximum};
        std::uniform_real_distribution<double> LYDistributor{FYMinimum , FYMaximum};
        FX = LXDistributor(LGenerator);
        FY = LYDistributor(LGenerator);
        if(ANormalization)
        {
            INormalize();
        }
    }

    bool SVector::IValidate()
    {
        return(FX || FY);
    }

    bool SVector::IClamp(double const& AMinimum , double const& AMaximum)
    {
        return(IMeasure() == std::clamp(IMeasure() , AMinimum , AMaximum));
    }

    double SVector::IMeasure()
    {
        return(std::sqrt(FX * FX + FY * FY));
    }

    double SVector::IMeasure(double const& AX , double const& AY)
    {
        return(ISubtract(AX , AY)->IMeasure());
    }

    double SVector::IConvert()
    {
        INormalize();
        return(std::atan2(FY , FX) * 180.0 / std::numbers::pi);
    }

    std::shared_ptr<SVector> SVector::IAdd(double const& AX , double const& AY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX + AX;
        LVector->FY = FY + AY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::ISubtract(double const& AX , double const& AY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX - AX;
        LVector->FY = FY - AY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IMultiply(double const& AX , double const& AY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        LVector->FX = FX * AX;
        LVector->FY = FY * AY;
        return(LVector);
    }

    std::shared_ptr<SVector> SVector::IDivide(double const& AX , double const& AY)
    {
        std::shared_ptr<SVector> LVector{std::make_shared<SVector>()};
        if(AX)
        {
            LVector->FX = FX / AX;
        }
        if(AY)
        {
            LVector->FY = FY / AY;
        }
        return(LVector);
    }

    SVector::~SVector()
    {
    
    }
}