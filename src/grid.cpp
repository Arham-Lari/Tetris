#include "grid.h"
#include <raylib.h>

Grid::Grid()
{
    numCol = 10;
    numRow  = 20;
    cellSize = 30;
    init();
}

void Grid::clearAllRow()
{
    for(int row = 0 ; row < numRow ; row ++)
    {
        clearRow(row);
    }
}
void Grid::init()
{
    for ( int row = 0; row < numRow; row ++ )
    {
        for(int col = 0 ; col < numCol; col ++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::draw()
{
     for ( int row = 0; row < numRow; row ++ )
    {
        for(int col = 0 ; col < numCol; col ++)
        {
            DrawRectangle(col * cellSize +1, row * cellSize +1, cellSize -1, cellSize -1 , DARKGRAY);
            
            if(grid[row][col] != 0){
                DrawRectangle(col * cellSize +1, row * cellSize +1, cellSize -1, cellSize -1, RED);
            }
        }
    }
   
}

bool Grid::isInside(int x , int y)
{
  if(x >=0 && x < numCol && y >= 0 && y < numRow){
        return true;
    }
    return false;
}

bool Grid::canFit(int row, int col)
{
    if(grid[row][col] == 0)
    {
        return true;
    }
    return false;
}
    
bool Grid::isRowFull(int row)
{
    for(int col =0 ; col < numCol ; col ++)
    {
        if(grid[row][col] == 0){
            return false;
        }
    }
    return true;
}

int Grid :: noOfRowsFull()
{
    int completeted = 0;
    for(int row = numRow-1; row >=0 ; row--)
    {
        if(isRowFull(row))
        {
            clearRow(row);
            completeted ++;
        }
        else if(completeted >0)
        {
            moveRowDown(row, completeted);
        }

    }
    return completeted;
}
   
void Grid::moveRowDown(int row, int numRow)
{
    for(int col = 0; col < numCol; col ++)
    {
        grid[row+numRow][col] = grid[row][col];
    }
}

void Grid::clearRow(int row)
{
   for(int col =0 ; col < numCol ; col ++)
    {
        grid[row][col] = 0;
    }
}
