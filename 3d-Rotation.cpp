#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    int x1 = 100, y1 = 250;
    int x2 = 150, y2 = 250;
    int x3 = 150, y3 = 300;
    int x4 = 100, y4 = 300;
    int x5 = 125, y5 = 225;
    int x6 = 175, y6 = 225;
    int x7 = 175, y7 = 275;
    int x8 = 125, y8 = 275;
    int an, xn1, yn1, xn2, yn2, xn3, yn3, xn4, yn4, xn5, yn5, xn6, yn6, xn7, yn7, xn8, yn8;
    double c,s;
    
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
    cout << "\nEnter Angle of Rotation:";
    cin >> an;
    line (x1,y1,x2,y2);
    line (x2,y2,x3,y3);
    line (x3,y3,x4,y4);
    line (x4,y4,x1,y1);
    line (x5,y5,x6,y6);
    line (x6,y6,x7,y7);
    line (x7,y7,x8,y8);
    line (x8,y8,x5,y5);
    line (x1,y1,x5,y5);
    line (x2,y2,x6,y6);
    line (x3,y3,x7,y7);
    line (x4,y4,x8,y8);
    delay (1000);
    
    c=cos(an*3.14/180);
    s=sin(an*3.14/180);
    
    xn1 = x1*c + y1*s;
    yn1 =-x1*s + y1*c;
    xn2 = x2*c + y2*s;
    yn2 =-x2*s + y2*c;
    xn3 = x3*c + y3*s;
    yn3 =-x3*s + y3*c;
    xn4 = x4*c + y4*s;
    yn4 =-x4*s + y4*c;
    xn5 = x5*c + y5*s;
    yn5 =-x5*s + y5*c;
    xn6 = x6*c + y6*s;
    yn6 =-x6*s + y6*c;
    xn7 = x7*c + y7*s;
    yn7 =-x7*s + y7*c;
    xn8 = x8*c + y8*s;
    yn8 =-x8*s + y8*c;
    
    line (xn1,yn1,xn2,yn2);
    line (xn2,yn2,xn3,yn3);
    line (xn3,yn3,xn4,yn4);
    line (xn4,yn4,xn1,yn1);
    line (xn5,yn5,xn6,yn6);
    line (xn6,yn6,xn7,yn7);
    line (xn7,yn7,xn8,yn8);
    line (xn8,yn8,xn5,yn5);
    line (xn1,yn1,xn5,yn5);
    line (xn2,yn2,xn6,yn6);
    line (xn3,yn3,xn7,yn7);
    line (xn4,yn4,xn8,yn8);
    
    getch();
    closegraph();
}
