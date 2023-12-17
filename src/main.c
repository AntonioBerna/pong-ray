#include "utility.h"
#include "button.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Game");

    Button playButton;
    Button helpButton;
    init_button(&playButton, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 30, 200, 60, "Play", GRAY);
    init_button(&helpButton, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 50, 200, 60, "Help", GRAY);

    Ball ball;
    Paddle leftPaddle;
    Paddle rightPaddle;
    Score score;    
    init_all(&ball, &leftPaddle, &rightPaddle, &score);
    
    bool isPaused = false;
    bool isMenuActive = true;
    bool isHelpActive = false;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        if (isMenuActive) {
            DrawMenu(playButton, helpButton);
            
            if (CheckButtonPressed(playButton)) {
                isMenuActive = false;
            } else if (CheckButtonPressed(helpButton)) {
                isHelpActive = true;
                isMenuActive = false;
            }
        } else if (isHelpActive) {
            DrawHelpText();

            if (IsKeyPressed(KEY_BACKSPACE)) {
                isMenuActive = true;
                isHelpActive = false;
            }
        } else {
            if (IsKeyPressed(KEY_BACKSPACE)) {
                isMenuActive = true;
                init_all(&ball, &leftPaddle, &rightPaddle, &score);
                isPaused = false;
            }

            if (IsKeyPressed(KEY_SPACE)) isPaused = !isPaused;
            
            if (IsKeyPressed(KEY_R)) {
                init_all(&ball, &leftPaddle, &rightPaddle, &score);
                isPaused = false;
            }

            if (!isPaused) {
                if (IsKeyDown(KEY_W) && leftPaddle.position.y > 0) leftPaddle.position.y -= PADDLE_SPEED * GetFrameTime();
                if (IsKeyDown(KEY_S) && leftPaddle.position.y + leftPaddle.height < SCREEN_HEIGHT) leftPaddle.position.y += PADDLE_SPEED * GetFrameTime();

                if (IsKeyDown(KEY_UP) && rightPaddle.position.y > 0) rightPaddle.position.y -= PADDLE_SPEED * GetFrameTime();
                if (IsKeyDown(KEY_DOWN) && rightPaddle.position.y + rightPaddle.height < SCREEN_HEIGHT) rightPaddle.position.y += PADDLE_SPEED * GetFrameTime();

                ball.position.x += ball.speed.x * GetFrameTime();
                ball.position.y += ball.speed.y * GetFrameTime();

                // Collisions with walls
                if (ball.position.y - ball.radius < 0 || ball.position.y + ball.radius > SCREEN_HEIGHT) {
                    ball.speed.y = -ball.speed.y;
                }

                // Increasing the score and repositioning the ball when it goes off the screen
                if (ball.position.x - ball.radius < 0) {
                    score.right++;
                    ball.position = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
                } else if (ball.position.x + ball.radius > SCREEN_WIDTH) {
                    score.left++;
                    ball.position = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
                }

                // Paddle collision
                if ((CheckCollisionCircleRec(ball.position, ball.radius, (Rectangle){leftPaddle.position.x, leftPaddle.position.y, leftPaddle.width, leftPaddle.height}) && ball.speed.x < 0) ||
                    (CheckCollisionCircleRec(ball.position, ball.radius, (Rectangle){rightPaddle.position.x, rightPaddle.position.y, rightPaddle.width, rightPaddle.height}) && ball.speed.x > 0)) {
                    ball.speed.x = -ball.speed.x;
                }

                leftPaddle.position.y += leftPaddle.speed.y * GetFrameTime();
                rightPaddle.position.y += rightPaddle.speed.y * GetFrameTime();
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(ball.position, ball.radius, BLACK);
            DrawRectangleRec((Rectangle){leftPaddle.position.x, leftPaddle.position.y, leftPaddle.width, leftPaddle.height}, BLACK);
            DrawRectangleRec((Rectangle){rightPaddle.position.x, rightPaddle.position.y, rightPaddle.width, rightPaddle.height}, BLACK);

            DrawText(TextFormat("%d - %d", score.left, score.right), SCREEN_WIDTH / 2 - MeasureText("0 - 0", 20) / 2, 10, 20, BLACK);
            
            if (isPaused) DrawText("PAUSED", SCREEN_WIDTH / 2 - MeasureText("PAUSED", 30) / 2, SCREEN_HEIGHT / 2 - 10, 30, RED);
            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}

