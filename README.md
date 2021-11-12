# UI.h - C/C++ UI Library
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://lavenes.com)
## Mô tả
---
Thư viện giúp bạn xây dựng UI trong console với C và C++ dành cho thành viên tại [FPT Polytechnic](https://caodang.fpt.edu.vn/) được phát triển bởi [Quang Nhật](https://www.facebook.com/nhatsdevil.mc).

<br/>
<center><img src="https://i.imgur.com/XnuuaOM.png"></center>
<br/>

## Documents
- [Cài đặt và sử dụng](#install)
- [Sự kiện chuột và bàn phím](#events)
  - [Chuột](#mouse)
  - [Bàn phím](#keyboard)
- [UI Components](#ui-components)
  - [Header Bar](#header-bar)
  - [Radio Box](#radio-box)
  - [Button](#button)
  - [Textbox](#textbox)
  - [Alert](#alert)
- [Drawing functions](#draw-func)
  - [Vẽ nội dung trên tọa độ X, Y](#draw)
  - [Di chuyển con trỏ tới tọa độ X, Y](#gotoxy)
  - [Vẽ một vùng hình vuông](#square)
  - [Đặt màu cho console](#set-color)
  - [Clear màn hình](#clear)
  - [Codepage](#codepage)
  - [Colors](#colors)

## Cài đặt và sử dụng

1. Bạn hãy tải mã nguồn từ trang git này sau đó giải nén vào folder dự án bạn muốn sử dụng thư viện
2. Import thư viện sau khi muốn sử dụng:
```c
#include "lavenes.h"
```

## Sự kiện chuột và bàn phím

>Khi sử dụng sự kiện bạn sẽ không sử dụng được scanf để lấy dữ liệu nhậ,
>bạn hãy xem sự kiện bàn phím để lấy giá trị và lưu vào biến nhé

Để sử dụng bạn init lệnh sau trước khi sử dụng
```c
//Setup mouse event
InitMouseStruct mouse = initMouse();

while(1) {
    InputStruct mouseStruct = initInput(mouse);
    
    //Các lệnh xử lý sự kiện chuột và bàn phím
}
```

### Chuột
Sự kiện bắt các thao tác chuột trên console bao gồm  tọa độ và phím nhấn. Để sử dụng API này bạn hãy init lệnh sau trước khi sử dụng:

```c
if(mouseStruct.eventType == MOUSE_EVENT) {
    //Xử lý thao tác trên chuột
}
```

Lấy tọa độ của chuột:
```c
int posX = mouseStruct.mouse.X; //Tọa độ X
int posY = mouseStruct.mouse.Y; //Tọa độ Y
```

Lấy phím nhấn từ chuột:
```c
//Chuột trái
if(mouseStruct.mouse.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
    //Code
}

//Chuột phải
if(mouseStruct.mouse.buttonState == FROM_LEFT_2ND_BUTTON_PRESSED) {
    //Code
}

//Chuột giữa
if(mouseStruct.mouse.buttonState == FROM_LEFT_3RD_BUTTON_PRESSED) {
    //Code
}

```

### Bàn phím
Sự kiện bắt các thao tác từ bàn phím. Để sử dụng API này bạn hãy init lệnh sau trước khi sử dụng:
```c
if(mouseStruct.eventType == KEY_EVENT) {
    //Code xử lý
}
```

Kiểm tra  người dùng có đang nhấn bàn phím hay không:

```c
if(mouseStruct.key.bKeyDown) {
    //Code
}
```

Lấy thông tin ký tự người dùng đã nhấn
```c
//Ascii Char
char key = mouseStruct.key.AsciiChar;
```

Cùng các kiểu khác:
```c
struct key {
    DWORD wVirtualKeyCode;
    CHAR AsciiChar;
    WCHAR UnicodeChar;
    BOOL bKeyDown;
    WORD dwControlKeyState;
    WORD wRepeatCount;
    WORD wVirtualScanCode;
}
```

## UI Components
### Header bar
Để tạo một header bạn sử dụng hàm sau:
```c
headerBar(title, width);

//title: tiêu đề (string)
//width: độ dài (int)
```

### Radio Box
Để tạo một Radio Box  bạn sử dụng code sau:
```c
//Khai báo cấu hình Radio Box
//Cách 1
RadioBox radio; 
radio.label = "Tiêu đề radio  box";
radio.x = 0; //Tọa độ  x
radio.y = 0; //Tọa độ y
radio.labelColor = 240; //Màu cho label
radio.boxColor = 240; //Màu cho Radio box
radio.checked = true; //Trạng thái cho radio box cho check  hay không
radio.codePage = 437; //Code page cho radio box

//Cách 2
//RadioBox radio = {title, x, y, labelColor, boxColor, checked, codePage};
RadioBox radio = {"Tiêu đề radio Box", 0, 0, 240, 240, true, 437};

//Vẽ radio box lên màn hình
RadioBoxElement(radio);
```

### Button
Để tạo một Button bạn sử dụng code sau:

```c
//Khai báo cấu hình Button
//Cách 1
Button btn;
btn.title = "Tiêu đề button"; //Tiêu đề Button
btn.x = 0; //Tọa độ x
btn.y = 0; //Tọa độ y
btn.width = 100; //Độ dài button
btn.height = 1; //Độ rộng button
btn.color = 240; //Màu cho button
btn.align = 1; //Align cho  button- 0: Left, 1: Center, 2: Right
btn.codePage = 437; //Codepage cho Button

//Cách 2
//Button btn = {title, x, y, width, height, color, align, codePage};
Button btn = {"Tiêu đề button", 0, 0, 100, 1, 240, 1, 437};

//Vẽ button lên màn hình
ButtonElement(btn);
```

### Textbox
Để tạo một Textbox bạn sử dụng code sau:

```c
//Khai báo cấu hình Textbox
//Cách 1
Input textbox;
textbox.label = "Label"; //Label cho Textbox
textbox.value = "Hello"; //Value cho Textbox
textbox.x = 0; //Tọa độ x
textbox.y = 0; //Tọa độ y
textbox.width = 10; //Độ dài Textbox
textbox.labelColor = 15; //Màu cho label
textbox.inputColor = 240; //Màu cho Textbox
textbox.align = 0; //Align cho Textbox: 0-Left; 1-Center; 2-Right
textbox.codePage = 437; //Codepage cho Textbox

//Cách 2
//Input textbox = {label, value, x, y, width, labelColor, inputColor, align, codePage};
Input textbox = {"Label", "Hello", 0, 0, 10, 15, 240, 0, 437};

//Vẽ Textbox lên màn hình
InputElement(textbox);
```

### Alert
Để tạo một Alert bạn sử dụng lệnh sau:

```c
//Khai báo cấu hình  Alert
//Cách 1
Alert alert;
alert.title = "Tieu de"; //Tiêu  đề cho title bar
alert.content = "Noi dung"; //Nội dung cho Alert 
alert.x = 0; //Tọa độ x
alert.y = 0; //Tọa độ y
alert.width = 20; //Chiều dài
alert.height = 10; //Chiều rộng
alert.titleColor = 159; //Màu title bar
alert.titleBarColor = 159; //Màu background title bar
alert.contentColor = 240; //Màu cho nội dung
alert.backgroundColor = 240; //Màu background cho nội dung
alert.codePage = 437; //Codepage

//Cách 2
//Alert alert = {title, content, x, y, width, height, titleColor, titleBarColor, contentColor, backgroundColor, codePage};
Alert alert = {"Tieu de", "Noi dung", 0, 0, 20, 10, 159, 159, 240, 240, 437};

//Vẽ Alert lên màn hình
AlertElement(alert);
```

## Drawing Functions
Các hàm xử lý vẽ lên  màn hình

### Draw
Vẽ nội dung trên tọa độ X, Y với màu

```c
//draw(content, x, y, color, codePage);

draw("HELLO", 0, 0, 240, 437);
```

### GotoXY
Di chuyển con trỏ đến tọa độ X, Y

```c
//gotoXY(x, y);

gotoXY(2, 5);
```

### Square
Vẽ một vùng từ vị trí x,y  đến x,y với màu

```c
//square(startX, startY, endX, endY, color);

square(0, 0, 10, 10, 240);
```

### Set Color
Đổi màu cho console

```c
//setColor(color); //color: mã màu

setColor(240);
```

### Codepage
Hiện tại có các mã code page sau được sử dụng nhiều:
Xem thêm các mã khác tại: [Microsoft Code Page Identifiers](https://docs.microsoft.com/en-us/windows/win32/intl/code-page-identifiers)

| Identifier      | Additional information |
| ----------- | ----------- |
| 437      | OEM United States - Mặc định của console       |
| 65001   | Unicode (UTF-8) - Sử dụng để viết tiếng Việt lên console        |

### Colors
Đây là bảng mã màu cho console

<br/>
<center><img src="https://i.imgur.com/zO5hsDD.jpg"></center>
<br/>

<br/>

[Designed by Lavenes in Ho Chi Minh city.](https://lavenes.com/)