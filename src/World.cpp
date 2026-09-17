#include "World.h"

World::World() { balls.reserve(MAX_BALLS); }

void World::AddBall(Ball ball)
{
    balls.push_back(ball);
}

void World::UpdateWorld(float deltaTime)
{
    // Update for regular ball movement.
    for (size_t i{}; i < balls.size(); ++i)
    {
        balls.at(i).Update(deltaTime);
    }

    // Update for collisions
    collisionHandler.Update(balls, deltaTime);

}

void World::DrawWorld()
{
    for (Ball& ball : balls)
    {
        ball.Draw();
    }
}
