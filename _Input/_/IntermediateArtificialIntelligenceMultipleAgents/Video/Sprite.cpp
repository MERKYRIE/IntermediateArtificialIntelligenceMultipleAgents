#include"IntermediateArtificialIntelligenceMultipleAgents.hpp"

#include"Image.hpp"
#include"Sprite.hpp"

namespace NIntermediateArtificialIntelligenceMultipleAgents::NVideo::NSprite
{
    SSprite::SSprite()
    {
        FImage = nullptr;
        FSource = {};
        FDestination = {};
        FRotation = 0.0;
    }

    NImage::SImage* const& SSprite::IImage()
    {
        return(FImage);
    }

    SDL_Rect const& SSprite::ISource()
    {
        return(FSource);
    }

    SDL_Rect const& SSprite::IDestination()
    {
        return(FDestination);
    }

    double const& SSprite::IRotation()
    {
        return(FRotation);
    }

    SSprite* SSprite::IImage(NImage::SImage* const& AImage)
    {
        FImage = AImage;
        return(this);
    }

    SSprite* SSprite::ISource(SDL_Rect const& AValue)
    {
        FSource = AValue;
        return(this);
    }

    SSprite* SSprite::IDestination(SDL_Rect const& AValue)
    {
        FDestination = AValue;
        return(this);
    }

    SSprite* SSprite::IRotation(double const& AValue)
    {
        FRotation = AValue;
        return(this);
    }

    SSprite* SSprite::ILoad(NImage::SImage* AImage)
    {
        FImage = AImage;
        FSource.w = FImage->IAccessWidth();
        FSource.h = FImage->IAccessHeight();
        FRotation = 0.0;
        return(this);
    }

    std::int32_t SSprite::IAccessSourceX()
    {
        return(FSource.x);
    }

    std::int32_t SSprite::IAccessSourceY()
    {
        return(FSource.y);
    }

    std::int32_t SSprite::IAccessSourceWidth()
    {
        return(FSource.w);
    }

    std::int32_t SSprite::IAccessSourceHeight()
    {
        return(FSource.h);
    }

    SSprite* SSprite::IAccessSourceXAbsolute(std::int32_t AX)
    {
        FSource.x = AX;
        return(this);
    }

