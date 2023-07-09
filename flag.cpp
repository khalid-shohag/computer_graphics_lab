#include<graphics.h>

int main()
{
    initwindow(1000, 1000);
    setcolor(GREEN);
    rectangle(100, 100, 500, 300);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(200, 104, GREEN);
    setcolor(RED);
    circle(300, 200, 50);
    setfillstyle(SOLID_FILL, RED);
    floodfill(300, 204, RED);
    getch();
}
