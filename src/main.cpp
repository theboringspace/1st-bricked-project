#include <raylib.h>
#include "Ball.h"
#include "CollisionHandler.h"



int main()
{
    InitWindow(1280, 720, "Bala Bala Bala Bele Bele Bele");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    float dt{GetFrameTime()};

    CollisionHandler collisioner;
    collisioner.AddBall( {Vector2{WINDOW_LENGTH - 1100, WINDOW_HEIGHT - 100}, 40.0, Vector2{10,10}, WHITE} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 20.0, Vector2{-6, 4}, RED} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 50.0, Vector2{10, 2}, BLUE} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 10.0, Vector2{-3, 10}, GRAY} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 80.0, Vector2{-1, 2}, GREEN} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 10.0, Vector2{-6, 3}, YELLOW} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 40.0, Vector2{5, -7}, GOLD} );
    collisioner.AddBall( {Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 40.0, Vector2{-2, 1}, PURPLE} );




    // Ball ball(Vector2{WINDOW_LENGTH - 1100, WINDOW_HEIGHT - 100}, 40.0, WHITE);
    // Ball ball2(Vector2{WINDOW_LENGTH / 2.0, WINDOW_HEIGHT / 2.0}, 40.0, RED);
    // ball.SetVelocity(Vector2{5, 5});
    // ball2.SetVelocity(Vector2{-6, 3});

    const Vector2 GRAVITY{0, 20};


    while(!WindowShouldClose())
    {
        /**
         * LOGIC PROCESSING
         */
        dt = GetFrameTime();

        collisioner.Update(GRAVITY, dt);


        /**
         * DRAWING
         */
        BeginDrawing();

        ClearBackground(BLACK);

        collisioner.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
