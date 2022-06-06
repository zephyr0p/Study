#include <iostream.h>
#include <graphics.h>
#include <dos.h>

void bcircle(int x, int y, int cx, int cy)
{
	putpixel(x + cx, y + cy, 11);
	putpixel(y + cx, x + cy, 11);
	putpixel(-y+ cx, x + cy, 11);
	putpixel(x + cx,-y + cy, 11);
	putpixel(-x+ cx,-y + cy, 11);
	putpixel(-y+ cx,-x + cy, 11);
	putpixel(y + cx,-x + cy, 11);
	putpixel(-x+ cx, y + cy, 11);
}

void calculate_points(int cx, int cy, int radius) 
{
	int x, y;
	int decision_parameter, plot_x, plot_y;

	x = 0;
	y = radius;

	decision_parameter = 3 - (2*radius);

	bcircle(x, y, cx, cy);
	while(x < y) 
	{
		x++;
		if(decision_parameter >= 0) 
		{
			decision_parameter = decision_parameter + (4*(x-y)) + 10;
			y--;
		} 
		else 
		{
			decision_parameter = decision_parameter + (4*x) + 6;
		}
		
		bcircle(x, y, cx, cy);

		delay(10);
	}
}

int main() 
{
	int gdriver=DETECT, gmode;
	int x, y, radius;

	cout << "Enter the initial point X, Y: ";
	cin >> x >> y;

	cout << "Enter Raduis: ";
	cin >> radius;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	calculate_points(x, y, radius);
	delay(99999);
	closegraph();

	return 0;
}
