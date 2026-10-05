#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void multiply(int T[3][3], int A[3][4], int R[3][4])
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

    
    int A[3][4] = {
        {100, 150, 200, 100},   
        {100,  50, 100, 100},   
        {1,     1,   1,   1}
    };

    
    int T[3][3] = {
        {1, 0, 120},
        {0, 1, 60},
        {0, 0, 1}
    };

    int R[3][4];

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
