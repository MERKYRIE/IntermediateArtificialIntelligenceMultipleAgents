#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NKeyboard
{
    inline struct SKeyboard
    {
        std::int64_t FKeys;
        std::vector<bool> FAreKeysHeld;
        std::vector<bool> FAreKeysPressed;
        std::vector<bool> FAreKeysReleased;

        SKeyboard();
        void IPreupdate();

        std::int64_t const& IKeys();
        std::vector<bool> const& IAreKeysHeld();
        std::vector<bool> const& IAreKeysPressed();
        std::vector<bool> const& IAreKeysReleased();

        void IKeys(std::int64_t const& AValue);
        void IAreKeysHeld(std::vector<bool> const& AValue);
        void IAreKeysPressed(std::vector<bool> const& AValue);
        void IAreKeysReleased(std::vector<bool> const& AValue);

        bool IIsKeyHeld(std::int64_t AKey);
        bool IIsKeyPressed(std::int64_t AKey);
        bool IIsKeyReleased(std::int64_t AKey);
        void IPostupdate(SDL_Event& AEvent);
        ~SKeyboard();
    }
    GKeyboard;
}