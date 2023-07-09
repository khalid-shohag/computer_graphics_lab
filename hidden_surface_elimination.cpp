#include<graphics.h>

void circles()
{
    setcolor(RED);
    circle(100, 300, 50);
    setfillstyle(SOLID_FILL, RED);
    floodfill(100, 305, RED);
}

void triangle()
{
    setcolor(GREEN);
    line(115, 265, 115, 335);
    line(115, 265, 215, 300);
    line(115, 335, 215, 300);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(120, 300, GREEN);
}

void square()
{
    setcolor(BLUE);
    rectangle(80, 230, 170, 300);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(90, 270, BLUE);
}

int main()
{
    printf("Enter a number: ");
    int number;
    scanf("%d", &number);
    initwindow(1000, 1000);
    if(number==1)
    {
        square();
        circles();
        triangle();
    }
    else if(number==2)
    {
        circles();
        square();
        triangle();
    }
    else if(number==3)
    {
        circles();
        triangle();
        square();
    }
    else if(number==4)
    {
        triangle();
        circles();
        square();
    }
    else if(number==5)
    {
        triangle();
        square();
        circles();
    }
    else if(number==6)
    {
        square();
        triangle();
        circles();
    }

    getch();
}
