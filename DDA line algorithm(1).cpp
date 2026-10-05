#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float dx, dy, steps, xinc, yinc, x, y;
    int i;

    initgraph(&gd, &gm, "");

    printf("Enter x1 and y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 and y2: ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x = x1;
    y = y1;

    for(i = 0; i <= steps; i++)
    {
        putpixel(x, y, WHITE);
        x = x + xinc;
        y = y + yinc;
    }

    getch();
    closegraph();
    return 0;
}
