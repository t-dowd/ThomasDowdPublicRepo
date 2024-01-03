#ifndef SWEEP
#define SWEEP
/**
 * @brief A singular Tile in the Game of Minesweeper. 
 * 
 */
struct GameNode{ 
    /**
     * @brief A boolean deciding if the node is shown or not
     * 
     */
    bool shown;
    /**
     * @brief Number of mines that are surrounding the node;
     * 
     */
    int numMinesSurrounded;
    /**
     * @brief X-Value of the Node
     * 
     */
    int xVal;
    /**
     * @brief Y-Value of the node 
     * 
     */
    int yVal;
    /**
     * @brief Set the Flagged Attribute
     * 
     */
    void setFlagged(bool);
    /**
     * @brief Get the Flag Attribute
     * 
     * @return true 
     * @return false 
     */
    bool getFlag() const;
    /**
     * @brief Set the Mine Attribute to true
     * 
     */
    void setmMineTrue();
    /**
     * @brief Set the Mine Attribute to false
     * 
     */
    void setmMineFalse();
    /**
     * @brief Returns the state of the Mine Attribute
     * 
     * @return true 
     * @return false 
     */
    bool getmMine() const;
    private:
    /**
     * @brief mMine Attribute PRIVATE
     * 
     */
    bool mMine;
    /**
     * @brief Flag Attribute
     * 
     */
    bool flagged;
};
/**
 * @brief Overloaded Functions of RNG
 * 
 * @param rollx 
 * @param rolly 
 * @param sizeX 
 * @param sizeY 
 */
void randomNumberGenerator(int& rollx,int& rolly,int sizeX, int sizeY);
void randomNumberGenerator(int& roll);
void randomNumberGenerator(int& roll, bool);
/**
 * @brief Upon click, auto generates a randomized area around the click, Semi Buggy.
 * 
 * @param x 
 * @param y 
 * @param Width 
 * @param Height 
 */
void spreader(GameNode**, int x, int y,int Width, int Height);
/**
 * @brief Fullprints the Game Board in Terminal *DEV USE*
 * 
 * @param gameboard 
 */
void fullprint(GameNode** gameboard,int, int);
/**
 * @brief Fullprints the Board Key in Terminal *DEV USE*
 * 
 * @param ListFromMain 
 * @param Width 
 * @param Height 
 */
void fullprintKey(GameNode** ListFromMain,int Width, int Height);
/**
 * @brief One round of the game, used in Terminal as well as SFML
 * 
 * @param gameboard 
 * @param Width 
 * @param Height 
 * @param onetime 
 */
void gameframe(GameNode** gameboard,int Width, int Height,bool onetime);
/**
 * @brief Creates and allocates memory for values, Parametierized constructor of sorts
 * 
 * @param x 
 * @param y 
 * @param minesclose 
 * @return GameNode* 
 */
GameNode* makeNodeForValue(int x, int y, int minesclose);
/**
 * @brief Create a Board object, Also starts the randomization process's.
 * 
 * @param sizey 
 * @param sizeX 
 * @param bombNum 
 * @return GameNode** 
 */
GameNode** CreateBoard(int sizey,int sizeX, int bombNum);
/**
 * @brief MAIN SFML GAME LOOP
 * 
 * @param ListFromMain 
 */
void drawGameBoard(GameNode** ListFromMain,int,int);
/**
 * @brief the start splash screen.
 * 
 */
void firstBoot();

#endif