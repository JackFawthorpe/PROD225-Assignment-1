#ifndef __PROD225COLOUR_H__
#define __PROD225COLOUR_H__

enum PROD225Colours
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

void MoveCursorTo(int column, int row);
void SetTextColour(int foreground, int background);

#endif // __PROD225COLOUR_H__
