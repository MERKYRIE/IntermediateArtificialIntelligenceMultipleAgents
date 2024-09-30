#pragma once

#include<array>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<numbers>
#include<random>
#include<source_location>
#include<string>
#include<unordered_map>
#include<variant>
#include<vector>

#pragma warning(push)
    #pragma warning(disable : 26819)

    #include"../SimpleDirectMediaLayer/SDL.h"
    #include"../SimpleDirectMediaLayer/Image/SDL_image.h"
#pragma warning(pop)

#pragma warning(disable : 26495)

namespace NIntermediateArtificialIntelligenceMultipleAgents
{
    inline struct SIntermediateArtificialIntelligenceMultipleAgents
    {
        SIntermediateArtificialIntelligenceMultipleAgents();
        void IPreupdate();
        ~SIntermediateArtificialIntelligenceMultipleAgents();
    }
    GIntermediateArtificialIntelligenceMultipleAgents;
}

#include"IntermediateArtificialIntelligenceMultipleAgents/Debug.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents/Keyboard.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents/Time.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents/Video.hpp"
#include"IntermediateArtificialIntelligenceMultipleAgents/Space.hpp"