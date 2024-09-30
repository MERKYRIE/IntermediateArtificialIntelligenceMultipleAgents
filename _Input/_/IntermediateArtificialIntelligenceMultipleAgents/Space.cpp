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

    const std::int64_t& SSpace::INumber()
    {
        return(FNumber);
    }

    std::vector<std::shared_ptr<NEntity::SEntity>> const& SSpace::IArray()
    {
        return(FArray);
    }

    void SSpace::INumber(const std::int64_t& AValue)
    {
        FNumber = AValue;
    }

    void SSpace::IArray(std::vector<std::shared_ptr<NEntity::SEntity>> const& AValue)
    {
        FArray = AValue;
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