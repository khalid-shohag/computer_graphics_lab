#include<graphics.h>
#include<math.h>

void draw_line(int x1, int y1, int x2, int y2)
{
    int dx = abs(x1-x2), dy = abs(y1-y2);
    int p = 2*dy - dx;
    putpixel(x1, y1, WHITE);
    int y = y1;
    while(x1<x2)
    {
        x1++;
        if(p<0)
        {
            p+=2*dy;
        }
        else
        {
            p+=2*dy-2*dx;
            y+=1;
        }
        putpixel(x1, y, WHITE);
    }
}

int main()
{
    initwindow(1000, 1000);
//    line(100, 100, 500, 100);
    int x1=100, y1=100, x2=500, y2=300;
    draw_line(x1, y1, x2, y2);
    getch();
    return 0;
}
