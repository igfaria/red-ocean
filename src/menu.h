#ifndef MENU_H
#define MENU_H

//Rect definitions
#define rectColor 0xF000
#define rectX 0
//#define rectY 13 //Somar de 40 em 40
#define rectHeight 30

//Cursor definitions
#define cursorX 0
#define cursorY 20

//Screen definitions
#define screenColor 0x0000
#define screenWidth 240

void drawMenu(String *options, int size, int rectY, int optionPosition){
    lcd.clear();
    lcd.setCursor(cursorX, cursorY);
    lcd.fillScreen(screenColor);
    lcd.fillRect(rectX, rectY, screenWidth, rectHeight, rectColor);
    for(int i = optionPosition-1; i < size; i++)
        lcd.printf("%s\n\n", options[i].c_str());
}

#endif /*MENU_H*/