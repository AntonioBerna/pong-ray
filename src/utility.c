#include "utility.h"

void init_ball(Ball *ball, float posX, float posY, float speedX, float speedY, float radius) {
    assert(ball != NULL);
    ball->position.x = posX;
    ball->position.y = posY;
    ball->speed.x = speedX;
    ball->speed.y = speedY;
    ball->radius = radius;
}

void init_paddle(Paddle *paddle, float posX, float posY, float speedX, float speedY, float width, float height) {
    assert(paddle != NULL);
    paddle->position.x = posX;
    paddle->position.y = posY;
    paddle->speed.x = speedX;
    paddle->speed.y = speedY;
    paddle->width = width;
    paddle->height = height;
}

void init_score(Score *score, int left, int right) {
    assert(score != NULL);
    score->left = left;
    score->right = right;
}

void init_all(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle, Score *score) {
    init_ball(ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_SPEED, BALL_SPEED, RADIUS);
    init_paddle(leftPaddle, 20, SCREEN_HEIGHT / 2 - 50, 0, 0, 20, 100);
    init_paddle(rightPaddle, SCREEN_WIDTH - 40, SCREEN_HEIGHT / 2 - 50, 0, 0, 20, 100);
    init_score(score, 0, 0);
}

