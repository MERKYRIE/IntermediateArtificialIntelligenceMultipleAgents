#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Video/Image.hpp"
#include"Video/Sprite.hpp"

#include"Space/Entity.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace
{
    SSpace::SSpace()
    {
        FNumber = 10;
        FArray.resize(FNumber);
        for(std::int64_t LEntity{0} ; LEntity < FNumber ; LEntity++)
        {
            FArray[LEntity] = std::make_shared<NEntity::SEntity>();
        }
        FArray.shrink_to_fit();
    }

    void SSpace::IPreupdate()
    {
        for(std::int64_t LEntity{0} ; LEntity < FNumber ; LEntity++)
        {
            FArray[LEntity]->IPreupdate();
        }
    }

    void SSpace::IPostupdate()
    {
        for(std::int64_t LEntity{0} ; LEntity < FNumber ; LEntity++)
        {
            FArray[LEntity]->IPostupdate();
        }
    }

    SSpace::~SSpace()
    {
    
    }
}