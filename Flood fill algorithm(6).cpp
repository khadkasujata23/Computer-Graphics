

#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void floodFill(int x, int y, int old_color, int new_color)
{
    int current;

    current = getpixel(x, y);

    if (current == old_color)
    {
        putpixel(x, y, new_color);

        floodFill(x + 1, y, old_color, new_color);
        floodFill(x - 1, y, old_color, new_color);
        floodFill(x, y + 1, old_color, new_color);
        floodFill(x, y - 1, old_color, new_color);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    
    rectangle(150, 100, 300, 250);


    floodFill(200, 150, BLACK, RED);

    getch();
    closegraph();
    return 0;
}
