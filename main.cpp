#include <raylib.h>

/**
 * CLASS Ball DECLARATION
 */
class Ball
{
private:
    Vector2 center; // (x,y)
    float   radius;

    Vector2 velocity{0, 0};
public:
    Ball(Vector2 c, float r);

    Vector2 GetCenter()const;
    float   GetRadius()const;

    void AddToPosition(const Vector2& vel);
    void AddToVelocity(const Vector2& accel);

    void SetVelocity(Vector2 vel);

    // TO CHANGE
    void Update(const Vector2& accel, float dt);
    void Draw()const;
};
/**
 * END CLASS Ball DECLARATION
 */

int main()
{
    InitWindow(1280, 720, "Bala Bala Bala Bele Bele Bele");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    float dt{GetFrameTime()};

    Ball ball(Vector2{1280 - 1100, 720 - 100}, 20.0);
    ball.SetVelocity(Vector2{5, 5});

    const Vector2 GRAVITY{0, 9.8};


    while(!WindowShouldClose())
    {
        /**
         * LOGIC PROCESSING
         */
        dt = GetFrameTime();

        ball.Update(GRAVITY, dt);


        /**
         * DRAWING
         */
        BeginDrawing();

        ClearBackground(BLACK);

        ball.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

/**
 * CLASS Ball DEFINITION
 */
Ball::Ball(Vector2 c, float r)
:   center(c), radius(r)
{
}

Vector2 Ball::GetCenter()const { return center; }

float Ball::GetRadius()const { return radius; }

void Ball::AddToPosition(const Vector2& vel)
{
    center.x += vel.x;
    center.y += vel.y;
}

void Ball::AddToVelocity(const Vector2& accel)
{
    velocity.x += accel.x;
    velocity.y += accel.y;
}

void Ball::SetVelocity(Vector2 vel)
{
    velocity = vel;
}

void Ball::Update(const Vector2& accel, float dt)
{
    // Bottom bound
    if (velocity.y > 0 && center.y + radius > 720)
    {
        velocity = Vector2{velocity.x, velocity.y * -1};
        return;
    }
    // Top bound
    if (velocity.y < 0 && center.y - radius < 0)
    {
        velocity = Vector2{velocity.x, velocity.y * -1};
        return;
    }
    // Right bound
    if (velocity.x > 0 && center.x + radius > 1280)
    {
        velocity = Vector2{velocity.x * -1, velocity.y};
        return;
    }
    // Left bound
    if (velocity.x < 0 && center.x - radius < 0)
    {
        velocity = Vector2{velocity.x * -1, velocity.y};
        return;
    }

    AddToVelocity(Vector2{ accel.x * dt, accel.y * dt} );
    AddToPosition(Vector2{ velocity.x * 0.50f, velocity.y * 0.50f});
}

void Ball::Draw()const
{
    DrawCircle(center.x, center.y, radius, WHITE);
}
/**
 * END CLASS Ball DEFINITION
 */
