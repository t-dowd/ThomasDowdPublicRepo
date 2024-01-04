#include "color_conversion.h"
#include <iostream>
#include <cmath>

using namespace std;
void rgb_to_hsv(const int red, const int green, const int blue, double& hue, double& saturation, double& value){
    const double PI = 3.14159265359;
    double maxM = 0.0; // for finding the max value, wouldve used lists but we dont know how yet
    double minM = 0.0;

    if (red == green && red == blue){ // all equal
        maxM = red;
        minM = green;
       }
    else if ( red > green && red > blue){ // red max 
        maxM = red;
        if (green >= blue){
            minM = blue;
        }
        else{minM = green;}
    }
    else if (green > red && green > blue){ // green max
        maxM = green;
        if (red >= blue){
            minM = blue;
        }
        else {minM = red;}
    }
    else if (blue > red && blue > green){ // blue max
        maxM = blue;
        if (red >= green){
            minM = green;
        }
        else {minM = red;}
    }
    
    value = (double) maxM / 255;

    if (maxM > 0){
        saturation = (double)(1 - (minM / maxM));
    }
    else{saturation = 0;}

    if (green > blue){
        hue = acos((red - (.5 * green) - (.5 * blue)) / sqrt(pow(red,2) + pow(green,2) + pow(blue,2) - (red * green) - (red * blue) - (green * blue)));
        hue = hue * (180 / PI);
    }
    else if(green < blue){
        hue = (2* PI) - acos((red - (.5 * green) - (.5 * blue)) / sqrt(pow(red,2) + pow(green,2) + pow(blue,2) - (red * green) - (red * blue) - (green * blue)));
        
        hue = hue * (180 / PI);
    }
    else {hue = 0;}
    
}

void hsv_to_rgb(const double hue, const double saturation, const double value, int& red, int& green, int& blue){
    double M = 0.0; M = 255 * value;
    double m = 0.0; m = M * (1-saturation);
    double z = 0.0;
    // double a = hue / 60;
    double b = std::fmod((hue/60),2);
    // Modulus does not accept floats or constants. I had to use fmod, may lead to problems...
    z =  (M - m)*(1- abs((b)-1));

    if (hue <60 && hue >= 0){
        red = M;
        green = z + m;
        blue = m;   
    }
    else if (hue >= 60 && hue < 120){
        red = z + m;
        green = M;
        blue = m;
    }
    else if (hue >= 120 && hue < 180){
        red = m;
        green = M;
        blue = z + m;
    }
    else if (hue >= 180 && hue < 240){
        red = m;
        green = z + m;
        blue = M;

    }
    else if (hue >= 240 && hue < 300){
        red = z + m;
        green = m;
        blue = M;
    }
    else if ( hue >= 300 && hue < 360){
        red = M;
        green = m;
        blue = z+m;
    }
}