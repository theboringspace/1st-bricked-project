#pragma once
#include <raylib.h>

/**
 * CLASS Ball DECLARATION
 */
class Ball
{
private:
    Vector2 center; // (x,y)
    float   radius;
    bool inflating{true};

    Color color;

    Vector2 velocity{0, 0};
public:
    Ball(Vector2 c, float r, Vector2 v, Color col);

    Vector2 GetCenter()const;
    float   GetRadius()const;
    Vector2 GetVelocity()const;

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
