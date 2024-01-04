#ifndef COLOR_CONVERSION_H
#define COLOR_CONVERSION_H

/**
 * @brief Converts RGB values to HSV
 * 
 * @param red 
 * @param green 
 * @param blue 
 * @param hue 
 * @param saturation 
 * @param value 
 */
void rgb_to_hsv(const int red, const int green, const int blue, double& hue, double& saturation, double& value);
/**
 * @brief Converts HSV values to RGB
 * 
 * @param hue 
 * @param saturation 
 * @param value 
 * @param red 
 * @param green 
 * @param blue 
 */
void hsv_to_rgb(const double hue, const double saturation, const double value, int& red, int& green, int& blue);

#endif