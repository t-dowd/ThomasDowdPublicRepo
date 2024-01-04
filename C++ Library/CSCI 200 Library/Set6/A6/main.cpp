/* CSCI 200: Assignment 6: A6 - SFML: Triangle Land
 *
 * Author: Thomas Dowd
 * Resources used: N/A
 *
 * For this assignment, we will write a program to read in a list of triangle data and draw an image comprised of those triangles.
 * 
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Triangle.h"
#include <cmath>
using namespace std;

int main() {
    // create a window
    vector <Triangle*> zoo; //CCreate a List of pointers POLYMORPHISm or whatever
    ifstream fileIn("triangles.dat"); 
    // ofstream std::cout("beans.txt");
    // Change to single function.
    char t; float x1; float y1; float x2; float y2; float x3; float y3; int redL; int greenL; int blueL;
    sf::Color ShapeColor;
    sf::Vector2f MainList[3];
    while(!fileIn.eof()) {
        // Data Values.
        fileIn >> t;
        fileIn >> x1;
        fileIn >> y1;
        MainList[0].x = x1;
        MainList[0].y = y1;
        fileIn >> x2;
        fileIn >> y2;
        MainList[1].x = x2;
        MainList[1].y = y2;
        fileIn >> x3;
        fileIn >> y3;
        MainList[2].x = x3;
        MainList[2].y = y3;
        fileIn >> redL;
        fileIn >> greenL;
        fileIn >> blueL;
        ShapeColor = sf::Color(redL,greenL,blueL,255); // Color of opaqity 255.
        if (t == 'S') {
            ScaleneTriangle* newTriangle = new ScaleneTriangle();
            if(!newTriangle->setCoordinates(MainList)){
                std::cout << "INVALD POINT: ";
                for (int i = 0; i < 3; i++){
                    std::cout << MainList[i].x << " " <<MainList[i].y << " ";
                }
                std::cout<<std::endl;
            }
            else{
                // newTriangle->draw(window);
                // window.display();
                newTriangle->setColor(ShapeColor);
                zoo.push_back(newTriangle);
            }


        } else if (t == 'I') {
            IsoscelesTriangle* newTriangle = new IsoscelesTriangle();
            if(!newTriangle->setCoordinates(MainList)){
                std::cout << "INVALD POINT: ";
                for (int i = 0; i < 3; i++){
                    std::cout << MainList[i].x << " " <<MainList[i].y << " ";
                }
                std::cout << "\n";
            }
            else{
                // newTriangle->draw(window);
                // window.display();
                newTriangle->setColor(ShapeColor);
                zoo.push_back(newTriangle);
            }

        } else {
            EquilateralTriangle* newTriangle = new EquilateralTriangle();
            if(!newTriangle->setCoordinates(MainList)){
                std::cout << "INVALD POINT: ";
                for (int i = 0; i < 3; i++){
                    std::cout << MainList[i].x << " " <<MainList[i].y << " ";
                }
                std::cout << "\n";
            }
            else{
                // newTriangle->draw(window);
                // window.display();
                newTriangle->setColor(ShapeColor);
                zoo.push_back(newTriangle);
            }
        }
        // window.display();
    }

    // create an event object once to store future events
    sf::Event event;
    sf::RenderWindow window( sf::VideoMode(640, 640), "A6 - SFML: Triangle Land" );
    // while the window is open
    while(window.isOpen() ) {
        // clear any existing contents
        window.clear();

        for (long long unsigned int i = 0; i < zoo.size(); i++){
            zoo.at(i)->draw(window);
        }
        window.display();
        // display the current contents of the window
        

        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == sf::Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
    }
    
    return 0;
}