/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "headerBar.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../libs/ui.h"
#include "../libs/mouse.h"

//Header bar
void headerBar(char title[], int consoleWidth) {
    SetConsoleOutputCP(65001); //Chuyển output sang utf8;

    int i;

    //Draw bar
    square( 0, 0, consoleWidth, 0, 252);

    //Draw close btn
    gotoXY(0,0);
    printf(" [x] ");

    //Draw title
    gotoXY((consoleWidth / 2) - (strlen(title) / 2), 0);
    printf("%s", title);

    //Chuyển console về mặc định
    setColor(15);
    SetConsoleOutputCP(437);//IBM
}