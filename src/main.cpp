#include <raylib.h>
#include "Ball.h"
#include "Constants.h"
#include "World.h"



int main()
{
    InitWindow(WINDOW_LENGTH, WINDOW_HEIGHT, "Bala Bala Bala Bele Bele Bele");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    float deltaTime{0};

    World world;
    world.AddBall( {Vector2{WINDOW_LENGTH / 2.0 - 100, WINDOW_HEIGHT / 2.0 + 100}, 40, Vector2{750, -750}, WHITE} );
    world.AddBall( {Vector2{WINDOW_LENGTH / 2.0 + 100, WINDOW_HEIGHT / 2.0 + 100}, 40, Vector2{-750, 750}, BLACK} );

    while(!WindowShouldClose())
    {
        /**
         * LOGIC PROCESSING
         */
        deltaTime = GetFrameTime();

        world.UpdateWorld(deltaTime);


        /**
         * DRAWING
         */
        BeginDrawing();

        ClearBackground(GRAY);

        world.DrawWorld();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
