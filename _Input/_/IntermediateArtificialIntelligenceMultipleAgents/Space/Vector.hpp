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

        void IAssign(double const& AX , double const& AY);
        void INormalize();
        void IGenerate(bool const& ANormalization = false);
        bool IValidate();
        bool IClamp(double const& AMinimum , double const& AMaximum);
        double IMeasure();
        double IMeasure(double const& AX , double const& AY);
        double IConvert();
        std::shared_ptr<SVector> IAdd(double const& AX , double const& AY);
        std::shared_ptr<SVector> ISubtract(double const& AX , double const& AY);
        std::shared_ptr<SVector> IMultiply(double const& AX , double const& AY);
        std::shared_ptr<SVector> IDivide(double const& AX , double const& AY);

        ~SVector();
    };
}