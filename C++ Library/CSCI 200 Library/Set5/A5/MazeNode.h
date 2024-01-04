#ifndef NODE_H
#define NODE_H

/**
 * @brief A single element of the Maze
 * 
 */
struct MazeNode {
    /**
     * @brief the Character value of this Node
     * 
     */
    char value;
    /**
     * @brief A Previously Passed Node
     * 
     */
    bool passed;

    int xVal;
    int yVal;
};

#endif