    SSprite* SSprite::IAccessSourceYAbsolute(std::int32_t AY)
    {
        FSource.y = AY;
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthAbsolute(std::int32_t AWidth)
    {
        FSource.w = AWidth;
        return(this);
    }

    SSprite* SSprite::IAccessSourceHeightAbsolute(std::int32_t AHeight)
    {
        FSource.h = AHeight;
        return(this);
    }

    SSprite* SSprite::IAccessSourceXRelative(std::int32_t AX)
    {
        FSource.x += AX;
        return(this);
    }

    SSprite* SSprite::IAccessSourceYRelative(std::int32_t AY)
    {
        FSource.y += AY;
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthRelative(std::int32_t AWidth)
    {
        FSource.w += AWidth;
        return(this);
    }

    SSprite* SSprite::IAccessSourceHeightRelative(std::int32_t AHeight)
    {
        FSource.h += AHeight;
        return(this);
    }

    double SSprite::IAccessSourceXRectangle()
    {
        return(static_cast<double>(FSource.x) / static_cast<double>(FImage->IAccessWidth()));
    }

    double SSprite::IAccessSourceYRectangle()
    {
        return(static_cast<double>(FSource.y) / static_cast<double>(FImage->IAccessHeight()));
    }

    double SSprite::IAccessSourceWidthRectangle()
    {
        return(static_cast<double>(FSource.w) / static_cast<double>(FImage->IAccessWidth()));
    }

    double SSprite::IAccessSourceHeightRectangle()
    {
        return(static_cast<double>(FSource.h) / static_cast<double>(FImage->IAccessHeight()));
    }

    SSprite* SSprite::IAccessSourceXRectangleAbsolute(double AX)
    {
        FSource.x = static_cast<std::int32_t>(FImage->IAccessWidth() * AX);
        return(this);
    }

    SSprite* SSprite::IAccessSourceYRectangleAbsolute(double AY)
    {
        FSource.y = static_cast<std::int32_t>(FImage->IAccessHeight() * AY);
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthRectangleAbsolute(double AWidth)
    {
        FSource.w = static_cast<std::int32_t>(FImage->IAccessWidth() * AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessSourceHeightRectangleAbsolute(double AHeight)
    {
        FSource.h = static_cast<std::int32_t>(FImage->IAccessHeight() * AHeight);
        return(this);
    }

    SSprite* SSprite::IAccessSourceXRectangleRelative(double AX)
    {
        FSource.x += static_cast<std::int32_t>(FImage->IAccessWidth() * AX);
        return(this);
    }

    SSprite* SSprite::IAccessSourceYRectangleRelative(double AY)
    {
        FSource.y += static_cast<std::int32_t>(FImage->IAccessHeight() * AY);
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthRectangleRelative(double AWidth)
    {
        FSource.w += static_cast<std::int32_t>(FImage->IAccessWidth() * AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessSourceHeightRectangleRelative(double AHeight)
    {
        FSource.h += static_cast<std::int32_t>(FImage->IAccessHeight() * AHeight);
        return(this);
    }

    double SSprite::IAccessSourceXSquare()
    {
        return(static_cast<double>(FSource.x) / static_cast<double>(FImage->IAccessMinimum()));
    }

    double SSprite::IAccessSourceYSquare()
    {
        return(static_cast<double>(FSource.y) / static_cast<double>(FImage->IAccessMinimum()));
    }

    double SSprite::IAccessSourceWidthSquare()
    {
        return(static_cast<double>(FSource.w) / static_cast<double>(FImage->IAccessMinimum()));
    }

    double SSprite::IAccessSourceHeightSquare()
    {
        return(static_cast<double>(FSource.h) / static_cast<double>(FImage->IAccessMinimum()));
    }

    SSprite* SSprite::IAccessSourceXSquareAbsolute(double AX)
    {
        FSource.x = static_cast<std::int32_t>(FImage->IAccessMinimum() * AX);
        return(this);
    }

    SSprite* SSprite::IAccessSourceYSquareAbsolute(double AY)
    {
        FSource.y = static_cast<std::int32_t>(FImage->IAccessMinimum() * AY);
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthSquareAbsolute(double AWidth)
    {
        FSource.w = static_cast<std::int32_t>(FImage->IAccessMinimum() * AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessSourceHeightSquareAbsolute(double AHeight)
    {
        FSource.h = static_cast<std::int32_t>(FImage->IAccessMinimum() * AHeight);
        return(this);
    }

    SSprite* SSprite::IAccessSourceXSquareRelative(double AX)
    {
        FSource.x += static_cast<std::int32_t>(FImage->IAccessMinimum() * AX);
        return(this);
    }

    SSprite* SSprite::IAccessSourceYSquareRelative(double AY)
    {
        FSource.y += static_cast<std::int32_t>(FImage->IAccessMinimum() * AY);
        return(this);
    }

    SSprite* SSprite::IAccessSourceWidthSquareRelative(double AWidth)
    {
        FSource.w += static_cast<std::int32_t>(FImage->IAccessMinimum() * AWidth);
        return(this);
    }
    SSprite* SSprite::IAccessSourceHeightSquareRelative(double AHeight)
    {
        FSource.h += static_cast<std::int32_t>(FImage->IAccessMinimum() * AHeight);
        return(this);
    }

    std::int32_t SSprite::IAccessDestinationX()
    {
        return(FDestination.x);
    }

    std::int32_t SSprite::IAccessDestinationY()
    {
        return(FDestination.y);
    }

    std::int32_t SSprite::IAccessDestinationWidth()
    {
        return(FDestination.w);
    }

    std::int32_t SSprite::IAccessDestinationHeight()
    {
        return(FDestination.h);
    }

    SSprite* SSprite::IAccessDestinationXAbsolute(std::int32_t AX)
    {
        FDestination.x = AX;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYAbsolute(std::int32_t AY)
    {
        FDestination.y = AY;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthAbsolute(std::int32_t AWidth)
    {
        FDestination.w = AWidth;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightAbsolute(std::int32_t AHeight)
    {
        FDestination.h = AHeight;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationXRelative(std::int32_t AX)
    {
        FDestination.x += AX;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYRelative(std::int32_t AY)
    {
        FDestination.y += AY;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthRelative(std::int32_t AWidth)
    {
        FDestination.w += AWidth;
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightRelative(std::int32_t AHeight)
    {
        FDestination.h += AHeight;
        return(this);
    }

    double SSprite::IAccessDestinationXRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleHorizontal(FDestination.x));
    }

    double SSprite::IAccessDestinationYRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleVertical(FDestination.y));
    }

    double SSprite::IAccessDestinationWidthRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleHorizontal(FDestination.w));
    }

    double SSprite::IAccessDestinationHeightRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleVertical(FDestination.h));
    }

    SSprite* SSprite::IAccessDestinationXRectangleAbsolute(double AX)
    {
        FDestination.x = GVideo.IConvertFromRectangleToPixelHorizontal(AX);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYRectangleAbsolute(double AY)
    {
        FDestination.y = GVideo.IConvertFromRectangleToPixelVertical(AY);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthRectangleAbsolute(double AWidth)
    {
        FDestination.w = GVideo.IConvertFromRectangleToPixelHorizontal(AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightRectangleAbsolute(double AHeight)
    {
        FDestination.h = GVideo.IConvertFromRectangleToPixelVertical(AHeight);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationXRectangleRelative(double AX)
    {
        FDestination.x += GVideo.IConvertFromRectangleToPixelHorizontal(AX);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYRectangleRelative(double AY)
    {
        FDestination.y += GVideo.IConvertFromRectangleToPixelVertical(AY);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthRectangleRelative(double AWidth)
    {
        FDestination.w += GVideo.IConvertFromRectangleToPixelHorizontal(AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightRectangleRelative(double AHeight)
    {
        FDestination.h += GVideo.IConvertFromRectangleToPixelVertical(AHeight);
        return(this);
    }

    double SSprite::IAccessDestinationXSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.x));
    }

    double SSprite::IAccessDestinationYSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.y));
    }

    double SSprite::IAccessDestinationWidthSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.w));
    }

    double SSprite::IAccessDestinationHeightSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.h));
    }

    SSprite* SSprite::IAccessDestinationXSquareAbsolute(double AX)
    {
        FDestination.x = GVideo.IConvertFromSquareToPixel(AX);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYSquareAbsolute(double AY)
    {
        FDestination.y = GVideo.IConvertFromSquareToPixel(AY);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthSquareAbsolute(double AWidth)
    {
        FDestination.w = GVideo.IConvertFromSquareToPixel(AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightSquareAbsolute(double AHeight)
    {
        FDestination.h = GVideo.IConvertFromSquareToPixel(AHeight);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationXSquareRelative(double AX)
    {
        FDestination.x += GVideo.IConvertFromSquareToPixel(AX);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationYSquareRelative(double AY)
    {
        FDestination.y += GVideo.IConvertFromSquareToPixel(AY);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationWidthSquareRelative(double AWidth)
    {
        FDestination.w += GVideo.IConvertFromSquareToPixel(AWidth);
        return(this);
    }

    SSprite* SSprite::IAccessDestinationHeightSquareRelative(double AHeight)
    {
        FDestination.h += GVideo.IConvertFromSquareToPixel(AHeight);
        return(this);
    }

    SSprite* SSprite::IDraw()
    {
        FImage->IDraw(FSource , {FDestination.x + FDestination.w / 2 , FDestination.y + FDestination.h / 2 , FDestination.w , FDestination.h} , FRotation);
        return(this);
    }
}