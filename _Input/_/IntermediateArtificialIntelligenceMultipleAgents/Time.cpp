#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NTime
{
    STime::STime()
    {
        FTimepointLast = 0;
        FTimepointAbsolute = 0;
        FTimepointRelative = 0;
    }

    void STime::IPreupdate()
    {
        FTimepointLast = FTimepointAbsolute;
        FTimepointAbsolute = SDL_GetTicks();
        FTimepointRelative = FTimepointAbsolute - FTimepointLast;
    }

    std::int64_t const& STime::ITimepointLast()
    {
        return(FTimepointLast);
    }

    std::int64_t const& STime::ITimepointAbsolute()
    {
        return(FTimepointAbsolute);
    }

    std::int64_t const& STime::ITimepointRelative()
    {
        return(FTimepointRelative);
    }

    void STime::ITimepointLast(std::int64_t const& AValue)
    {
        FTimepointLast = AValue;
    }

    void STime::ITimepointAbsolute(std::int64_t const& AValue)
    {
        FTimepointAbsolute = AValue;
    }

    void STime::ITimepointRelative(std::int64_t const& AValue)
    {
        FTimepointRelative = AValue;
    }

    void STime::IPostupdate()
    {
        
    }

    STime::~STime()
    {
        
    }
}