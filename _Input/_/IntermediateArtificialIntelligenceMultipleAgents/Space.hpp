#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NSpace
{
    namespace NEntity
    {
        struct SEntity;
    }

    inline struct SSpace
    {
        std::int64_t FNumber;
        std::vector<std::shared_ptr<NEntity::SEntity>> FArray;

        SSpace();
        void IPreupdate();

        void IPostupdate();
        ~SSpace();
    }
    GSpace;
}