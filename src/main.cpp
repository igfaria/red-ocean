

//Main Libraries
#include "M5Cardputer.h"
//#include <string>

//Code Abbreviations
using namespace std;
#define lcd M5.Lcd


//Project Libraries
#include "redOceanIcon.h" //Project logo librarie
#include "menuOptions.h"
#include "menu.h"
#include "menuControls.h"
//#include "keyboardConfig.h"


//Screen definitions
#define screenColor 0x0000
#define screenRotation 1
#define screenWidth 240
#define screenHeight 135
int scrollScreenDown = 0;
int scrollScreenUp = 0;

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
int optionPosition = 1;

//Cursor definitions
#define cursorX 0
#define cursorY 20

//Options size
#define mainMenuSize sizeof(mainOptions)/sizeof(mainOptions[0])
#define keyboardSize sizeof(keyboardOptions)/sizeof(keyboardOptions[0])
int size = mainMenuSize;
String *options = mainOptions;

int applicationOption = 0;
int applicationLink = 0;

void screenSettings(){
    lcd.clear();
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
    M5.Power.begin();
    lcd.setBrightness(50);
    lcd.setRotation(screenRotation);
    lcd.setTextSize(fontMedium);
    lcd.setTextColor(fontColor);
    lcd.fillScreen(screenColor);
    lcd.setTextDatum(top_left);
}

void setup() {
    //Screen settings
    screenSettings();

    redOceanIcon(); //Project logo function

    //drawMenu(mainOptions, sizeof(mainOptions)/sizeof(mainOptions[0]), rectY, optionPosition);
    rectPosition(rectSum, size, options, optionPosition);
}

void loop() {

    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()){
        if (M5Cardputer.Keyboard.isKeyPressed('.')){  
            optionPosition = arrowDown(rectSum, size, optionPosition);
            rectSum = rectPosition(rectSum, size, options, optionPosition);
        }

        if (M5Cardputer.Keyboard.isKeyPressed(';')){
            optionPosition = arrowUp(rectSum, size, optionPosition);
            rectSum = rectPosition(rectSum, size, options, optionPosition);
        }
            
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER) && applicationOption == 0){
            // Enter action
            if(optionPosition==3){
                options = keyboardOptions;
                size = keyboardSize;
                applicationLink = optionPosition;
                optionPosition = 1;
                rectSum = rectY;
                applicationOption = 1;
                rectSum = rectPosition(rectSum, size, options, optionPosition);
            }
        }else
        if(M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER) && applicationOption == 1){
            //Option Configuration
            //if(applicationLink == 3 && optionPosition == 1) runUSBKeyboard();
            //if(applicationLink == 3 && optionPosition == 2) runBleKeyboard();
        }

        if(M5Cardputer.Keyboard.isKeyPressed(KEY_OPT)){
            options = mainOptions;
            size = mainMenuSize;
            optionPosition = 1;
            rectSum = rectY;
            applicationOption = 0;
            applicationLink = 0;
            screenSettings();
            rectPosition(rectSum, size, options, optionPosition);
        }
    }
}
