#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Keyboard/Key.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard
{
    SKeyboard::SKeyboard()
    {
        for(auto const&[LKey , LValue] : std::initializer_list<std::pair<decltype(FAdaptors)::key_type , decltype(FAdaptors)::mapped_type>>
        {
            {SDL_SCANCODE_A , "A"}
            ,
            {SDL_SCANCODE_B , "B"}
            ,
            {SDL_SCANCODE_C , "C"}
        })
        {
            FKeys[LValue] = std::make_shared<NKey::SKey>();
            FAdaptors[LKey] = LValue;
        }
    }

    void SKeyboard::IPreupdate()
    {
        for(auto const&[LKey , LValue] : FKeys)
        {
            LValue->IPreupdate();
        }
    }

    void SKeyboard::IPostupdate(SDL_Event const& AEvent)
    {
        FKeys[FAdaptors[AEvent.key.keysym.scancode]]->IPostupdate(AEvent);
    }

    SKeyboard::~SKeyboard()
    {
    
    }
}