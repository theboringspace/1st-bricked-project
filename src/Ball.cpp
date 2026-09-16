#include  "Ball.h"
#include <raylib.h>

/**
 * CLASS Ball DEFINITION
 */
Ball::Ball(Vector2 c, float r, Vector2 v, Color col)
:   center(c), radius(r), velocity(v), color(col)
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

void Ball::Update(const Vector2& accel, float dt)
{
    if (radius >= 150)
    {
        inflating = false;
    }
    if (radius <= 50)
    {
        inflating = true;
    }

    // Bottom bound
    if (velocity.y > 0 && center.y + radius > 720)
    {
        velocity = Vector2{velocity.x, velocity.y * -1};
        if (inflating)
        {
            radius += radius * 0.10;
        }
        else
        {
            radius -= radius * 0.10;
        }
        return;
    }
    // Top bound
    if (velocity.y < 0 && center.y - radius < 0)
    {
        velocity = Vector2{velocity.x, velocity.y * -1};
        if (inflating)
        {
            radius += radius * 0.10;
        }
        else
        {
            radius -= radius * 0.10;
        }
        return;
    }
    // Right bound
    if (velocity.x > 0 && center.x + radius > 1280)
    {
        velocity = Vector2{velocity.x * -1, velocity.y};
        if (inflating)
        {
            radius += radius * 0.10;
        }
        else
        {
            radius -= radius * 0.10;
        }
        return;
    }
    // Left bound
    if (velocity.x < 0 && center.x - radius < 0)
    {
        velocity = Vector2{velocity.x * -1, velocity.y};
        if (inflating)
        {
            radius += radius * 0.10;
        }
        else
        {
            radius -= radius * 0.10;
        }
        return;
    }

    AddToVelocity(Vector2{ accel.x * dt, accel.y * dt} );
    AddToPosition(Vector2{ velocity.x, velocity.y});
}

void Ball::Draw()const
{
    DrawCircle(center.x, center.y, radius, color);
}
/**
 * END CLASS Ball DEFINITION
 */
