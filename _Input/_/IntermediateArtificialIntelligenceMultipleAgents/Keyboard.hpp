#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard
{    
    namespace NKey
    {
        struct SKey;
    }

    inline struct SKeyboard
    {
        std::unordered_map<std::string , std::shared_ptr<NKey::SKey>> FKeys;
        std::unordered_map<SDL_Scancode , std::string> FAdaptors;

        SKeyboard();
        void IPreupdate();

        void IPostupdate(SDL_Event const& AEvent);
        ~SKeyboard();
    }
    GKeyboard;
}