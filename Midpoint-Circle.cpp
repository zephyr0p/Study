#include<iostream.h>
#include <dos.h>
#include<graphics.h>
#include<math.h>

int main() {
  int gd = DETECT, gm;

  initgraph( & gd, & gm, "C:\\TC\\BGI");
  float x, y, x1 = 100, y1 = 200, p, r = 80;
  /*
  cout<<"\nEnter the centre of the circle:";
  cin>>x1>>y1;
  cout<<"Enter the radius of the circle:";
  cin>>r;
  */
  x = 0;
  y = r;
  p = 1 - r;
  while (x < y) {
    putpixel(x1 + x, y1 + y, WHITE);
    putpixel(x1 + x, y1 - y, WHITE);
    putpixel(x1 - x, y1 + y, WHITE);
    putpixel(x1 - x, y1 - y, WHITE);
    putpixel(x1 + y, y1 + x, WHITE);
    putpixel(x1 + y, y1 - x, WHITE);
    putpixel(x1 - y, y1 + x, WHITE);
    putpixel(x1 - y, y1 - x, WHITE);
    if (p < 0) {
      x = x + 1;
      y = y;
      p = p + 2 * x + 1;
    } else {
      x = x + 1;
      y = y - 1;
      p = p - 2 * y + 2 * x + 1;
    }
    delay(100);
  }
  delay(9999999);
  closegraph();
}
