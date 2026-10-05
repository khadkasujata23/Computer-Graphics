#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int xc, yc, rx, ry;
    int x = 0, y;
    long rx2, ry2;
    long p1, p2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter rx and ry: ");
    scanf("%d %d", &rx, &ry);

    rx2 = rx * rx;
    ry2 = ry * ry;

    y = ry;
    p1 = ry2 - (rx2 * ry) + (rx2 / 4);

    while ((2 * ry2 * x) <= (2 * rx2 * y))
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0)
            p1 += (2 * ry2 * x) + ry2;
        else
        {
            y--;
            p1 += (2 * ry2 * x) - (2 * rx2 * y) + ry2;
        }
        x++;
    }

    
    p2 = (ry2 * (x + 0.5) * (x + 0.5)) +
         (rx2 * (y - 1) * (y - 1)) -
         (rx2 * ry2);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0)
            p2 -= (2 * rx2 * y) + rx2;
        else
        {
            x++;
            p2 += (2 * ry2 * x) - (2 * rx2 * y) + rx2;
        }
        y--;
    }

    getch();
    closegraph();
    return 0;
}
