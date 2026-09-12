#include "game.h"
#include "grid.h"
#include <cstdlib>
#include <raylib.h>
#include <sys/types.h>
#include <utility>
#include <vector>

Game::Game()
{
    grid = Grid();
    gameOver = false;
    blocks = allBlock();
    currentBlock =  randomBlock();
    nextBlock = randomBlock();
}

std::vector<Block> Game::allBlock()
{
    return {LBlock(),JBlock(),ZBlock(),IBlock(),SBlock(),TBlock(),OBlock()};
}

Block Game::randomBlock()
{
    if(blocks.empty())
    {
        blocks = allBlock();
    }
    int randomNum = rand()%blocks.size();
    Block temp = blocks[randomNum];
    blocks.erase(blocks.begin() + randomNum);
    
    return temp;
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput()
{
        int input = GetKeyPressed();

    if(gameOver){
        if(input == KEY_ENTER){
            restart();
            return;
        }
    }

    else if(!gameOver){
        switch(input)
        {
            case KEY_LEFT :
                {
                    moveLeft();
                    break;
                }
            case KEY_RIGHT :
                {
                    moveRight();
                    break;
                }
            case KEY_DOWN :
                {
                    moveDown();
                    break;
                }
            case KEY_SPACE :
                {
                    rotateTheBlock();
                    break;
                }
        }
    }
}

void Game:: rotateTheBlock()
{
    if(!gameOver){
        currentBlock.rotateBlock();

        if(!isEmptyspace() || !isBlockinside()){
            currentBlock.undoRotation();
        }
    }
}

void Game::moveLeft()
{
    if(!gameOver){
        currentBlock.move(-1, 0);
        if(!isBlockinside() || !isEmptyspace()){
            currentBlock.move(1, 0);
        }
    }

}

void Game::moveRight()
{
    if(!gameOver){
        currentBlock.move(1, 0);
        if(!isBlockinside() || !isEmptyspace()){
            currentBlock.move(-1, 0);
        }
    }
}

void Game::moveDown()
{
    if(!gameOver){
        currentBlock.move(0, 1);
        if(!isBlockinside() || isEmptyspace()== false  ){
            currentBlock.move(0, -1);
            newSpawn();
        }
    }
}

bool Game::isBlockinside()
{
    std::vector<std::pair<int, int>> temp = currentBlock.newPosition();

    for(const auto& eachBlock : temp)
    {
        bool check = grid.isInside(eachBlock.second, eachBlock.first);
        if(!check)
        {
            return false;
        }
    }
    return true;
}


void Game::newSpawn ()
{
    std::vector<std::pair<int, int>> insertionOfBlock = currentBlock.newPosition();
    for(const auto& insert : insertionOfBlock)
    {
        grid.grid[insert.first][insert.second] = currentBlock.id;
    }

    currentBlock = nextBlock;
    nextBlock = randomBlock();
    if(!isEmptyspace()){
        gameOver = true;
    }
    int clearRow = grid.noOfRowsFull(); 
}

bool Game::isEmptyspace()
{
    std::vector<std::pair<int, int>> tem = currentBlock.newPosition();
    for(const auto& eachPos : tem)
    {
        if(!grid.canFit(eachPos.first, eachPos.second)){
            return false;
        }
    }
    return true;
}

void Game:: restart()
{
    blocks = allBlock();
    grid.clearAllRow();
    currentBlock = randomBlock();
    nextBlock = randomBlock();
    gameOver = false;
}
