#pragma once

#include <stdlib.h>
#include <assert.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct {
    Rectangle rect;
    const char *text;
    Color color;
} Button;

void init_button(Button *button, float x, float y, float width, float height, const char *text, Color color);
void DrawButton(Button button);
void DrawMenu(Button playButton, Button helpButton);
bool CheckButtonPressed(Button button);
void DrawHelpText(void);
