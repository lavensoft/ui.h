/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

typedef struct _radioBox {
    char label[128];
    int x;
    int y;
    int labelColor;
    int boxColor;
    int checked;
    int codePage;
}RadioBox;

void RadioBoxElement(RadioBox radioBox);