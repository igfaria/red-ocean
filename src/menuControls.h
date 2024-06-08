#ifndef MENUCONTROLS_H
#define MENU_H

//Rect definitions
#define rectY 13

int arrowUp(int rectSum, int size, int  optionPosition)
{
    if(optionPosition == 1){
        optionPosition = size;
    }else if(optionPosition > 1){
         optionPosition--;
    }

    return optionPosition;
}

int arrowDown(int rectSum, int size, int  optionPosition)
{
    if(optionPosition == size){
        optionPosition = 1;
    }
    else if(optionPosition < size){
         optionPosition++;
    }

    return optionPosition;
}

int rectPosition(int rectSum, int size, String *options, int  optionPosition){
        if(optionPosition%3 == 2){
            rectSum = rectY+40;
            drawMenu(options, size, rectSum, optionPosition-1);
        }
        if(optionPosition%3 == 1){
            rectSum = rectY;
            drawMenu(options, size, rectSum, optionPosition);
        }
        if(optionPosition%3 == 0){
            rectSum = rectY+80;
            drawMenu(options, size, rectSum, optionPosition-2);
        }
    return rectSum;
}

#endif /*MENUCONTROLS_H*/