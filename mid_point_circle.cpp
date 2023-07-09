#include<graphics.h>
#include<iostream>
using namespace std;

void plotcirclepixels(int x_center, int y_center, int px, int py)
{
    cout << px << " " << py << endl;
    putpixel(x_center+px, y_center+py, WHITE);
    putpixel(x_center+py, y_center+px, WHITE);
    putpixel(x_center+py, y_center-px, WHITE);
    putpixel(x_center+px, y_center-py, WHITE);
    putpixel(x_center-px, y_center+py, WHITE);
    putpixel(x_center-py, y_center+px, WHITE);
    putpixel(x_center-py, y_center-px, WHITE);
    putpixel(x_center-px, y_center-py, WHITE);
}

void findmidpoint(int x, int y, int r)
{
    int p = 1 - r;
    int px = 0, py = r;
    plotcirclepixels(x, y, px, py);
    while(px<py)
    {
        px++;
        if(p<0)
        {
            p+=2*px+1;
        }
        else
        {
            p+=2*(px-py)+1;
            py-=1;
        }
        plotcirclepixels(x, y, px, py);
    }
}


int main()
{
    initwindow(1000, 1000);
    int x = 300, y =300, r = 100;
    findmidpoint(x, y, r);
    getch();
}
