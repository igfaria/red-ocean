
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

//Cursor definitions
#define cursorX 0
#define cursorY 20

void setup() {
    //Screen settings
    M5.begin();
    M5.Power.begin();
    lcd.setRotation(screenRotation);
    lcd.setTextSize(fontMedium);
    lcd.setTextColor(fontColor);
    lcd.fillScreen(screenColor);

    redOceanIcon(); //Project logo function

    drawMenu(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]));
}


void loop() {

}
