#pragma once


#include "uiuc/PNG.h"           // ✅ Gives access to uiuc::PNG
#include "uiuc/HSLAPixel.h"     // ✅ Needed for HSLAPixel



namespace uiuc
{
    
}

PNG grayscale(PNG image);
PNG createSpotlight(PNG image, int centerX, int centerY);
PNG illinify(PNG image);
PNG watermark(PNG firstImage, PNG secondImage);
