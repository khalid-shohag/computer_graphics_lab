#include<graphics.h>
#include<math.h>
#include<iostream>
#define PI 3.14

using namespace std;

void translation(int x1, int y1, int x2, int y2, int Tx, int Ty)
{
    x1+=Tx; x2+=Tx; y1+=Ty; y2+=Ty;
    setcolor(GREEN);
    rectangle(x1, y1, x2, y2);
}

void rotation(int x1, int y1, int x2, int y2, float angle)
{
    int rx1 = x1*cos(angle) - y1*sin(angle);
    int ry1 = x1*sin(angle) + y1*cos(angle);
//    int rx2 = x2*cos(angle) - y2*sin(angle);
//    int ry2 = x2*sin(angle) + y2*cos(angle);
//    cout << rx1 << " " << ry1 << " " << rx2 << " " << ry2 << endl;
    setcolor(RED);
    rectangle(rx1, ry1, x2, y2);
}

void scaling(int x1, int y1, int x2, int y2, float sx, float sy)
{
    x1*=sx; x2*=sy; y1*=sy; y2*=sy;
    setcolor(BLUE);
    rectangle(x1, y1, x2, y2);
}

int main()
{
    initwindow(1000, 1000);
    int x1 = 100, y1 = 50, x2 = 400, y2 = 350;
    rectangle(x1, y1, x2, y2);
    translation(x1, y1, x2, y2, 100, 130);
    rotation(x1, y1, x2, y2, 30*PI/180);
    scaling(x1, y1, x2, y2, 0.5, 0.5);
    getch();
}
