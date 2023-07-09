#include<graphics.h>
#include<iostream>
using namespace std;

void sutherland_line_clipping(int x1, int y1, int x2, int y2, int xwmin, int ywmin, int xwmax, int ywmax)
{
    int region_begin[] = {0, 0, 0, 0}, region_end[] = {0, 0, 0, 0}, region_code[4];
    bool inside = true;

    //begin point region code
    if(x1<xwmin)
    {
        region_begin[0] = 1;
        inside = false;
    }
    if(x1>xwmax)
    {
        region_begin[1]=1;
        inside = false;
    }
    if(y1<ywmin)
    {
        region_begin[2] = 1;
        inside = false;
    }
    if(y1>ywmax)
    {
        region_begin[3] = 1;
        inside = false;
    }

    //end point region code
    if(x2<xwmin)
    {
        region_end[0] = 1;
        inside = false;
    }
    if(x2>xwmax)
    {
        region_end[1]=1;
        inside = false;
    }
    if(y2<ywmin)
    {
        region_end[2] = 1;
        inside = false;
    }
    if(y2>ywmax)
    {
        region_end[3] = 1;
        inside = false;
    }

    if(inside)
        return;

    for(int i=0; i<4; i++)
    {
        region_code[i] = region_begin[i] && region_end[i];
        if(region_code[i]==1)
        {
            return;
        }
    }

    int slope = (y2-y1)/(x2-x1);
    //find intersection of begin point
    // left side
    if(region_begin[0]==1 && region_begin[1]==0)
    {
        y1+=slope*(xwmin-x1);
        x1 = xwmin;
    }
    //right side
    else if(region_begin[0]==0 && region_begin[1]==1)
    {
        y1+=slope*(xwmax-x1);
        x1 = xwmax;
    }

    //below side
    if(region_begin[2]==1 && region_begin[3]==0)
    {
        x1+=(ywmin-y1)/slope;
        y1 = ywmin;
    }
    else if(region_begin[2]==0 && region_begin[3]==1)
    {
        x1+=(ywmax-y1)/slope;
        y1 = ywmax;
    }

    //find intersection of end point
    //left side
    if(region_end[0]==1 && region_end[1]==0)
    {
        y2+=(xwmin-x2)*slope;
        x2 = xwmin;
    }
    //right side
    else if(region_end[0]==0 && region_end[1]==1)
    {
        y2+=(xwmax-x2)*slope;
        x2 = xwmax;
    }

    //below
    if(region_end[2]==1 && region_end[3]==0)
    {
        x2+=(ywmin-y2)/slope;
        y2 = ywmin;
    }
    //above
    else if(region_end[2]==0 && region_end[3]==1)
    {
        x2+=(ywmax-y2)/slope;
        y2=ywmax;
    }

    cout << x1 << " " << y1 << endl;
    setcolor(RED);
    line(x1, y1, x2, y2);

}

int main()
{
    initwindow(1000, 1000);
    int x1 = 200, y1 = 250, x2 = 500, y2 = 550;
    line(x1, y1, x2, y2);
    int xwmin = 220, ywmin = 270, xwmax = 510, ywmax = 500;
    rectangle(xwmin, ywmin, xwmax, ywmax);
    sutherland_line_clipping(x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax);
    getch();
}
