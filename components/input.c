/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "input.h"
#include <stdio.h>
#include <windows.h>
#include "../lavenes.h"

//Vẽ textbox tại tọa độ xy
void InputElement(Input input) {
    int i; //i: width

    //Viết label trước button tại xy
    draw(input.label, input.x, input.y, input.labelColor, input.codePage);

    //Tính toán tọa độ xy cho input
    int inputX = input.x + strlen_utf8(input.label) + 1;
    int inputY = input.y;
    int inputWidth = (inputX + input.width);

    //Vẽ input tại tọa độ
    for(i = inputX; i < inputWidth; i++) { //Width
        draw("_", i, inputY, input.inputColor, 437);
    }

    //Viết value lên button
    //Tính toán tọa độ xy
    int titleX = inputX;
    int titleY = inputY;

    //Tính toán tọa độ căn ngang
    if(input.align == 1) { //Center
        titleX = (inputWidth - strlen_utf8(input.value) + inputX) / 2; //Tính toán tọa độ căn giữa
    }else if(input.align == 2) { //Right
        titleX = (inputWidth - strlen_utf8(input.value)); //Tính toán tọa độ căn trái
    }else{ //Left
        titleX = inputX;
    }

    //Vẽ Button
    draw(input.value, titleX, titleY, input.inputColor, input.codePage);

}