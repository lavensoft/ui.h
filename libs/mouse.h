/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include <windows.h>

typedef struct _mouseInitStruct {
    HANDLE console;
    INPUT_RECORD irInBuf[128];
    DWORD cNumRead;
    DWORD i;
} InitMouseStruct;

typedef struct _mouseStruct {
    DWORD buttonState;
    int X;
    int Y;
}MouseStruct;

typedef struct _keyboardStruct {
    DWORD wVirtualKeyCode;
    CHAR AsciiChar;
    WCHAR UnicodeChar;
    BOOL bKeyDown;
    WORD dwControlKeyState;
    WORD wRepeatCount;
    WORD wVirtualScanCode;
}KeyBoardStruct;

typedef struct _inputStruct {
    MouseStruct mouse;
    KeyBoardStruct key;
    WORD eventType;
}InputStruct;

InitMouseStruct initMouse();
InputStruct initInput(InitMouseStruct mouse);