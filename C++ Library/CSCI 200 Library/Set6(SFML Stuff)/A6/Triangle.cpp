#include "Triangle.h"
#include <cmath>
Triangle::Triangle() { // Default constructor
    numVertices = 0;
    for (int i = 0; i < 3; i++){
        coordinates[i].x = 0;
        coordinates[i].y = 0;
    }
}

void Triangle::setColor(const sf::Color c) {// Base setColor function that is passed to each child class. 
    color = c;
}
void Triangle::draw(sf::RenderTarget& window) { // Base Draw function that is passed to each child class. 
    sf::ConvexShape shapetoscreen;
    shapetoscreen.setPointCount(3);
    shapetoscreen.setPoint(0,coordinates[0]);
    shapetoscreen.setPoint(1,coordinates[1]);
    shapetoscreen.setPoint(2,coordinates[2]);
    shapetoscreen.setFillColor(color);
    window.draw(shapetoscreen);
}
bool ScaleneTriangle::setCoordinates(sf::Vector2f incoord[3]) { // Scalene triangle coodiate generator and validator
    double side1 = pow(pow((incoord[1].x - incoord[0].x),2) + pow((incoord[1].y - incoord[0].y),2),.5);
    double side2 = pow(pow((incoord[2].x - incoord[1].x),2) + pow((incoord[2].y - incoord[1].y),2),.5);
    double side3 = pow(pow((incoord[0].x - incoord[2].x),2) + pow((incoord[0].y - incoord[2].y),2),.5);
    if((side1 != 0) && (side2 != 0) && (side3 != 0) && (side1 + side2 > side3)) {
        ScaleneTriangle::coordinates[0].x = incoord[0].x;
        ScaleneTriangle::coordinates[0].y = incoord[0].y;
        ScaleneTriangle::coordinates[1].x = incoord[1].x;
        ScaleneTriangle::coordinates[1].y = incoord[1].y;
        ScaleneTriangle::coordinates[2].x = incoord[2].x;
        ScaleneTriangle::coordinates[2].y = incoord[2].y;
        return true;
    }
    return false;
}

bool IsoscelesTriangle::setCoordinates(sf::Vector2f incoord[3]){ // Isoceles Triangle coordinae generator and validator. 
    double side1 = pow(pow((incoord[1].x - incoord[0].x),2) + pow((incoord[1].y - incoord[0].y),2),.5);
    double side2 = pow(pow((incoord[2].x - incoord[1].x),2) + pow((incoord[2].y - incoord[1].y),2),.5);
    double side3 = pow(pow((incoord[0].x - incoord[2].x),2) + pow((incoord[0].y - incoord[2].y),2),.5);
    if((side1 != 0) && (side2 != 0) && (side3 != 0) && (side1 + side2 > side3)) {
        IsoscelesTriangle::coordinates[0].x = incoord[0].x;
        IsoscelesTriangle::coordinates[0].y = incoord[0].y;
        IsoscelesTriangle::coordinates[1].x = incoord[1].x;
        IsoscelesTriangle::coordinates[1].y = incoord[1].y;
        IsoscelesTriangle::coordinates[2].x = incoord[2].x;
        IsoscelesTriangle::coordinates[2].y = incoord[2].y;
        return true;
    }
    return false;
}

bool EquilateralTriangle::setCoordinates(sf::Vector2f incoord[3]){ // Ewualilater coordinate generator and validator. 
    double side1 = pow(pow((incoord[1].x - incoord[0].x),2) + pow((incoord[1].y - incoord[0].y),2),.5);
    double side2 = pow(pow((incoord[2].x - incoord[1].x),2) + pow((incoord[2].y - incoord[1].y),2),.5);
    double side3 = pow(pow((incoord[0].x - incoord[2].x),2) + pow((incoord[0].y - incoord[2].y),2),.5);
    if((side1 != 0) && (side2 != 0) && (side3 != 0) && (side1 + side2 > side3)) {
        EquilateralTriangle::coordinates[0].x = incoord[0].x;
        EquilateralTriangle::coordinates[0].y = incoord[0].y;
        EquilateralTriangle::coordinates[1].x = incoord[1].x;
        EquilateralTriangle::coordinates[1].y = incoord[1].y;
        EquilateralTriangle::coordinates[2].x = incoord[2].x;
        EquilateralTriangle::coordinates[2].y = incoord[2].y;
        return true;
    }
    return false;
}