#pragma once

namespace NIntermediateArtificialIntelligenceMultipleAgents::NVideo
{
    namespace NImage
    {
        struct SImage;
    }

    namespace NSprite
    {
        struct SSprite;
    }
    
    inline struct SVideo
    {
        SDL_Window* FWindow;
        SDL_Renderer* FRenderer;
        std::int32_t FWidth;
        std::int32_t FHeight;
        std::int32_t FMinimum;
        std::int32_t FMaximum;
        double FRatio;
        double FRatioInversed;
        std::vector<std::shared_ptr<NImage::SImage>> FImages;

        SVideo();
        void IPreupdate();

        SDL_Window* const& IWindow();
        SDL_Renderer* const& IRenderer();
        std::int32_t const& IWidth();
        std::int32_t const& IHeight();
        std::int32_t const& IMinimum();
        std::int32_t const& IMaximum();
        double const& IRatio();
        double const& IRatioInversed();
        std::vector<std::shared_ptr<NImage::SImage>> const& IImages();

        void IWindow(SDL_Window* const& AValue);
        void IRenderer(SDL_Renderer* const& AValue);
        void IWidth(std::int32_t const& AValue);
        void IHeight(std::int32_t const& AValue);
        void IMinimum(std::int32_t const& AValue);
        void IMaximum(std::int32_t const& AValue);
        void IRatio(double const& AValue);
        void IRatioInversed(double const& AValue);
        void IImages(std::vector<std::shared_ptr<NImage::SImage>> const& AValue);

        NImage::SImage* IAccessImageSpecific(const std::string& APath);
        NImage::SImage* IAccessImageRandom();
        double IConvertFromPixelToRectangleHorizontal(std::int32_t APixel);
        double IConvertFromPixelToRectangleVertical(std::int32_t APixel);
        double IConvertFromPixelToSquare(std::int32_t APixel);
        std::int32_t IConvertFromRectangleToPixelHorizontal(double ARectangle);
        std::int32_t IConvertFromRectangleToPixelVertical(double ARectangle);
        double IConvertFromRectangleToSquareHorizontal(double ARectangle);
        double IConvertFromRectangleToSquareVertical(double ARectangle);
        std::int32_t IConvertFromSquareToPixel(double ASquare);
        double IConvertFromSquareToRectangleHorizontal(double ASquare);
        double IConvertFromSquareToRectangleVertical(double ASquare);

        void IPostupdate();
        ~SVideo();
    }
    GVideo;
}