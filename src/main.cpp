#include <Arduino.h>

#include "M5Cardputer.h"

void draw_function(LovyanGFX* gfx) {
    int x      = rand() % gfx->width();
    int y      = rand() % gfx->height();
    int r      = (gfx->width() >> 4) + 2;
    uint16_t c = rand();
    gfx->fillRect(x - r, y - r, r * 2, r * 2, c);
}

void setup() {
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);
    int textsize = M5Cardputer.Display.height() / 60;
    if (textsize == 0) {
        textsize = 1;
    }
    M5Cardputer.Display.setTextSize(textsize);
}

void loop() {
    int x      = rand() % M5Cardputer.Display.width();
    int y      = rand() % M5Cardputer.Display.height();
    int r      = (M5Cardputer.Display.width() >> 4) + 2;
    uint16_t c = rand();
    M5Cardputer.Display.fillCircle(x, y, r, c);
    draw_function(&M5Cardputer.Display);
}