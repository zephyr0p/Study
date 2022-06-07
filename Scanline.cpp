#include <iostream.h>
#include <dos.h>
#include <graphics.h>

void drawPolygon(int *x, int *y, int number_of_edges) {
	int i=0, j=0, k=0, lines_on_screen=480;
	int *x_int = new int[number_of_edges];
	float *slope = new float[number_of_edges];

	x[number_of_edges] = x[0];
	y[number_of_edges] = y[0];

	for(i=0; i<number_of_edges; i++) {
		line(x[i], y[i], x[i+1], y[i+1]);
	}

	// find slope
	for(i=0; i<number_of_edges; i++) {
		int dx = x[i+1] - x[i];
		int dy = y[i+1] - y[i];

		if(dy == 0) {
			slope[i] = 1;
		} else if(dx == 0) {
			slope[i] = 0;
		} else {
			slope[i] = (float(dx)) / dy;
		}
	}

	// find intersection points and plot it
	for(int p=0; p<lines_on_screen; p++) {
		k=0;
		for(i=0; i<number_of_edges; i++) {
			if((y[i] <= p && y[i+1] > p) || (y[i] > p && y[i+1] <= p)) {
				x_int[k] = x[i] + slope[i] * (p - y[i]);
				k++;
			}
		}

		for(j=0; j<k-1; j++) {
			if(x[j]  > x[j+1]) {
				int temp = x[j+1];
				x[j+1] = x[j];
				x[j] = temp;
			}
		}

		for(i=0; i<k-1; i+=2) {
			line(x_int[i], p, x_int[i+1], p);
			delay(20);
		}
	}
}

int main() {
	int number_of_edges, gdriver=DETECT, gmode;

	cout << "Enter number of edges: ";
	cin >> number_of_edges;

	int *x = new int[number_of_edges], *y = new int[number_of_edges];

	for(int i=0;i<number_of_edges;i++) {
		cout << "Enter X and Y co-ordinates: ";
		cin >> x[i] >> y[i];
	}

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	drawPolygon(x, y, number_of_edges);
	delay(20000);
	closegraph();

	return 0;
}
