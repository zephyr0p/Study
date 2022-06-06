#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    int x,y,t;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    x = 100;
    y = 300;
    cout << "\nEnter Scaling factor:";
    cin >> t;
    bar3d (x+50,y-100,x+100,y-50,20,1);
    delay(1000);
    bar3d (x+(t*50),y-(t*100),x+(t*100),y-(t*50),t*20,1);
    getch();
    closegraph();
}
