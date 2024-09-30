#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NDebug
{
    SDebug::SDebug()
    {
        
    }

    void SDebug::IPreupdate()
    {
    
    }

    void SDebug::IAssert(bool ACondition , const std::string& AMessage , SDL_MessageBoxFlags AFlags , const std::source_location& ALocation)
    {
        if(ACondition)
        {
            if
            (
                (AFlags & SDL_MESSAGEBOX_INFORMATION)
                ||
                SDL_ShowSimpleMessageBox
                (
                    AFlags
                    ,
                    "Debug"
                    ,
                    (
                        std::string{}
                        +
                        "File - " + ALocation.file_name() + "\n"
                        +
                        "Function - " + ALocation.function_name() + "\n"
                        +
                        "Line - " + std::to_string(ALocation.line()) + "\n"
                        +
                        "Column - " + std::to_string(ALocation.column()) + "\n"
                        +
                        AMessage
                    )
                    .
                    data()
                    ,
                    nullptr
                )
                <
                0
            )
            {
                std::cout
                <<
                "Debug:" << "\n"
                <<
                "    File - " << ALocation.file_name() << "\n"
                <<
                "    Function - " << ALocation.function_name() << "\n"
                <<
                "    Line - " << ALocation.line() << "\n"
                <<
                "    Column - " << ALocation.column() << "\n"
                <<
                AMessage << "\n\n";
            }
            if(AFlags & SDL_MESSAGEBOX_ERROR)
            {
                std::exit(0);
            }
        }
    }

    void SDebug::IError(bool ACondition , const std::string& AMessage , const std::source_location& ALocation)
    {
        IAssert(ACondition , AMessage , SDL_MESSAGEBOX_ERROR , ALocation);
    }

    bool SDebug::IWarning(bool ACondition , const std::string& AMessage , const std::source_location& ALocation)
    {
        IAssert(ACondition , AMessage , SDL_MESSAGEBOX_WARNING , ALocation);
        return(ACondition);
    }

    bool SDebug::IInformation(bool ACondition , const std::string& AMessage , const std::source_location& ALocation)
    {
        IAssert(ACondition , AMessage , SDL_MESSAGEBOX_INFORMATION , ALocation);
        return(ACondition);
    }

    void SDebug::ISimpleDirectMediaLayerCodeError(std::int32_t AValue , const std::source_location& ALocation)
    {
        IError(AValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation);
    }

    bool SDebug::ISimpleDirectMediaLayerCodeWarning(std::int32_t AValue , const std::source_location& ALocation)
    {
        return(IWarning(AValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    bool SDebug::ISimpleDirectMediaLayerCodeInformation(std::int32_t AValue , const std::source_location& ALocation)
    {
        return(IInformation(AValue < 0 , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    void SDebug::ISimpleDirectMediaLayerMaskError(std::int32_t AValue , const std::source_location& ALocation)
    {
        IError(!AValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation);
    }

    bool SDebug::ISimpleDirectMediaLayerMaskWarning(std::int32_t AValue , const std::source_location& ALocation)
    {
        return(IWarning(!AValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    bool SDebug::ISimpleDirectMediaLayerMaskInformation(std::int32_t AValue , const std::source_location& ALocation)
    {
        return(IInformation(!AValue , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    void SDebug::ISimpleDirectMediaLayerHandleError(void* APointer , const std::source_location& ALocation)
    {
        IError(!APointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation);
    }

    bool SDebug::ISimpleDirectMediaLayerHandleWarning(void* APointer , const std::source_location& ALocation)
    {
        return(IWarning(!APointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    bool SDebug::ISimpleDirectMediaLayerHandleInformation(void* APointer , const std::source_location& ALocation)
    {
        return(IInformation(!APointer , std::string{} + "Simple DirectMedia Layer - " + SDL_GetError() , ALocation));
    }

    void SDebug::IPostupdate()
    {
    
    }

    SDebug::~SDebug()
    {
        
    }
}