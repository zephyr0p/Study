#include <iostream.h>
#include <graphics.h>
#include <dos.h>

void bline(int x0, int y0, int x1, int y1) 
{
    int x, y, dx, dy, decision_parameter;
    dx = x1 - x0;
    dy = y1 - y0;
    
    x=x0;
    y=y0;
    
    decision_parameter = (2*dy) - dx;
    while(x <= x1) {
        putpixel(x, y, 11);
        
        x++;
        if(decision_parameter >= 0) 
        {
            y++;
            decision_parameter = decision_parameter + (2*dy) - (2*dx);
        } 
        else 
        {
            decision_parameter = decision_parameter + (2*dy);
        }
        
        delay(50);
    }
}

int main() 
{
    int gd=DETECT, gm;
    int x0, y0, x1, y1;
    
    cout << "Enter X0 and Y0: ";
    cin >> x0 >> y0;
    
    cout << "Enter X1 and Y1: ";
    cin >> x1 >> y1;
    
    initgraph (&gd, &gm, "C:\\TC\\BGI");
    bline(x0, y0, x1, y1);
    
    delay(5000);
    closegraph();
}
