#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

void combination(int n, int c[])
{
    for(int i=0; i<=n; i++)
    {
        c[i] = 1;
        for(int j=n; j>=i+1; j--)
            c[i]*=j;
        for(int k=n-i; k>=2; k--)
            c[i]/=k;
    }
}

void draw_curve(int points, int x_points[], int y_points[])
{
    int degree = points-1;
    int combinations[points];

    combination(degree, combinations);
    for(int i=0; i<points; i++)
        cout << combinations[i] << " ";
    cout << endl;
    freopen("output_curve.txt", "w", stdout);

    for(float u=0; u<=1; u+=0.002)
    {
        int px = 0, py = 0;
        for(int i=0; i<=degree; i++)
        {
            px+=x_points[i]*combinations[i]*pow(u, i)*pow(1-u, degree-i);
            py+=y_points[i]*combinations[i]*pow(u, i)*pow(1-u, degree-i);
        }
        cout << px << " " << py << endl;
        putpixel(px, py, WHITE);
    }

}

int main()
{
    int points;
    freopen("input_curve.txt","r", stdin);
    cin >> points;
    int x_points[points];
    int y_points[points];
    for(int i=0; i<points; i++)
    {
        cin >> x_points[i] >> y_points[i];
    }
    initwindow(1000, 1000);
    for(int i=0; i<4; i++)
        putpixel(x_points[i], y_points[i], WHITE);
    draw_curve(points, x_points, y_points);
//    int x_points[] = {100, 200, 400, 600};
//    int y_points[] = {100, 300, 300, 400};

    getch();
}
