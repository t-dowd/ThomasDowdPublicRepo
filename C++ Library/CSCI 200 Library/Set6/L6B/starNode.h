#ifndef MAZEFUNC_h
#define MAZEFUNC_h

#include <fstream> 

struct starNode{
    public:
        starNode();
        ~starNode();
        starNode* makeStarNode(std::ifstream&);
        double getXcord();
        double getYcord();
        double getBright();
        float getXadjust();
        float getYadjust();
        void setXadjust(float);
        void setYadjust(float);
        void setXcord(double);
        void setYcord(double);
        void setBright(double);
        float getTransformedX(int);
        float getTransformedY(int);
    private:
        double mXCord;
        double mYCord;
        double mBright;
        float mXAdjustedX;
        float mYAdjustedY;
};


#endif