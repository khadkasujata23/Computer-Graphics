#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    int xc, yc, r;
    int x, y, p;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center of circle (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius of circle: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    p = 1 - r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p < 0)
        {
            p = p + 2 * x + 3;
        }
        else
        {
            p = p + 2 * (x - y) + 5;
            y = y - 1;
        }
        x = x + 1;
    }

    getch();
    closegraph();
    return 0;
}
