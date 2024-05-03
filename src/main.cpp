

//Main Libraries
#include "M5Cardputer.h"
#include <string>

//Code Abbreviations
using namespace std;
#define lcd M5.Lcd


//Project Libraries
#include "redOceanIcon.h" //Project logo librarie
#include "menuOptions.h"
#include "menu.h"
#include "menuControls.h"

//Screen definitions
#define screenColor 0x0000
#define screenRotation 1
#define screenWidth 240
#define screenHeight 135

//Font definitions
#define fontColor 0xFFFF
#define fontSmall 1.5
#define fontMedium 2.5
#define fontHigh 3

//Rect definitions
#define rectColor 0xF000
#define rectX 0
#define rectY 13 //Somar de 40 em 40
#define rectHeight 30
int rectSum = rectY;

//Cursor definitions
#define cursorX 0
#define cursorY 20

void setup() {
    //Screen settings
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
    M5.Power.begin();
    lcd.setRotation(screenRotation);
    lcd.setTextSize(fontMedium);
    lcd.setTextColor(fontColor);
    lcd.fillScreen(screenColor);

    redOceanIcon(); //Project logo function

    drawMenu(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]), rectY);
}


void loop() {

    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange())
    {
        if (M5Cardputer.Keyboard.isKeyPressed('.'))           
            rectSum = arrowDown(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]), rectSum);

        if (M5Cardputer.Keyboard.isKeyPressed(';'))
            rectSum = arrowUp(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]), rectSum);
            
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER))
            drawMenu(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]), rectY);
    }


}