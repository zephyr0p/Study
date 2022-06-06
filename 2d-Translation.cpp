#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int gd=DETECT, gm;
    int t;
    int x1=50, y1=50;
    int x2=150, y2=50;
    int x3=150, y3=150;
    int x4=50, y4=150;
    clrscr();
    
    initgraph (&gd, &gm, "C:\\TC\\BGI");
    cout << "\nEnter Translating Factor:";
    cin >> t;
    line (x1,y1,x2,y2);
    line (x2,y2,x3,y3);
    line (x3,y3,x4,y4);
    line (x4,y4,x1,y1);
    
    delay(1000);
    
    line (x1+t,y1+t,x2+t,y2+t);
    line (x2+t,y2+t,x3+t,y3+t);
    line (x3+t,y3+t,x4+t,y4+t);
    line (x4+t,y4+t,x1+t,y1+t);
    
    getch();
    closegraph();
}
