/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "mouse.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//Thiết lập cho  sự kiện chuột và bàn phím trên console
InitMouseStruct initMouse() {
    //Lấy std và setup các biến lấy buffer console
    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;
    DWORD cNumRead, fdwMode;
    
    //Tắt quickedit mode
    GetConsoleMode(console, &prev_mode); 
    SetConsoleMode(console, prev_mode & ENABLE_EXTENDED_FLAGS);

    //Kích hoạt sự kiện nhập bàn phím và chuột

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(console, fdwMode);

    InitMouseStruct mouse;

    mouse.console = console;
    mouse.cNumRead = cNumRead;

    return mouse;
}

//Thiết lập sự kiện input từ chuột và bàn phím
InputStruct initInput(InitMouseStruct mouse) {
    //Đọc events
    ReadConsoleInput(mouse.console, mouse.irInBuf,128, &mouse.cNumRead);
    InputStruct inputStruct;

    //Bắt các sự kiện bàn phím, chuột và xử lý
    for (mouse.i = 0; mouse.i < mouse.cNumRead; mouse.i++) {
        const MOUSE_EVENT_RECORD mer = mouse.irInBuf[mouse.i].Event.MouseEvent; //Chuột
        const KEY_EVENT_RECORD ker = mouse.irInBuf[mouse.i].Event.KeyEvent; //Bàn phím

        inputStruct.eventType = mouse.irInBuf[mouse.i].EventType;

        //Sự kiện chuột
        if(mouse.irInBuf[mouse.i].EventType == MOUSE_EVENT) {
            //Lấy tọa độ chuột
            const int posX = mer.dwMousePosition.X;
            const int posY = mer.dwMousePosition.Y;

            inputStruct.mouse.buttonState = mer.dwButtonState;

            inputStruct.mouse.X = posX;
            inputStruct.mouse.Y = posY;
        }else if(mouse.irInBuf[mouse.i].EventType == KEY_EVENT) { //Sự kiện bàn phím
            //Lấy key nhấn
            inputStruct.key.wVirtualKeyCode = ker.wVirtualKeyCode;
            inputStruct.key.AsciiChar = ker.uChar.AsciiChar;
            inputStruct.key.UnicodeChar = ker.uChar.UnicodeChar;
            inputStruct.key.bKeyDown = ker.bKeyDown;
            inputStruct.key.dwControlKeyState = ker.dwControlKeyState;
            inputStruct.key.wRepeatCount = ker.wRepeatCount;
            inputStruct.key.wVirtualScanCode = ker.wVirtualScanCode;
        }

        return inputStruct;
    }
}