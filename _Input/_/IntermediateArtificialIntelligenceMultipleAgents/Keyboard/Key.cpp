#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Key.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard::NKey
{
    SKey::SKey()
    {
        FState = "Up";
        FState_.clear();
    }

    void SKey::IPreupdate()
    {
        FState_.clear();
    }

    void SKey::IPostupdate(SDL_Event const& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_KEYDOWN):
                FState = "Down";
                if(!AEvent.key.repeat)
                {
                    FState_ = "Pressed";
                }
            break;
            case(SDL_KEYUP):
                FState = "Up";
                if(!AEvent.key.repeat)
                {
                    FState_ = "Released";
                }
            break;
        }
    }

    SKey::~SKey()
    {
    
    }
}