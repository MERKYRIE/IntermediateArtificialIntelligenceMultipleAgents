#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace::NVector
{
    struct SVector
    {
        double FXMinimum;
        double FXMaximum;
        double FX;
        double FYMinimum;
        double FYMaximum;
        double FY;

        SVector();

        SVector* IReset();
        SVector* IAssign(SVector* const& AVector);
        std::shared_ptr<SVector> IAdd(SVector* const& AVector);
        std::shared_ptr<SVector> ISubtract(SVector* const& AVector);
        std::shared_ptr<SVector> IMultiply(SVector* const& AVector);
        std::shared_ptr<SVector> IDivide(SVector* const& AVector);
        double IMeasure();
        SVector* INormalize();
        SVector* IGenerate(double const& AMinimum , double const& AMaximum);
        bool IValidate();

        ~SVector();
    };
}