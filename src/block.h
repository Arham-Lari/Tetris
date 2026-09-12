#include "vector"
#include "map"
#include <utility>
#include <vector>

class Block{
public:
    Block();
    int id;
    void rotateBlock();
    void undoRotation();
    void draw();
    void move(int x , int y);
    std::vector<std::pair<int, int>> newPosition();
    std::map<int, std::vector<std::pair<int, int>>> cells;

private:
    int cellsize;
    int rotationState;
    int offsetx ;
    int offsety;
};
