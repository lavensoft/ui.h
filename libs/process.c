#include <stdio.h>
#include <windows.h>

//Function lấy ký tự utf8
//source: https://stackoverflow.com/questions/32936646/getting-the-string-length-on-utf-8-in-c
size_t strlen_utf8(const char *s) {
    size_t count = 0;
    while (*s) {
        count += (*s++ & 0xC0) != 0x80;
    }
    return count;
}