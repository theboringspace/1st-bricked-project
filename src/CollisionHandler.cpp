#include "CollisionHandler.h"

void CollisionHandler::AddBall(Ball ball)
{
    balls.push_back(ball);
}


void CollisionHandler::Update(const Vector2 accel, float dt)
{
    for (size_t i{}; i < balls.size(); ++i)
    {
        balls.at(i).Update(accel, dt);
    }

    for (size_t i{}; i < balls.size(); ++i)
    {
        for (size_t j{i + 1}; j < balls.size(); ++j)
        {
            if (Colliding(balls.at(i), balls.at(j)))
            {
                ApplyCollision(balls.at(i), balls.at(j));
            }
        }
    }

}

bool CollisionHandler::Colliding(const Ball& ball1, const Ball& ball2)const
{
    return ( ball1.GetRadius() + ball2.GetRadius() >= GetDistance(ball1, ball2) );
}

void CollisionHandler::ApplyCollision(Ball& ball1, Ball& ball2)const
{
    Vector2 delta{ ball2.GetCenter().x - ball1.GetCenter().x, ball2.GetCenter().y - ball1.GetCenter().y };
    Vector2 relVel{ ball2.GetVelocity().x - ball1.GetVelocity().x, ball2.GetVelocity().y - ball1.GetVelocity().y };

    // only resolve if they're moving toward each other
    if (delta.x * relVel.x + delta.y * relVel.y >= 0) return;

    Vector2 temp{ball1.GetVelocity()};
    ball1.SetVelocity(ball2.GetVelocity());
    ball2.SetVelocity(temp);
}


float CollisionHandler::GetDistance(const Ball& ball1, const Ball& ball2)const
{
    return std::sqrt( std::pow((ball2.GetCenter().x - ball1.GetCenter().x), 2) + std::pow((ball2.GetCenter().y - ball1.GetCenter().y), 2) );
}

void CollisionHandler::Draw()
{
    for (size_t i{}; i < balls.size(); ++i)
    {
        balls.at(i).Draw();
    }
}
