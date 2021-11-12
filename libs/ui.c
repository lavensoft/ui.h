/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "ui.h"
#include <stdio.h>
#include<windows.h>

void gotoXY(int x, int y);
void setColor(int x);

//vẽ nội dung trên tọa độ xy với màu có thể thêm codePage để đổi output pageId
void draw(char content[], int x, int y, int color, int codePage) {
    //Đổi màu output console
    setColor(color);

    //Đổi output page id theo định dạng
    SetConsoleOutputCP(codePage);

    //Chuyển con trỏ đến tọa độ x, y trên console buffer
    gotoXY(x,y);

    //Vẽ nội dung lên màn hình
    printf("%s", content);

    //Đặt output console pageId về mặt định
    SetConsoleOutputCP(437);

    //Đặt color về màu mặc định
    setColor(15);
}

//di chuyển con trỏ đến một vị trí x, y trên console
void gotoXY(int x, int y) {
    COORD coord; //Khai báo coord
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); //Update x, y coord
}

//Vẽ một vùng từ vị trí x,y  đến x,y với màu
void square(int startX, int startY, int endX, int endY, int color) {
    int x,y;

    for(x = startX; x < endX + (startX != endX ? 0 : 1); x ++) { //Width
        for(y = startY; y < endY + (startY != endY ? 0 : 1); y ++) { //Height
            draw(" ", x, y, color, 437);
        }
    }
}

//Đặt màu cho console với mã màu
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

//Xóa màn hình không sử dụng system clear vì sẽ gây xung đột với mouse click
//Tham khảo từ thư viện console.h Nguyen Trung Thanh
void clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}