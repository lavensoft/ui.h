/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

typedef struct _input {
    char label[128];
    char value[128];
    int x;
    int y;
    int width;
    int labelColor;
    int inputColor;
    int align;
    int codePage;
}Input;

void InputElement(Input input);