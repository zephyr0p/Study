#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int gd=DETECT, gm;
    int x1,x2,y1,y2,x3,y3,an;
    double c,s;
    initgraph (&gd, &gm, "C:\\TC\\BGI");
    cout << "\nEnter the points x1 and y1:";
    cin >> x1 >> y1;
    cout << "\nEnter the points x2 and y2:";
    cin >> x2 >> y2;
    cout << "\nEnter the points x3 and y3:";
    cin >> x3 >> y3;
    cout << "\nEnter the angle of rotation:";
    cin >> an;
    
    line (x1,y1,x2,y2);
    line (x2,y2,x3,y3);
    line (x3,y3,x1,y1);
    delay(1000);
    
    c=cos(an*3.14/180);
    s=sin(an*3.14/180);
    
    x1 = floor (x1*c + y1*s);
    y1 = floor (-x1*s+ y1*c);
    x2 = floor (x2*c + y2*s);
    y2 = floor (-x2*s+ y2*c);
    x3 = floor (x3*c + y3*s);
    y3 = floor (-x3*s+ y3*c);
    
    line (x1,y1,x2,y2);
    line (x2,y2,x3,y3);
    line (x3,y3,x1,y1);
    
    getch();
    closegraph();
}
