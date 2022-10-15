#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int A1, B1, A2, B2;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int A1, int A2, int B1, int B2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	dx = A2-A1;
	dy = B2-B1;
	if (dx < 0) 
		dx = -dx;
	if (dy < 0) 
		dy = -dy;
	incx = 1;
	if (A2 < A1) 
		incx = -1;
	incy = 1;
	if (B2 < B1) 
		incy = -1;
	x = A1; 
	y = B1;
	if (dx > dy)
	{
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++)
		{
			if (e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
				e += inc2;	
			x += incx;
			draw_pixel(x, y);
		}
	}
	else
	{
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		for (i=0; i<dy; i++)
		{
			if (e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;	
			draw_pixel(x, y);
		}			
	}
}

void myDisplay()
{
	draw_line(A1, A2, B1, B2);
	glFlush();
}

int main(int argc, char **argv)
{
	printf( "Enter First Pixel(A1, B1) Co-Ordinate Values\n");
	scanf("%d %d", &A1, &B1);
	printf( "Enter Second Pixel(A2, B2) Co-Ordinate Values\n");
	scanf("%d %d", &A2, &B2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
