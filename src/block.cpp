#include "block.h"
#include <iostream>
#include <raylib.h>
#include <utility>
#include <vector>

Block::Block()
{
    cellsize = 30;
    rotationState = 0;
    offsetx = 0;
    offsety = 0;
}

void Block::draw()
{
    std::vector<std::pair<int, int>> EachCell = newPosition();
    for(const auto & cell : EachCell )
    {
        DrawRectangle(cell.second * cellsize +1, cell.first * cellsize +1, cellsize -1, cellsize -1, RED);
    }
}

void Block::move(int x ,int y)
{
    offsetx  += x;  
    offsety += y;
}

std::vector<std::pair<int, int>> Block::newPosition()
{
    std::vector<std::pair<int, int>> currrentPosition = cells[rotationState];
    std::vector<std::pair<int, int>> newpos;

    for(auto& cur : currrentPosition)
    {
        cur.second += offsetx;
        cur.first += offsety;
        newpos.push_back(cur);
    }

    return newpos;
}

void Block::rotateBlock()
{
    rotationState ++;
    if(rotationState >= cells.size())
    {
        std::cout<<rotationState<<std::endl;
        undoRotation();
    }
}

void Block::undoRotation()
{
    rotationState --;

    if(rotationState < 0)
    {
        rotationState = cells.size() -1;
    }
}
