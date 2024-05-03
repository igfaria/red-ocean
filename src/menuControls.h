#ifndef MENUCONTROLS_H
#define MENU_H

//Rect definitions
#define rectY 13

int arrowDown(string *options, int size, int rectSum)
{
    if (rectSum < rectY + 80)
    {
        rectSum += 40;
        M5Cardputer.Display.clear();
        drawMenu(options, size, rectSum);
    } else
    {
        rectSum = rectY;
        drawMenu(options, size, rectY);
    }

    return rectSum;
}

int arrowUp(string *options, int size, int rectSum)
{
    if (rectSum > rectY)
    {
        rectSum -= 40;
        M5Cardputer.Display.clear();
        drawMenu(mainOptions, size, rectSum);
    } 
    else
    {
        rectSum = rectY + 80;
        drawMenu(mainOptions, size, rectSum);
    }
    return rectSum;
}

#endif /*MENUCONTROLS_H*/