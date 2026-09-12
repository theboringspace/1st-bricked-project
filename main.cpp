#include <raylib.h>

int main()
{
    int window_width = 1280;
    int window_height = 720;
    float x_pos = window_width / 2.0;
    float y_pos = window_height / 2.0;
    float radius = 30.0;
    bool velXIsPos = true;
    bool velYIsPos = true;
    Vector2 velocity{ 5, 5 };
    Vector2 position{ x_pos, y_pos };

    InitWindow(window_width, window_height, "Raylib Template");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        position.x += velocity.x;
        if (position.x + radius >= window_width || position.x - radius <= 0) {
            velocity.x *= -1;


            velXIsPos = velocity.x > 0;



            if (velXIsPos) {
                velocity.x += 5;
                velXIsPos = false;
            }
            else {
                velocity.x -= 5;
                velXIsPos = true;
            }
        }

        position.y += velocity.y;
        if (position.y + radius >= window_height || position.y - radius <= 0) {
            velocity.y *= -1;

            velYIsPos = velocity.y > 0;

            if (velYIsPos) {
                velocity.y += 5;
                velXIsPos = false;
            }
            else {
                velocity.y -= 5;
                velYIsPos = true;
            }
        }



        BeginDrawing();



        ClearBackground(BLACK);
        DrawCircle(position.x, position.y, radius, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
