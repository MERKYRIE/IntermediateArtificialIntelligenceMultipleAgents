#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard::NKey
{    
    struct SKey
    {
        std::string FState;
        std::string FState_;

        SKey();
        void IPreupdate();

        void IPostupdate(SDL_Event const& AEvent);
        ~SKey();
    };
}