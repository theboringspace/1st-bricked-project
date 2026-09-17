#include <raylib.h>
#include "BallWeapon.h"
#include <cmath>

BallWeapon::BallWeapon(Vector2 centerOfRot, float rad, float momArm)
:   centerOfRotation(centerOfRot), radius(rad), momentArm(momArm)
{
}

void BallWeapon::SetCenterOfRotation(Vector2 centRot)
{
    centerOfRotation = centRot;
}

void BallWeapon::Update(float deltaTime)
{
    radian += angularVelocity * deltaTime;
    if (radian >= 2 * PI)
    {
        radian -= 2 * PI;
    }

    center.x = centerOfRotation.x + std::sqrt(2) * momentArm * std::cos(radian);
    center.y = centerOfRotation.y + std::sqrt(2) * momentArm * std::sin(radian);
}

void BallWeapon::Draw()
{
    DrawCircle(center.x, center.y, radius, RED);
}
