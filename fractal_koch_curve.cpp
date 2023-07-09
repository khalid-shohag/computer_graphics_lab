#include<graphics.h>
#include<math.h>
#define PI 3.14

void draw_koch_curve(int x1, int y1, int x2, int y2, int no_of_iteration, bool outer_direction)
{
    float angle = 60*PI/180;
    int mid_first_x = x1+(x2-x1)/3;
    int mid_first_y = y1 + (y2-y1)/3;
    int mid_sec_x = x1+(x2-x1)*2/3;
    int mid_sec_y = y1 + (y2-y1)*2/3;
    int mid_x, mid_y;

    if(outer_direction)
    {
        mid_x = mid_first_x+cos(angle)*(mid_sec_x-mid_first_x) - sin(angle)*(mid_sec_y-mid_first_y);
        mid_y =mid_first_y+sin(angle)*(mid_sec_x-mid_first_x) + cos(angle)*(mid_sec_y-mid_first_y);
    }
    else
    {
        mid_x = mid_first_x+cos(angle)*(mid_sec_x-mid_first_x) + sin(angle)*(mid_sec_y-mid_first_y);
        mid_y =mid_first_y-sin(angle)*(mid_sec_x-mid_first_x) + cos(angle)*(mid_sec_y-mid_first_y);
    }

    if(no_of_iteration>0)
    {
        draw_koch_curve(x1, y1, mid_first_x, mid_first_y, no_of_iteration-1, outer_direction);
        draw_koch_curve(mid_first_x, mid_first_y, mid_x, mid_y, no_of_iteration-1, outer_direction);
        draw_koch_curve(mid_x, mid_y, mid_sec_x, mid_sec_y, no_of_iteration-1, outer_direction);
        draw_koch_curve(mid_sec_x, mid_sec_y, x2, y2, no_of_iteration-1, outer_direction);
    }
    else
    {
        line(x1, y1, mid_first_x, mid_first_y);
        line(mid_first_x, mid_first_y, mid_x, mid_y);
        line(mid_x, mid_y, mid_sec_x, mid_sec_y);
        line(mid_sec_x, mid_sec_y, x2, y2);
    }
}

int main()
{
    initwindow(1000, 1000);
    int x1 = 300, y1 = 250, x2 = 700, y2 = 450;
    float angle = 60*PI/180;
    int x3 = x1+cos(angle)*(x2-x1) + sin(angle)*(y2-y1), y3 =y1- sin(angle)*(x2-x1) + cos(angle)*(y2-y1);

    draw_koch_curve(x1, y1, x2, y2, 3, false);
    draw_koch_curve(x1, y1, x3, y3, 3, false);
    draw_koch_curve(x2, y2, x3, y3, 3, true);
    getch();
}
