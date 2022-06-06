#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int gd=DETECT, gm;
    int s;
    int x1=50, y1=50;
    int x2=150, y2=50;
    int x3=150, y3=150;
    int x4=50, y4=150;
    clrscr();
    
    initgraph (&gd, &gm, "C:\\TC\\BGI");
    cout << "\nEnter Scaling Factor:";
    cin >> s;
    line (x1,y1,x2,y2);
    line (x2,y2,x3,y3);
    line (x3,y3,x4,y4);
    line (x4,y4,x1,y1);
    
    delay(1000);
    
    line (x1*s,y1*s,x2*s,y2*s);
    line (x2*s,y2*s,x3*s,y3*s);
    line (x3*s,y3*s,x4*s,y4*s);
    line (x4*s,y4*s,x1*s,y1*s);
    
    getch();
    closegraph();
}
