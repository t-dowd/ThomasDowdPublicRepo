#include "Sweep.h"
#include <sstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

void GameNode::setmMineTrue(){
    this->mMine = true;
}
bool GameNode::getmMine() const{
    return this->mMine;
}
void GameNode::setmMineFalse(){
    this->mMine = false;
}
void GameNode::setFlagged(bool Value){
    this->flagged = Value;
}
bool GameNode::getFlag()const{
    return this->flagged;
}
void firstBoot(){
    // This remembers your choice for rules and terminal splash screen. 
    int choice = -1;
    int sentinal;
    char toss;
    ifstream dontrunagain;
    dontrunagain.open("data/Sentinal.txt"); // If this is 1 proceed and read file, if not skip the splash screen
    dontrunagain >> sentinal;
    if (sentinal == 0){
        dontrunagain.close();
        return;
    }
    std::string line;
    ifstream rules;
    ifstream firstBoot;
    firstBoot.open("data/FirstBoot.txt");
    ofstream firstBoot2;
    firstBoot >> toss;
    while (!firstBoot.eof())
    {
        getline (firstBoot,line); // Reads the Welcome message and such
        cout << line << '\n';
    }
    firstBoot.close();
    cin >> choice;
    if (choice == 1){
        rules.open("data/rules.txt");
        while(!rules.eof()){
            getline (rules,line);
            cout << line << '\n';
        }
        rules.close();
        cin >> choice;
    }
    else if (choice == 2){
        cout << "Made by Thomas Dowd" << endl;
    }
    if (choice == 3){
        firstBoot2.open("data/Sentinal.txt");
        firstBoot2 << 0;
    }
    // Return to main
}
void fullprintKey(GameNode** ListFromMain,int Width, int Height){
    for (int i = 0; i < Width; i++) {
        for (int j = 0; j <Height; j++) {
            std::cout << " " << ListFromMain[j][i].getmMine() << " ";
            // std::cout <<" (" <<ListFromMain[j][i].xVal << "," << ListFromMain[j][i].yVal << "): " << ListFromMain[j][i].mine;
        }
    std::cout << std::endl;
    }
}
void gameframe(GameNode** gameboard,int Width, int Height,bool onetime){
    if (onetime == true){
        int getxvalin; int getyvalin;
        std::cout << "enter starting x: "; std::cin >> getyvalin; std::cout << "\nenter starting y: "; std::cin >> getxvalin;
        spreader(gameboard,getxvalin,getyvalin,Width, Height);
    }
    for (int x = 0; x < Width; x++) {
        for (int j = 0; j <Height; j++) {
            if (gameboard[j][x].shown == false && gameboard[j][x].getmMine() != true){
                std::cout << " " << "#" << " ";
            }
            else if(gameboard[j][x].shown == true){
            std::cout << " " << gameboard[j][x].getmMine() << " ";}
            // std::cout <<" (" <<ListFromMain[j][i].xVal << "," << ListFromMain[j][i].yVal << "): " << ListFromMain[j][i].mine;
            else{
            std::cout << " " << gameboard[j][x].getmMine()<< " ";    
            }
        }   
    std::cout << std::endl;
    }
}
GameNode* makeNodeForValue(int x, int y, int minesclose){
    GameNode* tempGameNode = new GameNode;
    tempGameNode->numMinesSurrounded = minesclose;
    tempGameNode->shown = false;
    tempGameNode->setmMineFalse();
    tempGameNode->setFlagged(false);
    tempGameNode->xVal = x;
    tempGameNode->yVal = y;
    return tempGameNode;
}
GameNode** CreateBoard(int sizey,int sizeX, int bombNum){
    GameNode** GameBoard = new GameNode*[sizeX]; // Allocates space and ininitalizes the array.
    int mineX = 0; int mineY = 0;
    for (int i = 0; i < sizeX;i++){
        GameBoard[i] = new GameNode[sizey];     
    }
    for (int y = 0; y < sizeX; y++){
        for (int x = 0; x < sizey;x++){
            GameBoard[y][x] = *makeNodeForValue(x,y,0);
        }
    // std::cout<<std::endl;
    }
    //~~~~~ Creating the Bombs ~~~~~~
    for (int i = 0; i < bombNum; i++){
        randomNumberGenerator(mineX,mineY,sizey,sizeX);
        GameBoard[mineY][mineX].setmMineTrue();
    }
    for (int y = 0; y<sizeX; y++){ // Check all aroudn and if a mine is there, make all surroudning nodes have +1 Surrounded attribute.
        for(int x =0; x<sizey;x++){

            if (GameBoard[y][x].getmMine() == false){
                if (x+1 < sizey && GameBoard[y][x+1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (x-1 >= 0 && GameBoard[y][x-1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (y+1 < sizeX && GameBoard[y+1][x].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (y-1 >= 0 && GameBoard[y-1][x].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (x+1 < sizey && y+1 < sizeX && GameBoard[y+1][x+1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (x+1 < sizey && y-1 >= 0 && GameBoard[y-1][x+1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (x-1 >= 0 && y+1 < sizeX && GameBoard[y+1][x-1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
                if (x-1 >= 0 && y-1 >= 0 && GameBoard[y-1][x-1].getmMine()){
                    GameBoard[y][x].numMinesSurrounded++;
                }
            }
        }
        
    }
        return GameBoard; 
}
// Three overloaded and fraknly inefficent functions to depict the three diffrent random sitiations.
void randomNumberGenerator(int& rollx,int& rolly,int sizeX, int sizeY){
    rollx = (rand() % sizeX);
    rolly = (rand() % sizeY); 
    return;
}
void randomNumberGenerator(int& roll){
    roll = (rand() % 3);
    return;
}
void randomNumberGenerator(int& roll, bool myBool){
    roll = (rand() % 2);
    return;
}

void spreader(GameNode** ListMain,int y, int x,int Width, int Height ){

    
    int randspread; // The random value passed to each x and y value . 
    int counter = 0;
    ListMain[x][y].shown = true;
    while (counter != 2){
        // the loop is the same for the following.

        //  = = = Template for Random function = = = //

        randomNumberGenerator(randspread); // generate a random number
        try{
            if (x+randspread > Width){    // Check the new random x and y values are in bounds.
                throw std::exception();
            }
            else if (!ListMain[x+randspread][y].getmMine()); // If new x and y are on a Mine, DONT reveal
            else{
                ListMain[x+randspread][y].shown = true;      // If the x and y are on a Mine, reveal and move on.
            }
        } 

        // = = = End Template = = = //

        catch(...){}
        randomNumberGenerator(randspread);
        try{ 
            if (x-randspread< 0){
                throw std::exception();
            }
            else if (ListMain[x-randspread][y].getmMine());
            else{
                ListMain[x-randspread][y].shown = true; 
            }
        } catch(...){} // west
        randomNumberGenerator(randspread);
        try{
            if (y+randspread > Height){
                throw std::exception();
            }
            else if(ListMain[x][y+randspread].getmMine());
            else{
                ListMain[x][y+randspread].shown = true;
            }
        } catch(...){} // south
        randomNumberGenerator(randspread);
        try{
            if (y-1 < 0){
                throw std::exception();
            }
            else if(ListMain[x][y+randspread].getmMine());
            else{
                ListMain[x][y-randspread].shown = true;
            }
        } catch(...){} // north
        counter++;
    }
    counter = 0;
    while(counter != 3){
        bool mybool;

         //  = = = Template for Random Diagional function = = = //

        randomNumberGenerator(randspread,mybool);
        if (x+ randspread<= Width && y+randspread <= Height){ // Check the new random x and y values are in bounds.
            if (ListMain[x+randspread][y+randspread].getmMine()); // If new x and y are on a Mine, DONT reveal
            else{
                ListMain[x+randspread][y+randspread].shown = true; // If the x and y are on a Mine, reveal and move on.
            }
        }

        // = = = End Template = = =//

        randomNumberGenerator(randspread,mybool);
        if(x+randspread <= Width && y-randspread >= 0){
            if ( ListMain[x+randspread][y-randspread].getmMine());
            else ListMain[x+randspread][y-randspread].shown = true;
        }
        randomNumberGenerator(randspread,mybool);
        if(x-randspread >= 0 && y+randspread <= Height){
            if(ListMain[x-randspread][y+randspread].getmMine());
            else ListMain[x-randspread][y+randspread].shown = true;
        }
        randomNumberGenerator(randspread,mybool);
        if(x-randspread >= 0 && y-randspread >= 0){
            if (ListMain[x-randspread][y-randspread].getmMine());
            else ListMain[x-randspread][y-randspread].shown = true;
        }
        counter++;
    }
}
void fullprint(GameNode** gameboard,int Width, int Height){ // Archived terminal print of the board
    for (int X = 0; X < Width; X++){
    std::cout << "\n=====================" << std::endl;
    for (int Y = 0; Y < Height; Y++){
            std::cout<< "Square (" << gameboard[Y][X].xVal << " , " <<  gameboard[Y][X].yVal  << ")" <<
                "\nMine: " << gameboard[Y][X].getmMine() << "\nShown: "<<gameboard[Y][X].shown << 
                "\n+ + + + + + +" <<std::endl;
        }
    }
}
void drawGameBoard(GameNode** ListFromMain,int GIVENWIDTH, int GIVENHEIGHT){
    // The main SFML game loop.
    float gridSizeX = 50.f; // IF BROKEN FOR NO RESON SEE HERE 
    float gridSizeY = 71.f;

    // These values are Factors of 9 and 13, the size of the board, so there is no chance our board has overlaps
    // or unused grid space. 

    unsigned int WidthRender = 650;  // Length and Width of the Board in Pixels
    unsigned int HeightRender = 639;

    // These values are Factors of 9 and 13, the size of the board, so there is no chance our board has overlaps
    // or unused grid space. 


    bool doOnce = true; 

    // = = = Font Objects = = = //
    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf"))
        return;
    sf::Text text(".", font, 10);
    sf::Text MinesAround("Mines",font, 50);
    sf::Text flag("Flagged", font, 50);
    flag.setFillColor(sf::Color(254,134,46));

    // = = = Rectange Objects = = =//
    // Hidden Tile
    sf::RectangleShape tileHidden;
    // Shown Tile
    sf::RectangleShape tileShown;
    tileHidden.setSize(sf::Vector2f(gridSizeX,gridSizeY));
        tileHidden.setOutlineColor(sf::Color(100,100,100));
        tileHidden.setOutlineThickness(4);
        tileHidden.setFillColor(sf::Color(176,113,186));
        tileShown.setSize(sf::Vector2f(gridSizeX,gridSizeY));
        tileShown.setOutlineColor(sf::Color(100,100,100));
        tileShown.setOutlineThickness(4);
        tileShown.setFillColor(sf::Color(50,50,50));

    // = = = Mouse Position Vectors = = =//
    sf::Vector2i mousePosSystem;
    sf::Vector2u mouseGrid;

    // = = = CHEATING?? = = =//
    // This line is commented out by default, if the user would like to have the answer key 
    // while they play Un-commnent the next line.
        // fullprintKey(ListFromMain,9,13);
	// = = = Render Window = = = //

    sf::RenderWindow window(sf::VideoMode(WidthRender, HeightRender), "MineSweeper");

    // = = = Grid Initialization = = = //
    // The grid is a invisible mapping of the board that graphs x/y to the tiles. 
    // Is static and invisible, used to track the mouse location and mainly mouse clicks.
    sf::RectangleShape grid(sf::Vector2f(gridSizeX,gridSizeY));


    // float cameraDPI = 100.f;

	while (window.isOpen())
	{
        
        // = = = Main Game Loop = = =//

        // = = = Mouse = = =//
        sf::Vector2i mousePosSystem = sf::Mouse::getPosition(window); // 0,0 top left of window
        if(mousePosSystem.x >= 0.f && mousePosSystem.x < WidthRender && mousePosSystem.y >= 0.f && mousePosSystem.y < HeightRender){
            mouseGrid.x = mousePosSystem.x / gridSizeX; // Current location of the mosue.
            mouseGrid.y = mousePosSystem.y / gridSizeY;
        }
        
        // Below is the code to display mouse x and y positions. If youre confused on how the mouse is tracked 
        // un-comment the following 4 lines.

                // std::stringstream printToSfml;
                // printToSfml << "X-Cord: "<< mouseGrid.x << "Y-Cord: " << mouseGrid.y << "\nMouse Presed:" << sf::Mouse::isButtonPressed(sf::Mouse::Left) <<
                //     "\nMinesSurrounded: " << ListFromMain[mouseGrid.x][ mouseGrid.y].numMinesSurrounded;
                // text.setString(printToSfml.str());

        //Grid Procedurally Generated
        

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
            }
            if (event.type == sf::Event::Resized){
                std::cout << "Window was resized\n\nDO NOT RESIZE WINDOW\n\nERROR: Sweep.cpp:239:30: error: sf::Event::Resized.window Null sf::Event::Resized RANGE" << endl;
                window.close();
            }            
		}
        
        if (!doOnce){ // If this is the first time, "Blow Up" the starting squares.
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                ListFromMain[mouseGrid.x][mouseGrid.y].shown = true;
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                ListFromMain[mouseGrid.x][mouseGrid.y].setFlagged(true);
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)){
                ListFromMain[mouseGrid.x][mouseGrid.y].setFlagged(false);
            }
        }
        else{
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle)){
                ListFromMain[mouseGrid.x][mouseGrid.y].shown = true;
                spreader(ListFromMain,mouseGrid.y,mouseGrid.x,9,13);
                doOnce = false;
            }
        }
		window.clear();
        bool win = true;
        for (int x = 0; x < 13; x++){ // x Multiplier
            for (int y = 0; y < 9; y++){
                if ((ListFromMain[x][y].getmMine()==true && ListFromMain[x][y].getFlag()==false)||(ListFromMain[x][y].shown == false)){win = false;}
            }
        }
        if (win){
            cout << "YOU WON" << endl;
            window.close();
            return;
        }
        for (int x = 0; x < 13; x++){ // x Multiplier
            for (int y = 0; y < 9; y++){ // y Multiplier
                if (ListFromMain[x][y].shown == false && ListFromMain[x][y].getFlag() == false){
                    tileHidden.setPosition(gridSizeX * x,gridSizeY * y); // Update position
                    window.draw(tileHidden);
                }
                else if(ListFromMain[x][y].shown == true && ListFromMain[x][y].getmMine()){
                    std::string s = "!!!";
                    MinesAround.setString(s);
                    MinesAround.setPosition((gridSizeX * x)+5,(gridSizeY * y)); 
                    tileShown.setPosition(gridSizeX * x,gridSizeY* y);
                    tileShown.setFillColor(sf::Color(255,0,0)); // Update color
                    window.draw(tileShown);
                    window.draw(MinesAround);
                }
                else if (ListFromMain[x][y].shown == false && ListFromMain[x][y].getFlag() == true){
                    tileHidden.setPosition(gridSizeX * x,gridSizeY * y);
                    window.draw(tileHidden);
                    std::string s = "P"; // "FLAG"
                    flag.setString(s);
                    flag.setPosition((gridSizeX * x)+5,(gridSizeY * y)); // Update Position
                    window.draw(flag);
                }
                else{
                    std::string s =std::to_string(ListFromMain[x][y].numMinesSurrounded);
                    MinesAround.setString(s);
                    MinesAround.setPosition((gridSizeX * x)+10,(gridSizeY * y));
                    tileShown.setPosition(gridSizeX * x,gridSizeY* y);
                    window.draw(tileShown);
                    window.draw(MinesAround);
                // tileShown.setPosition(gridSizeX * y,gridSizeY * x);
                // window.draw(tileShown);
                }
            }
        }
        window.draw(text);

		window.display();
	}

	return;
}