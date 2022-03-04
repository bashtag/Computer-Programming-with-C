#include <stdio.h>
#define PI 3.14

void	mid_point(int x1, int y1, int x2, int y2)
{
	float x, y;
	x = (float)(x1 + x2) / 2;
	y = (float)(y1 + y2) / 2;
	printf("M(x,y) = (%.1f, %.1f)\n", x, y);
}

float	slope(int x1, int y1, int x2, int y2)
{
	return ((float)(y2 - y1) / (float)(x2 - x1));
}

float	square_of_radius(int x1, int y1, int x2, int y2)
{
	/* distance between two points formula */
	return (((float)(x2 - x1) * (float)(x2 - x1)) + (float)((y2 - y1) * (float)(y2 - y1)));
}


float	area_of_circle(int x1, int y1, int x2, int y2)
{
	/* R^2 = 4 * r^2 */
	return (PI * (square_of_radius(x1, y1, x2, y2) / 4));
}


int	main(void)
{
	/* A and B coordinates */
	int x1, x2, y1, y2;
	
	printf("x1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);
	
	printf("\nMidpoint: ");
	mid_point(x1, y1, x2, y2);
	printf("\nSlope: m = (%.1f)\n", slope(x1, y1, x2, y2));
	printf("\nArea: A = %.1f\n", area_of_circle(x1, y1, x2, y2));
	return (0);
}
