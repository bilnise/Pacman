#include "utils.h"

void gotoligcol(int lig, int col)
{
    COORD mycoord;

    mycoord.X  = col;
    mycoord.Y  = lig;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

int getWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);

    return screen_buffer_info.dwMaximumWindowSize.X;
}

int getHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);

    return screen_buffer_info.dwMaximumWindowSize.Y;
}

