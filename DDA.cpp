#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int main() {
	int gdriver=DETECT, gmode;
	int x1, y1, x2, y2, i=0;
	float x, y, step, dx, dy, xinc, yinc;

	cout << "Enter X1 and Y1: ";
	cin >> x1 >> y1;

	cout << "Enter X2 and Y2: ";
	cin >> x2 >> y2;

	dx = float(x2) - x1;
	dy = float(y2) - y1;

	step = dx >= dy ? dx : dy;

	xinc = dx/step;
	yinc = dy/step;

	x=x1;
	y=y1;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	while(i <= step) {
		putpixel(abs(x), abs(y), 11);
		x += xinc;
		y += yinc;
		i++;
		delay(100);
	}

	delay(5000);
	closegraph();
}
