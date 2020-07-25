#include "Collider.h"

#include <iostream>

namespace Pong
{
    Collider::Collider(SDL_Window *window) : window_(window) {}

    void Collider::Collide(std::unique_ptr<Player> &player1, std::unique_ptr<Player> &player2, std::unique_ptr<Ball> &ball)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        auto ball_rect = ball->GetRect();

        auto player1_rect = player1->GetRect();
        if (ball_rect.x > player1_rect.x && ball_rect.x < player1_rect.x + player1_rect.w &&
            ((ball_rect.y > player1_rect.y && ball_rect.y < player1_rect.y + player1_rect.h) ||                            // Either ball top edge should be touch player
             (ball_rect.y + ball_rect.h > player1_rect.y && ball_rect.y + ball_rect.h < player1_rect.y + player1_rect.h))) // or bottom one
        {
            BallPlayerColiission(player1, ball);
        }

        auto player2_rect = player2->GetRect();
        if (ball_rect.x + ball_rect.w > player2_rect.x && ball_rect.x + ball_rect.w < player2_rect.x + player2_rect.w &&
            ((ball_rect.y > player2_rect.y && ball_rect.y < player2_rect.y + player2_rect.h) ||                            // Either ball top edge should be touch player
             (ball_rect.y + ball_rect.h > player2_rect.y && ball_rect.y + ball_rect.h < player2_rect.y + player2_rect.h))) // or bootom one
        {
            BallPlayerColiission(player2, ball);
        }

        if (ball_rect.y <= 0 || ball_rect.y + ball_rect.h > window_height) // hits the wall top or bottom side
        {
            ball->velocity_y_ = -ball->velocity_y_;
        }
    }

    void Collider::BallPlayerColiission(std::unique_ptr<Player> &player, std::unique_ptr<Ball> &ball)
    {
        int player_y_center = player->GetRect().y + player->GetRect().h / 2;
        int ball_y_center = ball->GetRect().y + ball->GetRect().h / 2;
        const float angle_coefficient = 0.1f;
        ball->velocity_y_ += (player_y_center - ball_y_center) * angle_coefficient;
        ball->velocity_x_ = -ball->velocity_x_;
    }

    bool Collider::IsGoalScored(std::unique_ptr<Ball> &ball)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        auto ball_rect = ball->GetRect();

        if (ball_rect.x <= 0)
        {
            std::cout << "Player2 scored goal" << '\n';
            return true;
        }
        else if (ball_rect.x + ball_rect.w >= window_width)
        {
            std::cout << "Player1 scored goal" << '\n';
            return true;
        }
        return false;
    }
} // namespace Pong