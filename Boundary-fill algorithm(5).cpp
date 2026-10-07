
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void boundaryFill(int x, int y, int fill_color, int boundary_color)
{
    int current;

    current = getpixel(x, y);

    if (current != boundary_color && current != fill_color)
    {
        putpixel(x, y, fill_color);

        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    
    rectangle(150, 100, 300, 250);

    
    boundaryFill(200, 150, GREEN, WHITE);

    getch();
    closegraph();
    return 0;
}
