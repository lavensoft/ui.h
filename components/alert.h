/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

typedef struct _alert {
    char title[128];
    char content[128];
    int x;
    int y;
    int width;
    int height;
    int titleColor;
    int titleBarColor;
    int contentColor;
    int backgroundColor;
    int codePage;
}Alert;

void AlertElement(Alert alert);