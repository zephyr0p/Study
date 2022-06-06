#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    int x,y,s;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    x = 100;
    y = 300;
    cout << "\nEnter Scaling factor:";
    cin >> s;
    bar3d (x+50,y-100,x+100,y-50,20,1);
    delay(1000);
    bar3d (x+(s*50),y-(s*100),x+(s*100),y-(s*50),s*20,1);
    getch();
    closegraph();
}
