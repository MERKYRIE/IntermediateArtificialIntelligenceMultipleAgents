#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2main")
#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2")
#pragma comment(lib , "../SimpleDirectMediaLayer/Image/SDL2_image")

#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"IntermediateArtificialIntelligenceMultipleAgents/Keyboard/Key.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents
{
    SIntermediateArtificialIntelligenceMultipleAgents::SIntermediateArtificialIntelligenceMultipleAgents()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    }

    void SIntermediateArtificialIntelligenceMultipleAgents::IUupdate()
    {
        while(NKeyboard::GKeyboard.FKeys["Escape"]->FState == "Up")
        {
            NDebug::GDebug.IPreupdate();
            NKeyboard::GKeyboard.IPreupdate();
            SDL_Event LEvent;
            while(SDL_PollEvent(&LEvent))
            {
                switch(LEvent.type)
                {
                    case(SDL_KEYDOWN):
                        NKeyboard::GKeyboard.IPostupdate(LEvent);
                    break;
                    case(SDL_KEYUP):
                        NKeyboard::GKeyboard.IPostupdate(LEvent);
                    break;
                }
            }
            NTime::GTime.IPreupdate();
            NVideo::GVideo.IPreupdate();
            NSpace::GSpace.IPreupdate();
            NSpace::GSpace.IPostupdate();
            NVideo::GVideo.IPostupdate();
            NTime::GTime.IPostupdate();
            NDebug::GDebug.IPostupdate();
        };
    }

    SIntermediateArtificialIntelligenceMultipleAgents::~SIntermediateArtificialIntelligenceMultipleAgents()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NIntermediateArtificialIntelligenceMultipleAgents::GIntermediateArtificialIntelligenceMultipleAgents.IUupdate();
    return(0);
}