/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

typedef struct _button {
    char title[128];
    int x;
    int y;
    int width;
    int height;
    int color;
    int align;
    int codePage;
}Button;

void ButtonElement(Button btn);