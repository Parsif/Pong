#pragma once

namespace Pong
{
    class Ball
    {
    private:
        const float RADIUS_ = 10.0f;

    
    public:
        Ball();
        void OnWindowResize();
        void Draw();

    };
} // namespace Pong
