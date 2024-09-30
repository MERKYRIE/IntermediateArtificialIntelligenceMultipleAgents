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

        std::int64_t const& INumber();
        std::vector<std::shared_ptr<NEntity::SEntity>> const& IArray();

        void INumber(std::int64_t const& AValue);
        void IArray(std::vector<std::shared_ptr<NEntity::SEntity>> const& AValue);

        void IPostupdate();
        ~SSpace();
    }
    GSpace;
}