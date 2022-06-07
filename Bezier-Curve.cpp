#include <iostream.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

double get_coordinate(float t, int c1, int c2, int c3, int c4) {
	return ((pow((1-t), 3) * c1) + (3*(pow((1-t), 2))*t*c2) + (3*(1-t)*pow(t, 2) * c3) +(pow(t, 3) * c4));
}

int main() {
	int gdriver=DETECT, gmode;
	int x1=180, x2=60, x3=320, x4=180;
	int y1=240, y2=40, y3=40, y4=240;
	int line_x=180, line_y=360;
	double put_x, put_y;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	setfillstyle(SOLID_FILL, 11);

	for(float t=0.0; t<1.00; t+=0.001) {
		put_x = get_coordinate(t, x1, x2, x3, x4);
		put_y = get_coordinate(t, y1, y2, y3, y4);
		putpixel(put_x, put_y, 11);
	}

	line(x1, y1, line_x, line_y);
	delay(999999);
	closegraph();

	return 0;
}
