#include "raylib.h"
#include "game.h"

const Vector2 winDimension {300,600};
const Color winColor {DARKBLUE};

float lastTime = 0;

bool timer(float interval)
{
    float currentTime = GetTime();
    if(currentTime - lastTime >= interval)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    InitWindow(winDimension.x, winDimension.y, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(winColor);
        game.draw();
        game.handleInput();

        if(timer(0.2)){
            game.moveDown();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
