#ifndef MENUCONTROLS_H
#define MENU_H

//Rect definitions
#define rectY 13

//Cursor definitions
#define cursorY 20

int scrollOptionsDown(int scrollScreen, int size, int rectSum)
{
    if(size > 3 && rectSum == rectY+80){  
        if(scrollScreen <= size-3)
        {
            scrollScreen++;
        }
    }
    return scrollScreen;
}

int scrollOptionsUp(int scrollScreen, int size, int rectSum)
{
    if(size > 3 && rectSum == rectY){  
        if(scrollScreen <= size-3)
        {
            scrollScreen++;
        }
    }
    return scrollScreen;
}

int scrollInicial(int size, int scrollScreen, int rectSum)
{
    if(size > 3 && rectSum == rectY+80)
        if(scrollScreen == size-3+1)
            scrollScreen = 0;
    return scrollScreen;
}

int scrollFinal(int size, int scrollScreen, int rectSum)
{
    if(size > 3 && rectSum == rectY)
        if(scrollScreen == size-3+1)
            scrollScreen = 0;
    return scrollScreen;
}


int arrowDown(string *options, int size, int rectSum, int scrollScreen)
{
    if(size <= 3)
    {
        if (size <= 2)
        {
            if(size == 1)
            {
                drawMenu(options, size, rectY, cursorY);
            }
            if(size == 2)
            {
                if(rectSum == rectY)
                {
                    rectSum += 40;
                    drawMenu(options, size, rectSum, cursorY);
                } else
                {
                    rectSum = rectY;
                    drawMenu(options, size, rectY, cursorY);
                }
            }
            if(size == 3)
            {
                if (rectSum < rectY + 80)
                {
                    rectSum += 40;
                    drawMenu(options, size, rectSum, cursorY);
                } else
                {
                    rectSum = rectY;
                    drawMenu(options, size, rectY, cursorY);
                }
            } 
        }
    }
    if (size > 3)
    {
        if (rectSum < rectY + 80)
        {
            rectSum += 40;
            drawMenu(options, size, rectSum, cursorY);
        } else if (scrollScreen <= size-3)
        {
            scrollScreen = 20 + (scrollScreen - 1)*40;
            drawMenu(options, size, rectSum, -scrollScreen);
        }else{
            rectSum = rectY;
            drawMenu(options, size, rectY, cursorY);
        }
    }
    return rectSum;
}



int arrowUp(string *options, int size, int rectSum, int scrollScreen)
{
    if(size <= 3)
    {
        if (size <= 2)
        {
            if(size == 1)
            {
                drawMenu(options, size, rectY, cursorY);
            }
            if(size == 2)
            {
                if(rectSum == rectY)
                {
                    rectSum += 40;
                    drawMenu(options, size, rectSum, cursorY);
                } else
                {
                    rectSum = rectY;
                    drawMenu(options, size, rectY, cursorY);
                }
            }
            if(size == 3)
            {
                if (rectSum > rectY)
                {
                    rectSum -= 40;
                    drawMenu(mainOptions, size, rectSum, cursorY);
                } else
                {
                    rectSum = rectY + 80;
                    drawMenu(mainOptions, size, rectSum, cursorY);
                }
            } 
        }
    }
    if (size > 3)
    {
        if (rectSum > rectY)
        {
            rectSum -= 40;
            drawMenu(mainOptions, size, rectSum, cursorY);
        } else if (scrollScreen <= size-3)
        {
            scrollScreen = 20 + (scrollScreen - 1)*40;
            drawMenu(options, size, rectY, -scrollScreen);
        } else 
        {
            scrollScreen = 20 + ((size-3) - 1)*40;
            rectSum = rectY + 80;
            drawMenu(mainOptions, size, rectSum, -scrollScreen);
        }
    }
    return rectSum;
}

#endif /*MENUCONTROLS_H*/

