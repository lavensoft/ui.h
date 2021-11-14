/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "radioBox.h"
#include <stdio.h>
#include <windows.h>
#include "../lavenes.h"

//Vẽ RadioBox tại tọa độ xy
void RadioBoxElement(RadioBox radioBox) {
    //Vẽ box tại tọa độ x,y
    if(radioBox.checked) { //isChecked
        draw("[x]", radioBox.x, radioBox.y, radioBox.boxColor, 437);
    }else{
        draw("[ ]", radioBox.x, radioBox.y, radioBox.boxColor, 437);
    }

    //Vẽ label
    int labelX = radioBox.x + 5;
    int labelY = radioBox.y;

    draw(radioBox.label, labelX, labelY, radioBox.labelColor, radioBox.codePage);
}