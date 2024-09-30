#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NDebug
{
    inline struct SDebug
    {
        SDebug();
        void IPreupdate();

        void IAssert(bool ACondition , const std::string& AMessage , SDL_MessageBoxFlags AFlags , const std::source_location& ALocation);
        void IError(bool ACondition = true , const std::string& AMessage = "" , const std::source_location& ALocation = std::source_location::current());
        bool IWarning(bool ACondition = true , const std::string& AMessage = "" , const std::source_location& ALocation = std::source_location::current());
        bool IInformation(bool ACondition = true , const std::string& AMessage = "" , const std::source_location& ALocation = std::source_location::current());
        void ISimpleDirectMediaLayerCodeError(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerCodeWarning(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerCodeInformation(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        void ISimpleDirectMediaLayerMaskError(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerMaskWarning(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerMaskInformation(std::int32_t AValue , const std::source_location& ALocation = std::source_location::current());
        void ISimpleDirectMediaLayerHandleError(void* APointer , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerHandleWarning(void* APointer , const std::source_location& ALocation = std::source_location::current());
        bool ISimpleDirectMediaLayerHandleInformation(void* APointer , const std::source_location& ALocation = std::source_location::current());

        void IPostupdate();
        ~SDebug();
    }
    GDebug;
}