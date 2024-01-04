#include "starNode.h"
#include "starCraftFunctions.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
// #include <SFML/Graphics.hpp> 
starNode::starNode(){
    this->mBright = 0.0;
    this->mXCord = 0.0;
    this->mYCord = 0.0;
    this->mXAdjustedX = 0.0;
    this->mYAdjustedY = 0.0;
}
starNode::~starNode(){};
starNode* starNode::makeStarNode(std::ifstream& fileIn){
    starNode* tempNode = new starNode;
    return tempNode;
}
double starNode::getBright(){
    return this->mBright;
}
double starNode::getXcord(){
    return this->mXCord;
}
double starNode::getYcord(){
    return this->mYCord;
}
void starNode::setXcord(double xCord){
    this->mXCord = xCord;
}
void starNode::setYcord(double yCord){
    this->mYCord = yCord;
}
void starNode::setBright(double bright){
    this->mBright = bright;
}
float starNode::getXadjust(){
    return this->mXAdjustedX;
}
float starNode::getYadjust(){
    return this->mYAdjustedY;
}
void starNode::setXadjust(float X){
    this->mXAdjustedX = X;
}
void starNode::setYadjust(float Y){
    this->mYAdjustedY = Y;
}
float starNode::getTransformedX(int WIDTH){
    this->mXAdjustedX = ((this->mXCord) + 1) * WIDTH / 2;
    return this->mXAdjustedX;
}
float starNode::getTransformedY(int HEIGHT){
    this->mYAdjustedY = (-(this->mYCord) + 1) * HEIGHT / 2;
    return this->mYAdjustedY;
}

bool enter_star_file(std::ifstream& wumpusFileIn){
    std::string wumpusFileName = " ";
    std::cout << "Enter Maze (EXPLICITLY) file to read from: ";
    std::cin >> wumpusFileName;
    wumpusFileIn.open(wumpusFileName);
    if ((wumpusFileIn.is_open() == true)){
        std::cout << "File '" << wumpusFileName << "' has been successfully opened\n" << std::endl;
        return true;
    }
    else{
        std::cout << "File Not Availiable, or something went wrong\nTry banging your head on the desk and trying again!" << std::endl;
        return false;
    }
}

void file_to_vector(std::ifstream& fileIn, std::vector <starNode*>& mainlist){
    double toss;
    double tempX;
    double tempY;
    double bright;
    while (!fileIn.eof()){
        starNode* tempnode = new starNode;
        fileIn >> tempX;
        tempnode->setXcord(tempX);
        fileIn >> tempY;
        tempnode->setYcord(tempY);
        fileIn >> toss;
        fileIn >> bright;
        tempnode->setBright(bright);
        fileIn >> toss;
        fileIn >> toss;
        tempnode->getTransformedX(640);
        tempnode->getTransformedY(640);
        mainlist.push_back(tempnode);
    }
}
void vector_to_file(std::string beans_filename, std::vector <starNode*> mainlist){
    std::ofstream beans;
    beans.open(beans_filename);
        for (unsigned int i = 0; i < mainlist.size(); i++){
            // beans << mainlist.at(i)->getXcord() << "|";
            // beans << mainlist.at(i)->getYcord() << "|";
            // beans << mainlist.at(i)->getBright() << "|";
            // beans << mainlist.at(i)->getXadjust() << "|";
            // beans << mainlist.at(i)->getYadjust() << "|";
            // beans << "\n";
        }
    beans.close();
}
void draw_stars(std::vector <starNode*> vecMain){
    // create a window
    sf::RenderWindow window( sf::VideoMode(640, 640), "Stars" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    // Load a sprite to display
        // sf::Texture texture;
        // if (!texture.loadFromFile("data/bubble.png"))
        //     return;
        // sf::Sprite sprite(texture);
    // perform any file processing once before draw loop begins
        // sf::Font font;
        // if (!font.loadFromFile("data/arial.ttf"))
        //     return;
        // sf::Text text("Hello World", font, 50);
    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    sf::Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();
        /////////////////////////////////////
        // BEGIN DRAWING HERE
        sf::CircleShape starShape(2);
        for (unsigned int i = 0; i < vecMain.size(); i++){
            starShape.setPosition(sf::Vector2f(vecMain.at(i)->getXadjust(), vecMain.at(i)->getYadjust()));
            // place any draw commands here to display in the window
            int shadeofgrey = (int)( ( 255.0 * ((7.96)-vecMain.at(i)->getBright()) ) / 7.96 );
            starShape.setFillColor(sf::Color(shadeofgrey,shadeofgrey,shadeofgrey));
            // sf::CircleShape shape(20);
            window.draw(starShape);
        }
        // window.draw(text);
        // window.draw(sprite);
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == sf::Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }
}