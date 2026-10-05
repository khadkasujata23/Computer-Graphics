#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

void multiply(float T[3][3], float A[3][4], float R[3][4])
{
    int i, j, k;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            R[i][j] = 0;
            for(k = 0; k < 3; k++)
            {
                R[i][j] += T[i][k] * A[k][j];
            }
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    float angle = 45;
    float rad = angle * PI / 180;


    float A[3][4] = {
        {100, 150, 200, 100},   
        {100,  50, 100, 100},   
        {1,     1,   1,   1}
    };

    
    float T[3][3] = {
        { cos(rad), -sin(rad), 0 },
        { sin(rad),  cos(rad), 0 },
        {     0,          0,   1 }
    };

    float R[3][4];

    multiply(T, A, R);

    
    setcolor(WHITE);
    line(A[0][0], A[1][0], A[0][1], A[1][1]);
    line(A[0][1], A[1][1], A[0][2], A[1][2]);
    line(A[0][2], A[1][2], A[0][0], A[1][0]);

    
    setcolor(RED);
    line(R[0][0], R[1][0], R[0][1], R[1][1]);
    line(R[0][1], R[1][1], R[0][2], R[1][2]);
    line(R[0][2], R[1][2], R[0][0], R[1][0]);

    getch();
    closegraph();
    return 0;
}
