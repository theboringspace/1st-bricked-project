#pragma once

#include <vector>
#include "Constants.h"
#include "Ball.h"

class CollisionHandler
{
private:
    std::vector<Ball> balls;

public:
    void AddBall(Ball ball);

    void Update(const Vector2 accel, float dt);

    bool Colliding(const Ball& ball1, const Ball& ball2)const;

    void ApplyCollision(Ball& ball1, Ball& ball2)const;

    float GetDistance(const Ball& ball1, const Ball& ball2)const;

    void Draw();
};
