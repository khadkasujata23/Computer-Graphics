#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, p, x, y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    p = 2 * dy - dx;

    x = x1;
    y = y1;

    while (x <= x2)
    {
        putpixel(x, y, WHITE);

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * (dy - dx);
            y = y + 1;
        }
        x = x + 1;
    }

    getch();
    closegraph();
    return 0;
}
