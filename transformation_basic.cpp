#include<graphics.h>
#include<iostream>
#include<math.h>
#define PI 3.14
using namespace std;

void translation(int x[], int y[], int tx, int ty)
{
    //x1+=tx; y1+=ty; x2+=tx; y2+=ty;
    setcolor(RED);
    for(int i=0; i<4; i++)
    {
        line(x[i]+tx, y[i]+ty, x[(i+1)%4]+tx, y[(i+1)%4]+ty);
    }
}

void scaling(int x[], int y[], float sx, float sy)
{
    setcolor(BLUE);
    for(int i=0; i<4; i++)
    {
        line(x[i]*sx, y[i]*sy, x[(i+1)%4]*sx, y[(i+1)%4]*sy);
    }
}

void rotation(int x[], int y[],  float angle)
{
    setcolor(GREEN);
    for(int i=0; i<4; i++)
    {
        int rx1 = x[i]*cos(angle) - y[i]*sin(angle);
        int ry1 = x[i]*sin(angle) + y[i]*cos(angle);
        int rx2 = x[(i+1)%4]*cos(angle) - y[(i+1)%4]*sin(angle);
        int ry2 = x[(i+1)%4]*sin(angle) + y[(i+1)%4]*cos(angle);
        line(rx1, ry1, rx2, ry2);
    }
}

int main()
{
    initwindow(1000, 1000);

    int x[] = {200, 200, 500, 500};
    int y[] = {200, 500, 500, 200};

    for(int i=0; i<4; i++)
    {
        line(x[i], y[i], x[(i+1)%4], y[(i+1)%4]);
    }

//    int x1 = 200, y1 = 200, x2 = 500, y2 = 500;
//    rectangle(x1, y1, x2, y2);
    //translation vector
    int tx = 295, ty = 295;
    translation(x, y, tx, ty);
//
    //scaling factors
    float sx = 0.7, sy = 0.7;
    scaling(x, y, sx, sy);
//
    float angle = 15*PI/180;
    rotation(x, y, angle);
    getch();
    return 0;
}
