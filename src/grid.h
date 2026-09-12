#pragma once 

class Grid
{
public:
    Grid();
    void clearAllRow();
    void clearRow(int row);
    bool isRowFull(int row);
    void moveRowDown(int row, int numRow);
    int noOfRowsFull();
    int grid[20][10];
    void draw();
    bool isInside(int x , int y);
    bool canFit(int row , int col);

private:
    void init();
    int numRow;
    int numCol;
    int cellSize;
};
