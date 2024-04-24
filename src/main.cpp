
//Main Libraries
#include "M5Cardputer.h"
#include <string>

//Code Abbreviations
using namespace std;
#define lcd M5.Lcd

//Project Libraries
#include "redOceanIcon.h" //Project logo librarie


void setup() {
    //Screen settings
    M5.begin();
    M5.Power.begin();
    lcd.setRotation(1);
    lcd.setTextSize(3);
    lcd.setTextColor(WHITE);
    lcd.fillScreen(BLACK);

    //Project logo settings
    lcd.setSwapBytes(true);
    lcd.setBrightness(255);
    lcd.pushImage(iconX, iconY, iconWidth, iconHeight, redOceanIcon);
    delay(2*1000);
}

void loop() {
    /*string msg = "Te amo";
    
    lcd.setCursor(0, 0);

    lcd.fillScreen(BLACK);
    lcd.printf("%s", msg.c_str());

    delay(2*1000);
    lcd.setCursor(0, 0);
    msg = "Muitooo";
    lcd.fillScreen(RED);
    lcd.printf("%s\n", msg.c_str());

    delay(2*1000);*/
}