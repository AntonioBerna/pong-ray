#include "button.h"

void init_button(Button *button, float x, float y, float width, float height, const char *text, Color color) {
    assert(button != NULL);
    button->rect.x = x;
    button->rect.y = y;
    button->rect.width = width;
    button->rect.height = height;
    button->text = text;
    button->color = color;
}

void DrawButton(Button button) {
    DrawRectangleRec(button.rect, button.color);
    DrawText(button.text, button.rect.x + 10, button.rect.y + 10, 20, BLACK);
}

void DrawMenu(Button playButton, Button helpButton) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Pong Game", SCREEN_WIDTH / 2 - MeasureText("Pong Game", 40) / 2, 50, 40, BLACK);
    
    DrawButton(playButton);
    DrawButton(helpButton);
    
    EndDrawing();
}

bool CheckButtonPressed(Button button) {
    Vector2 mousePoint = GetMousePosition();
    return (CheckCollisionPointRec(mousePoint, button.rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void DrawHelpText(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Help", SCREEN_WIDTH / 2 - MeasureText("Help", 40) / 2, 50, 40, BLACK);
    DrawText("Paddle sinistro: W (su), S (giù)\n\n"
             "Paddle destro: Freccia su, Freccia giù\n\n"
             "Metti in pausa: SPAZIO\n\n"
             "Ripristina il gioco: R\n\n"
             "Torna al menu: BACKSPACE",
             SCREEN_WIDTH / 4 - 20, SCREEN_HEIGHT / 4, 20, BLACK);

    EndDrawing();
}
