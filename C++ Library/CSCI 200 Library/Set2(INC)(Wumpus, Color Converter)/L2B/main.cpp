// Thomas Dowd 
// Lab 2B - Color Space Converter

#include<cmath>
#include<iostream>
#include "color_conversion.h"

using namespace::std;


int main(){
    int red = 0;int green = 0;int blue = 0; // Initializing Variables for RGB
    double hue = 0.0;double saturation = 0.0;double value = 0.0; // Initalizing Variables for HSV

    int choicemaker = 0;
    cout << "Press the corresponding keybind with the responding function\nRGB to HSV   1\nHSV to RGB   2\n"; cin >> choicemaker;
    if (choicemaker == 1){
        cout << "\nRGB to HSV\n";
        cout << "Input Int for RED: "; cin >> red;
        cout << "\nInput Int for GREEN: "; cin>> green;
        cout << "\nInput Int for BLUE: "; cin>> blue;
        rgb_to_hsv(red, green, blue, hue, saturation, value);
        cout << "\nHue is: " << hue << "\nSaturation is: " << saturation << "\nValue is: "<< value;
    }
    else {
        cout << "\nHSV to RGB\n";
        cout << "Input Double for HUE: "; cin >> hue;
        cout << "\nInput Double for Saturation: "; cin>> saturation;
        cout << "\nInput Double for Value: "; cin>> value;
        hsv_to_rgb(hue, saturation, value, red, green, blue);
        cout << "\nRed is: "<< red << "\nGreen is: "<< green << "\nBlue is: " << blue;
    }
    return 0;
}