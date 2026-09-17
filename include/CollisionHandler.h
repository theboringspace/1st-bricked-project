#pragma once

#include <vector>
#include "Ball.h"

class CollisionHandler
{
public:
    void Update(std::vector<Ball>& balls, float deltaTime);

    bool Colliding(const Ball& ball1, const Ball& ball2)const;

    void ApplyCollision(Ball& ball1, Ball& ball2)const;

    float GetDistance(const Ball& ball1, const Ball& ball2)const;
};
