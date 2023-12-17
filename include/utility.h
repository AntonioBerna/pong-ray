#pragma once

#include <stdlib.h>
#include <assert.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BALL_SPEED 300.0f
#define RADIUS 10
#define PADDLE_SPEED 500.0f

typedef struct {
    Vector2 position;
    Vector2 speed;
    float radius;
} Ball;

void init_ball(Ball *ball, float posX, float posY, float speedX, float speedY, float radius);

typedef struct {
    Vector2 position;
    Vector2 speed;
    float width;
    float height;
} Paddle;

void init_paddle(Paddle *paddle, float posX, float posY, float speedX, float speedY, float width, float height);

typedef struct {
    int left;
    int right;
} Score;

void init_score(Score *score, int left, int right);

////////////

void init_all(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle, Score *score); 

////////////