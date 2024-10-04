#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Video/Image.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NVideo
{
    SVideo::SVideo()
    {
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FWindow = SDL_CreateWindow("IntermediateArtificialIntelligenceMultipleAgents" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP));
        NDebug::GDebug.ISimpleDirectMediaLayerHandleError(FRenderer = SDL_CreateRenderer(FWindow , -1 , SDL_RENDERER_ACCELERATED));
        SDL_DisplayMode LDisplayMode;
        NDebug::GDebug.ISimpleDirectMediaLayerCodeError(SDL_GetWindowDisplayMode(FWindow , &LDisplayMode));
        FWidth = LDisplayMode.w;
        FHeight = LDisplayMode.h;
        FMinimum = std::min(FWidth , FHeight);
        FMaximum = std::max(FWidth , FHeight);
        FRatio = static_cast<double>(FWidth) / static_cast<double>(FHeight);
        FRatioInversed = static_cast<double>(FHeight) / static_cast<double>(FWidth);
        NDebug::GDebug.ISimpleDirectMediaLayerMaskError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Images"})
        {
            if(LEntry.path().extension() == ".png")
            {
                FImages.emplace_back(std::make_shared<NImage::SImage>(LEntry.path().generic_string()));
            }
        }
        FImages.shrink_to_fit();
    }

    void SVideo::IPreupdate()
    {
        SDL_RenderClear(FRenderer);
    }
    
    SDL_Window* const& SVideo::IWindow()
    {
        return(FWindow);
    }
    
    SDL_Renderer* const& SVideo::IRenderer()
    {
        return(FRenderer);
    }
    
    std::int32_t const& SVideo::IWidth()
    {
        return(FWidth);
    }

    std::int32_t const& SVideo::IHeight()
    {
        return(FHeight);
    }

    std::int32_t const& SVideo::IMinimum()
    {
        return(FMinimum);
    }

    std::int32_t const& SVideo::IMaximum()
    {
        return(FMaximum);
    }

    double const& SVideo::IRatio()
    {
        return(FRatio);
    }

    double const& SVideo::IRatioInversed()
    {
        return(FRatioInversed);
    }

    std::vector<std::shared_ptr<NImage::SImage>> const& SVideo::IImages()
    {
        return(FImages);
    }

    void SVideo::IWindow(SDL_Window* const& AValue)
    {
        FWindow = AValue;
    }

    void SVideo::IRenderer(SDL_Renderer* const& AValue)
    {
        FRenderer = AValue;
    }

    void SVideo::IWidth(std::int32_t const& AValue)
    {
        FWidth = AValue;
    }

    void SVideo::IHeight(std::int32_t const& AValue)
    {
        FHeight = AValue;
    }

    void SVideo::IMinimum(std::int32_t const& AValue)
    {
        FMinimum = AValue;
    }

    void SVideo::IMaximum(std::int32_t const& AValue)
    {
        FMaximum = AValue;
    }

    void SVideo::IRatio(double const& AValue)
    {
        FRatio = AValue;
    }

    void SVideo::IRatioInversed(double const& AValue)
    {
        FRatioInversed = AValue;
    }

    void SVideo::IImages(std::vector<std::shared_ptr<NImage::SImage>> const& AValue)
    {
        FImages = AValue;
    }

    NImage::SImage* SVideo::IAccessImageSpecific(const std::string& APath)
    {
        std::vector<std::shared_ptr<NImage::SImage>>::iterator LIterator
        {
            std::find_if(FImages.begin() , FImages.end() , [&](std::shared_ptr<NImage::SImage>& LImage){return(LImage->IIs(APath));})
        };
        return(LIterator->get());
    }

    NImage::SImage* SVideo::IAccessImageRandom()
    {
        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDistributor{0 , FImages.size() - 1};
        return(FImages[LDistributor(LGenerator)].get());
    }

    double SVideo::IConvertFromPixelToRectangleHorizontal(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FWidth));
    }

    double SVideo::IConvertFromPixelToRectangleVertical(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FHeight));
    }

    double SVideo::IConvertFromPixelToSquare(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FMinimum));
    }

    std::int32_t SVideo::IConvertFromRectangleToPixelHorizontal(double ARectangle)
    {
        return(static_cast<std::int32_t>(FWidth * ARectangle));
    }

    std::int32_t SVideo::IConvertFromRectangleToPixelVertical(double ARectangle)
    {
        return(static_cast<std::int32_t>(FHeight * ARectangle));
    }

    double SVideo::IConvertFromRectangleToSquareHorizontal(double ARectangle)
    {
        return(IConvertFromPixelToSquare(IConvertFromRectangleToPixelHorizontal(ARectangle)));
    }

    double SVideo::IConvertFromRectangleToSquareVertical(double ARectangle)
    {
        return(IConvertFromPixelToSquare(IConvertFromRectangleToPixelVertical(ARectangle)));
    }

    std::int32_t SVideo::IConvertFromSquareToPixel(double ASquare)
    {
        return(static_cast<std::int32_t>(FMinimum * ASquare));
    }

    double SVideo::IConvertFromSquareToRectangleHorizontal(double ASquare)
    {
        return(IConvertFromPixelToRectangleHorizontal(IConvertFromSquareToPixel(ASquare)));
    }

    double SVideo::IConvertFromSquareToRectangleVertical(double ASquare)
    {
        return(IConvertFromPixelToRectangleVertical(IConvertFromSquareToPixel(ASquare)));
    }

    void SVideo::IPostupdate()
    {
        SDL_RenderPresent(FRenderer);
    }

    SVideo::~SVideo()
    {
        FImages.clear();
        IMG_Quit();
        SDL_DestroyRenderer(FRenderer);
        SDL_DestroyWindow(FWindow);
    }
}