#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test#32" );
    int x = 0;

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    // Load a sprite to display
        sf::Texture texture;
        if (!texture.loadFromFile("data/bubble.png"))
            return EXIT_FAILURE;
        sf::Sprite sprite(texture);
    // perform any file processing once before draw loop begins
    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("*SHAPE*", font, 70);
    text.setPosition(120,120);
    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();
        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // place any draw commands here to display in the window
        sf::CircleShape shape(20);
        // window.draw(shape);
        window.draw(sprite);
        window.draw(text);
        text.rotate(x);
        x++;
        x = x % 360;
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}