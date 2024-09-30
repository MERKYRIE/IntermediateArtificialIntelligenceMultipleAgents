#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NTime
{
    inline struct STime
    {
        std::int64_t FTimepointLast;
        std::int64_t FTimepointAbsolute;
        std::int64_t FTimepointRelative;

        STime();
        void IPreupdate();

        std::int64_t const& ITimepointLast();
        std::int64_t const& ITimepointAbsolute();
        std::int64_t const& ITimepointRelative();

        void ITimepointLast(std::int64_t const& AValue);
        void ITimepointAbsolute(std::int64_t const& AValue);
        void ITimepointRelative(std::int64_t const& AValue);

        void IPostupdate();
        ~STime();
    }
    GTime;
}