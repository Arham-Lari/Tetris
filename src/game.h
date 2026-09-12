#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game
{
public:
    Game();
    void draw();
    void handleInput();
    void moveDown();

private:
    void restart();
    bool gameOver;
    Grid grid;
    std::vector<Block> blocks ;
    void rotateTheBlock();
    Block currentBlock;
    bool isEmptyspace();
    bool isBlockinside();
    void newSpawn();
    Block nextBlock;
    std::vector<Block> allBlock();
    Block randomBlock();
    void moveLeft();
    void moveRight();
};
