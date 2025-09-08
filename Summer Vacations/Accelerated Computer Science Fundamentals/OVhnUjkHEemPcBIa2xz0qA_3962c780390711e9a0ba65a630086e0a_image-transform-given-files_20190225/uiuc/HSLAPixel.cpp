/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace uiuc {
    HSLAPixel::HSLAPixel()
{
  h = 0.0;
  s = 0.0;
  l = 1.0;
  a = 1.0;
}
HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha)
{
  h = hue;
  s = saturation;
  l = luminance;
  a = alpha;
}
}
