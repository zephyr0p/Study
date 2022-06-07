#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void main()
{
	int x1=200,y1=200,x2=180,y2=80,x3=245,y3=80,x4=225,y4=200,i;
	int x5=80,y5=180,x6=80,y6=245,x7=200,y7=225;
	int x8=180,y8=345,x9=245,y9=345,x10=225,y10=225,x11=345,y11=245,x12=345,y12=180;
	double put_x,put_y,t;
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setfillstyle(SOLID_FILL,YELLOW);
	circle(212.5,212.5,14);
	floodfill(212,212,WHITE);
	setfillstyle(SOLID_FILL,RED);
	for(t=0.0;t<1.0;t=t+0.001)
	{
		put_x=pow(1-t,3)*x1+3*t*pow(1-t,2)*x2+3*t*t*(1-t)*x3+pow(t,3)*x4;
		put_y=pow(1-t,3)*y1+3*t*pow(1-t,2)*y2+3*t*t*(1-t)*y3+pow(t,3)*y4;
		putpixel(put_x,put_y,WHITE);
		put_x=pow(1-t,3)*x1+3*t*pow(1-t,2)*x5+3*t*t*(1-t)*x6+pow(t,3)*x7;
		put_y=pow(1-t,3)*y1+3*t*pow(1-t,2)*y5+3*t*t*(1-t)*y6+pow(t,3)*y7;
		putpixel(put_x,put_y,WHITE);
		put_x=pow(1-t,3)*x7+3*t*pow(1-t,2)*x8+3*t*t*(1-t)*x9+pow(t,3)*x10;
		put_y=pow(1-t,3)*y7+3*t*pow(1-t,2)*y8+3*t*t*(1-t)*y9+pow(t,3)*y10;
		putpixel(put_x,put_y,WHITE);
		put_x=pow(1-t,3)*x10+3*t*pow(1-t,2)*x11+3*t*t*(1-t)*x12+pow(t,3)*x4;
		put_y=pow(1-t,3)*y10+3*t*pow(1-t,2)*y11+3*t*t*(1-t)*y12+pow(t,3)*y4;
		putpixel(put_x,put_y,WHITE);
	}
	floodfill(202,198,WHITE);
	getch();
	closegraph();
}
