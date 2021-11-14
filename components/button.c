/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "button.h"
#include <stdio.h>
#include <windows.h>
#include "../libs/process.h"
#include "../libs/ui.h"

//Vẽ button tại tọa  độ xy với chiều dài và chiều rộng cùng code page và màu
//Align 0: left; 1: center; 2: right
void ButtonElement(Button btn) {
    //Vẽ button tại tọa độ
    int buttonEndX = btn.x + btn.width;
    int buttonEndY = btn.y + btn.height;

    square(btn.x, btn.y, buttonEndX, buttonEndY, btn.color);

    //Viết tiêu đề lên button
    //Tính toán tọa độ xy
    int titleX = btn.x;
    int titleY = btn.y;

    titleY = (btn.height) / 2 + titleY; //Tính toán tọa độ căn giữa dọc

    //Tính toán tọa độ căn ngang
    if(btn.align == 1) { //Center
        titleX = (btn.width - strlen_utf8(btn.title)) / 2 + btn.x; //Tính toán tọa độ căn giữa
    }else if(btn.align == 2) { //Right
        titleX = (btn.width - strlen_utf8(btn.title) - 1) + btn.x; //Tính toán tọa độ căn trái
    }else{ //Left
        titleX = btn.x + 1;
    }

    //Vẽ Button
    draw(btn.title, titleX, titleY, btn.color, btn.codePage);
}