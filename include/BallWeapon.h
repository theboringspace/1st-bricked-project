#pragma once

#include <raylib.h>

class BallWeapon
{
private:
    // Variables in relation to the weaponholder
    Vector2 centerOfRotation;
    float   momentArm;

    // Variables of just the ball weapon (Which is also a ball)
    Vector2 center{};
    float   radius;

    float angularVelocity{2* PI};
    float radian{0};
public:
    BallWeapon(Vector2 centerOfRot, float rad, float momArm);

    void SetCenterOfRotation(Vector2 centRot);

    void Update(float deltaTime);
    void Draw();
};
