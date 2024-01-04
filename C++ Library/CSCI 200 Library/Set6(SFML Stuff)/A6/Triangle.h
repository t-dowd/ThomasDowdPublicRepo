#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Triangle {
    public:
        Triangle();
        ~Triangle();
        void setColor(const sf::Color c);
        void draw(sf::RenderTarget& window);
        virtual bool setCoordinates(sf::Vector2f[3]) = 0;
        
    protected:
        int numVertices;
        sf::Vector2f coordinates[3];
    private:
        sf::Color color;
};

class ScaleneTriangle : public Triangle {
    public:
        bool setCoordinates(sf::Vector2f[3]) override;
};

class IsoscelesTriangle : public Triangle {
    public:
        bool setCoordinates(sf::Vector2f[3]) override;
};

class EquilateralTriangle : public Triangle {
    public:
        bool setCoordinates(sf::Vector2f[3]) override;
};
#endif