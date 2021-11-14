/*
    THƯ VIỆN VẼ UI CONSOLE ĐƯỢC PHÁT TRIỂN BỞI QUANG NHẬT
    DEVELOPMENT BY QUANG NHẬT
*/

#include "alert.h"
#include <stdio.h>
#include <windows.h>
#include "../libs/process.h"
#include "../libs/ui.h"
#include "./button.h"

void AlertElement(Alert alert) {
    //Vẽ title bar
    int alertEndX = alert.x + alert.width;
    int alertEndY = alert.y;

    square(alert.x, alert.y, alertEndX, alertEndY, alert.titleBarColor);

    //Viết title lên title bar
    int titleX = (alert.width - strlen_utf8(alert.title)) / 2 + alert.x;
    int titleY = alert.y;

    draw(alert.title, titleX, titleY, alert.titleColor, alert.codePage);

    //Vẽ vùng content
    int alertSpaceEndX = alert.x + alert.width;
    int alertSpaceEndY = alert.y + alert.height;

    square(alert.x, alert.y + 1, alertSpaceEndX, alertSpaceEndY, alert.backgroundColor);

    //Viết content lên alert
    //Tính toán căn giữa form
    int contentX = (alert.width - strlen_utf8(alert.content)) / 2 + alert.x;
    int contentY = (alert.height - 3) / 2 + alert.y + 1;

    draw(alert.content, contentX, contentY, alert.contentColor, alert.codePage);

    //Viết ok button
    //Tính toán vị trí button giữa form
    int buttonX = (alert.width - 4) / 2 + alert.x;
    int buttonY = alert.y + alert.height - 2;

    Button btn = {"OK",buttonX, buttonY, 4, 1, alert.titleBarColor, 1, 437};

    ButtonElement(btn);

    //Vẽ shadow
    int shadowStartX = alert.x + 1;
    int shadowEndX = alert.width + alert.x;
    int shadowStartY = alert.y + 1;
    int shadowEndY = alert.height + alert.y;

    square(shadowStartX, shadowEndY, shadowEndX, shadowEndY, 15); //Shadow ngang
    square(shadowEndX, shadowStartY, shadowEndX, shadowEndY + 1, 15); //Shadow dọc
}