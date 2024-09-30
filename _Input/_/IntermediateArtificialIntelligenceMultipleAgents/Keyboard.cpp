#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard
{
    SKeyboard::SKeyboard()
    {
        FKeys = 512;
        FAreKeysHeld.resize(FKeys);
        FAreKeysPressed.resize(FKeys);
        FAreKeysReleased.resize(FKeys);
        for(std::int64_t LKey{0} ; LKey < FKeys ; LKey++)
        {
            FAreKeysHeld[LKey] = false;
            FAreKeysPressed[LKey] = false;
            FAreKeysReleased[LKey] = false;
        }
    }

    void SKeyboard::IPreupdate()
    {
        for(std::int64_t LKey{0} ; LKey < FKeys ; LKey++)
        {
            FAreKeysPressed[LKey] = false;
            FAreKeysReleased[LKey] = false;
        }
    }

    std::int64_t const& SKeyboard::IKeys()
    {
        return(FKeys);
    }

    std::vector<bool> const& SKeyboard::IAreKeysHeld()
    {
        return(FAreKeysHeld);
    }

    std::vector<bool> const& SKeyboard::IAreKeysPressed()
    {
        return(FAreKeysPressed);
    }

    std::vector<bool> const& SKeyboard::IAreKeysReleased()
    {
        return(FAreKeysReleased);
    }

    void SKeyboard::IKeys(std::int64_t const& AValue)
    {
        FKeys = AValue;
    }

    void SKeyboard::IAreKeysHeld(std::vector<bool> const& AValue)
    {
        FAreKeysHeld = AValue;
    }

    void SKeyboard::IAreKeysPressed(std::vector<bool> const& AValue)
    {
        FAreKeysPressed = AValue;
    }

    void SKeyboard::IAreKeysReleased(std::vector<bool> const& AValue)
    {
        FAreKeysReleased = AValue;
    }

    bool SKeyboard::IIsKeyHeld(std::int64_t AKey)
    {
        return(FAreKeysHeld[AKey]);
    }

    bool SKeyboard::IIsKeyPressed(std::int64_t AKey)
    {
        return(FAreKeysPressed[AKey]);
    }

    bool SKeyboard::IIsKeyReleased(std::int64_t AKey)
    {
        return(FAreKeysReleased[AKey]);
    }

    void SKeyboard::IPostupdate(SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_KEYDOWN):
                FAreKeysHeld[AEvent.key.keysym.scancode] = true;
                if(!AEvent.key.repeat)
                {
                    FAreKeysPressed[AEvent.key.keysym.scancode] = true;
                }
            break;
            case(SDL_KEYUP):
                FAreKeysHeld[AEvent.key.keysym.scancode] = false;
                if(!AEvent.key.repeat)
                {
                    FAreKeysReleased[AEvent.key.keysym.scancode] = true;
                }
            break;
        }
    }

    SKeyboard::~SKeyboard()
    {
    
    }
}