#include <stdio.h>
#include <math.h>

#define PI 3.14

// coordinates struct
typedef struct
{
	int	x;
	int	y;
} Coordinates;

// circle struct
typedef struct
{
	Coordinates	points[2];
	float	radius;
	float	perimeter;
	float	area;
} Circle;


// calculation function
void	calculate_struct(Circle circle[], int num_of_circles)
{
	double pow1, pow2;

	for (int i = 0; i < num_of_circles; i++)
	{
		pow1 = pow((circle[i].points[1].x - circle[i].points[0].x), 2.0);
		pow2 = pow((circle[i].points[1].y - circle[i].points[0].y), 2.0);
		circle[i].radius = sqrt(pow1 + pow2);
		circle[i].perimeter = 2.0 * PI * circle[i].radius;
		circle[i].area = PI * circle[i].radius * circle[i].radius;
	}
}

/**
 * @brief Printing circles in an ascending order...
 * 
 * @param circles 
 * @param num_of_circles 
 * @param min_value 
 * @param j 
 */
void	print_struct(Circle circles[], int num_of_circles, float min_value, int j)
{
	int	i, k = 0;

	// max value
	for (i = 0; i < num_of_circles; i++)
	{
		if (circles[k].radius < circles[i].radius)
			k = i;
	}

	// min value
	for (i = 0; i < num_of_circles; i++)
	{
		// printf("radius-> %f\n", circles[i].radius);
		if (circles[i].radius > min_value && circles[k].radius > circles[i].radius)
			k = i;
	}

	printf("\nCircle %d\tRadius: %.2f\tPerimeter: %.2f\tArea:%.2f", k + 1, circles[k].radius, circles[k].perimeter, circles[k].area);

	min_value = circles[k].radius;
	if (j != 1)
		print_struct(circles, num_of_circles, min_value, j - 1);
}

/**
 * @brief recursive is_prime function
 * 
 * @param num 
 * @param div 
 * @return int 
 */
int	is_prime(int num, int div)
{
	if (num % div == 0)
	{	
		if (div == 1)
			return 1;
		else
			return 0;
	}
	is_prime(num, div - 1);
}

// 
void	factorization(int num, int div)
{
	if (num % div == 0)
		printf("%d*", div);
	if (div == num/div - 1)
		return;

	factorization(num / div, div + 1);
}

int	main(void)
{
	Circle circles[10];
	int	num_of_circles;
	int	center_x, center_y, P_x, P_y;
	int num;

	printf("PART1\n"
		"\nNumber of Cicles: ");
	scanf("%d", &num_of_circles);

	for (int i = 0; i < num_of_circles; i++)
	{
		printf("\nCicle %d...\n"
			"Coordinates of center: ", i + 1);
		scanf("%d %d", &center_x, &center_y);
		printf("Coordinates of point P: ");
		scanf("%d %d", &P_x, &P_y);
		circles[i].points[0].x = center_x;
		circles[i].points[0].y = center_y;
		circles[i].points[1].x = P_x;
		circles[i].points[1].y = P_y;
	}

	calculate_struct(circles, num_of_circles);

	printf("\n\nPrinting circles in an ascending order...\n");

	print_struct(circles, num_of_circles, 0.0, num_of_circles);

	printf("\n\nPART2\n\n");

	printf("Enter a number: ");
	scanf("%d", &num);

	if (is_prime(num, num-1))
		printf("%d is a prime number.\n", num);
	else
	{
		printf("%d is not a prime number.\n", num);
		// factorization(num, 2);
	}

	return (0);
}