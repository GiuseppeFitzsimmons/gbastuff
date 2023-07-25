#include "toolbox.h"

// extra stuff, also in tonc_video.h
#define M3_WIDTH SCREEN_WIDTH
// typedef for a whole mode3 line
typedef COLOR M3LINE[M3_WIDTH];
// m3_mem is a matrix; m3_mem[y][x] is pixel (x,y)
#define m3_mem ((M3LINE *)MEM_VRAM)

// void vid_vsync()
// {
//     while (REG_VCOUNT >= 160)
//         ; // wait till VDraw
//     while (REG_VCOUNT < 160)
//         ; // wait till VBlank
// }

int main()
{
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;
    // 0x0003 > 0x0000000000000011
    // 0x0400 > 0x0000100000000000
    //   |    > 0x0000100000000011
    int x, y;

    for (x = 1; x < SCREEN_HEIGHT; ++x)
    {
        y = 10 * x;
        m3_mem[x][y] = CLR_BLUE;
    }
    for (y = 1; y < SCREEN_WIDTH * 2; ++y)
    {
        x = 10 * y;
        m3_mem[x][y] = CLR_LIME;
    }
    for (y = SCREEN_WIDTH / 2; y < SCREEN_WIDTH; ++y)
    {
        x = 10 * y;
        m3_mem[x][y] = CLR_MAG;
    }

    while (1)
        ;
    return 0;
}

// H
// for (i = 120; i < 127; ++i)
// {
//     m3_mem[80][i] = CLR_BLUE;
// }
// for (i = 72; i < 88; ++i)
// {
//     m3_mem[i][120] = CLR_CYAN;
// }
// for (i = 72; i < 88; ++i)
// {
//     m3_mem[i][126] = CLR_RED;
// }

// // I
// for (i = 72; i < 88; ++i)
// {
//     m3_mem[i][136] = CLR_CYAN;
// }
