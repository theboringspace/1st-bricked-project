#include  "Ball.h"
#include "Constants.h"
#include <raylib.h>


/**
 * CLASS Ball DEFINITION
 */
Ball::Ball(Vector2 c, float r, Vector2 v, Color col)
:   center(c), radius(r), velocity(v), color(col),
    weapon(Vector2{center}, radius / 2.0f, radius * 1.5f)
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

Vector2 Ball::GetVelocity()const
{
    return velocity;
}

void Ball::Update(float deltaTime)
{
    weapon.SetCenterOfRotation(center);
    weapon.Update(deltaTime);

    hasHitWall =    (velocity.y > 0 && center.y + radius > WINDOW_HEIGHT)   ||
                    (velocity.y < 0 && center.y - radius < 0)               ||
                    (velocity.x > 0 && center.x + radius > WINDOW_LENGTH)   ||
                    (velocity.x < 0 && center.x - radius < 0);

    if (hasHitWall)
    {
        Ball tempBall{*this};
        velocity = Vector2{0, 0};

        // Bottom bound
        if (tempBall.velocity.y > 0 && tempBall.center.y + radius >= WINDOW_HEIGHT)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x, tempBall.velocity.y * -1};
        }
        // Top bound
        else if (tempBall.velocity.y < 0 && tempBall.center.y - radius <= 0)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x, tempBall.velocity.y * -1};
        }
        // Right bound
        else if (tempBall.velocity.x > 0 && tempBall.center.x + radius >= WINDOW_LENGTH)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x * -1, tempBall.velocity.y};
        }
        // Left bound
        else if (tempBall.velocity.x < 0 && tempBall.center.x - radius <= 0)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x * -1, tempBall.velocity.y};
        }

        velocity = tempBall.velocity;

        hasHitWall = false;

        return;
    }

    AddToPosition(Vector2{ velocity.x * deltaTime, velocity.y * deltaTime});
}

void Ball::Draw()
{
    DrawCircle(center.x, center.y, radius, color);
    weapon.Draw();
}
/**
 * END CLASS Ball DEFINITION
 */
