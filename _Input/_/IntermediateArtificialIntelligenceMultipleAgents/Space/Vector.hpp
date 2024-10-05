#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NVector
{
    struct SVector
    {
        double FX;
        double FY;

        SVector();

        void IAssign(std::shared_ptr<SVector> const& AVector);

        bool IValidate();
        bool IClamp(double const& AMinimum , double const& AMaximum);

        double IMeasure();
        double IConvert();

        std::shared_ptr<SVector> INormalize();
        std::shared_ptr<SVector> IGenerate(double const& AMinimumX , double const& AMaximumX , double const& AMinimumY , double const& AMaximumY);
        std::shared_ptr<SVector> IShrink(double const& AMinimumX , double const& AMaximumX , double const& AMinimumY , double const& AMaximumY);

        std::shared_ptr<SVector> IAdd(double const& AValue);
        std::shared_ptr<SVector> ISubtract(double const& AValue);
        std::shared_ptr<SVector> IMultiply(double const& AValue);
        std::shared_ptr<SVector> IDivide(double const& AValue);

        std::shared_ptr<SVector> IAdd(std::shared_ptr<SVector> const& AVector);
        std::shared_ptr<SVector> ISubtract(std::shared_ptr<SVector> const& AVector);
        std::shared_ptr<SVector> IMultiply(std::shared_ptr<SVector> const& AVector);
        std::shared_ptr<SVector> IDivide(std::shared_ptr<SVector> const& AVector);

        ~SVector();
    };
}