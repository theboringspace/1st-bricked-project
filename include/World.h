#pragma once

#include <raylib.h>

#include "CollisionHandler.h"
#include "Ball.h"

class World
{
private:
    static constexpr size_t MAX_BALLS{100};

    // Only two balls will be fighting.
    std::vector<Ball> balls;
    // Checks and applies collision.
    CollisionHandler collisionHandler;

public:
    World();

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;
    ~World() = default;

    void AddBall(Ball ball);

    void UpdateWorld(float deltaTime);
    void DrawWorld();
};
