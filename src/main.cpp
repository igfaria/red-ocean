
//Main Libraries
#include "M5Cardputer.h"
#include <string>

//Code Abbreviations
using namespace std;
#define lcd M5.Lcd
//#include <SPI.h>
//#include <Wire.h>
#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

//Project Libraries
#include "redOceanIcon.h" //Project logo librarie


void setup() {
    //Screen settings
    M5.begin();
    M5.Power.begin();
    lcd.setRotation(1);
    lcd.setTextSize(2.5);
    lcd.setTextColor(0xFFFFF);
    lcd.fillScreen(BLACK);

    //Project logo settings
    lcd.setSwapBytes(true);
    lcd.setBrightness(255);
    lcd.pushImage(iconX, iconY, iconWidth, iconHeight, redOceanIcon);
    delay(5*1000);

    string msg = {" [*] IR\n\n [*] Wifi\n\n [*] Keyboard"};
    //string msg = " [*] IR";
    
    int cursorX = 0;
    int cursorY = 20;
    int targetX = 0;
    int targetY = 15;
    int i = 0;

    lcd.setCursor(cursorX, cursorY);
    lcd.fillScreen(BLACK);
    lcd.fillRect(targetX, targetY, iconWidth, 30, RED);
    //lcd.setTextColor(0xFFFFF);
    lcd.printf("%s", msg.c_str());
    //lcd.printf("%-15s", msg.c_str());
    cursorY += 20;
    delay(2*1000);
}




void loop() {
    /*=
    string msg = "Te amo";
    
    lcd.setCursor(0, 0);

    lcd.fillScreen(BLACK);
    lcd.printf("%s", msg.c_str());

    delay(2*1000);
    lcd.setCursor(0, 0);
    msg = "Muitooo";
    lcd.fillScreen(RED);
    lcd.printf("%s\n", msg.c_str());

    delay(2*1000);
    */
}
