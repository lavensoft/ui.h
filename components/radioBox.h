/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

typedef enum {false, true} bool;

typedef struct _radioBox {
    char label[128];
    int x;
    int y;
    int labelColor;
    int boxColor;
    bool checked;
    int codePage;
}RadioBox;

void RadioBoxElement(RadioBox radioBox);