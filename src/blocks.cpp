#include "block.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        cells[0] = {{0,2},{1,0},{1,1},{1,2}};
        cells[1] = {{0,1},{1,1},{2,1},{2,2}};
        cells[2] = {{1,0},{1,1},{1,2},{2,0}};
        cells[3] = {{0,0},{0,1},{1,1},{2,1}};
        move(3, 0);
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id =2;
        cells[0] = {{0,0},{1,0},{1,1},{1,2}};
        cells[1] = {{0,1},{0,2},{1,1},{2,1}};
        cells[2] = {{1,0},{1,1},{1,2},{2,2}};
        cells[3] = {{0,1},{1,1},{2,0},{2,1}};
        move (3,0);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells[0] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
        cells[1] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
        cells[2] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
        move(3,0);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells[0] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        move(4,0);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells[0] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}};
        cells[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
        cells[2] = {{1, 1}, {1, 2}, {2, 0}, {2, 1}};
        cells[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
        move(3,0);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells[0] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};
        cells[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 1}};
        cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 1}};
        cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 1}};
        move(3,0);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
        cells[1] = {{0, 2}, {1, 1}, {1, 2}, {2, 1}};
        cells[2] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
        cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
        move(3,0);
    }
};
