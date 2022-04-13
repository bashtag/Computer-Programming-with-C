#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

typedef enum {
	triangle = 1,
	quadrilateral,
	circle,
	pyramid,
	cylinder
} Shapes;

typedef enum {
	area = 1,
	perimeter,
	volume
} Calculators;

// to clear input buffer
void	flush()
{
	int	buffer;

	do {
		buffer = getchar();
	} while (buffer != EOF && buffer != '\n');
}

// shape selection function
int	select_shape()
{
	int	selection, buff;

	printf(	"\nSelect a shape to calculate:\n"
			"-------------------------------\n"
			"1. Triangle\n"
			"2. Quadrilateral\n"
			"3. Circle\n"
			"4. Pyramid\n"
			"5. Cylinder\n"
			"0. Exit\n"
			"-------------------------------\n"
			"Input: ");
	selection = getchar(); /* get a single character */

	/* check if input is only one digit */
	buff = getchar();
	if (buff != '\n')
	{
		flush();
		return (-1);
	}

	return (selection - '0');
}

// calculator selection function
int	select_calc()
{
	int	selection, buff;

	printf("\nSelect calculator:\n"
			"------------------------------\n"
			"1. Area\n"
			"2. Perimeter\n"
			"3. Volume\n"
			"0. Exit\n"
			"Input: ");
	selection = getchar(); /* get a single character */

	/* check if input is only one digit */
	buff = getchar();
	if (buff != '\n')
	{
		flush();
		return (-1);
	}
	
	return (selection - '0');
}

// get a valid floating number
// if input is not a valid number, than it'll be return (-1.0)
double	get_a_valid_f_number()
{
	int	buffer, flag = 0;
	double	db_num = -1.0;

	scanf("%lf", &db_num);

	// my own flush loop
	do {
		buffer = getchar();
		flag++; /* flag for the wrong inputs */
	} while (buffer != EOF && buffer != '\n');

	if (flag > 1 || db_num <= 0.0) return (-1.0);
	return (db_num);
}

// triangle calculations
int	calc_triangle(Calculators calculator)
{
	int flag = 1; /* for the infinite loop for the wrong inputs */
	double	a, b, c, p_meter, tri_area, s;
	
	do {
		switch (calculator)
		{
			case area:
				
				printf("Please enter three sides of Triangle :\n");		
				
				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					b = get_a_valid_f_number();
					if (b != -1.0)
					{
						c = get_a_valid_f_number();
						if (c != -1.0)
						{
							// check if it is a valid triangle
							if ((a + b) > c && (a + c) > b && (b + c) > a)
							{
								s = (a + b + c) / 2.0;
								// Heron formula
								tri_area = sqrt(s*(s - a)*(s - b)*(s - c));
								printf("\nArea of TRIANGLE : %.2lf\n", tri_area);
								flag = 0;
							}
							else
								printf("\nERROR! Please enter a valid triangle.\n");
						}
						else
							printf("\nERROR! Please enter a valid entry.\n");
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case perimeter:

				printf("Please enter three sides of Triangle :\n");
			
				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					b = get_a_valid_f_number();
					if (b != -1.0)
					{
						c = get_a_valid_f_number();
						if (c != -1.0)
						{
							// check if it is a valid triangle
							if ((a + b) > c && (a + c) > b && (b + c) > a)
							{
								p_meter = (a + b + c);
								printf("\nPerimeter of TRIANGLE : %.2lf\n", p_meter);
								flag = 0;
							}
							else
								printf("\nERROR! Please enter a valid triangle.\n");
						}
						else
							printf("\nERROR! Please enter a valid entry.\n");
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case volume:
				printf("\nERROR! You cannot calculate the volume of a triangle. Please try again.\n");
				flag = 0;
				break;

			default:
				break;
		}
	} while (flag);

	return (0);
}

// quadrilateral calculations
int	calc_quadrilateral(Calculators calculator)
{
	int	flag = 1; /* for the infinite loop for the wrong inputs */
	double	a, b, c, d, p_meter, quad_area, s;
	
	do {
		switch (calculator)
		{
			case area:

				printf("Please enter four sides of Quadrilateral :\n");			
			
				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					b = get_a_valid_f_number();
					if (b != -1.0)
					{
						c = get_a_valid_f_number();
						if (c != -1.0)
						{
							d = get_a_valid_f_number();
							if (d != -1.0)
							{
								s = (a + b + c + d) / 2.0;
								// Brahmagupta's formula
								quad_area = sqrt((s - a)*(s - b)*(s - c)*(s - d));
								printf("\nArea of QUADRILATERAL : %.2lf\n", quad_area);
								flag = 0;
							}
							else
								printf("\nERROR! Please enter a valid entry.\n");
						}
						else
							printf("\nERROR! Please enter a valid entry.\n");
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case perimeter:

				printf("Please enter four sides of Quadrilateral :\n");

				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					b = get_a_valid_f_number();
					if (b != -1.0)
					{
						c = get_a_valid_f_number();
						if (c != -1.0)
						{
							d = get_a_valid_f_number();
							if (d != -1.0)
							{
								p_meter = (a + b + c + d);
								printf("\nPerimeter of QUADRILATERAL : %.2lf\n", p_meter);
								flag = 0;
							}
							else
								printf("\nERROR! Please enter a valid entry.\n");
						}
						else
							printf("\nERROR! Please enter a valid entry.\n");
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case volume:
				printf("\nERROR! You cannot calculate the volume of a quadrilateral. Please try again.\n");
				flag = 0;
				break;

			default:
				break;
		}
	} while (flag);

	return (0);
}

// circle calculations
int	calc_circle(Calculators calculator)
{
	int flag = 1;
	double	r, p_meter, circle_area;
	
	do {
		switch (calculator)
		{
			case area:

				printf("\nPlease enter the radius of Circle :\n");	
			
				r = get_a_valid_f_number();
				if (r != -1.0)
				{
					circle_area = PI * (r * r);
					printf("\nArea of CIRCLE : %.2lf\n", circle_area);
					flag = 0;
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
			case perimeter:
				
				printf("\nPlease enter the radius of Circle :\n");

				r = get_a_valid_f_number();
				if (r != -1.0)
				{
					p_meter = 2.0 * PI * (r);
					printf("\nPerimeter of CIRCLE : %.2lf\n", p_meter);
					flag = 0;
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
				
			case volume:
				printf("\nERROR! You cannot calculate the volume of a circle. Please try again.\n");
				flag = 0;
				break;

			default:
				break;
		}
	} while (flag);
	
	return (0);
}

// pyramid calculations
int	calc_pyramid(Calculators calculator)
{
	int	flag = 1; /* for the infinite loop for the wrong inputs */
	double	a, l, h, p_meter, base_area, lateral_area, surface_area, vol;

	do {
		switch (calculator)
		{
			case area:
				
				printf("\nPlease enter the base side and slant height of a Pyramid :\n");
	
				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					l = get_a_valid_f_number();
					if (l != -1.0)
					{
						base_area = (a * a);
					
						printf("\nBase Surface Area of a PYRAMID : %.2lf\n", base_area);
						
						lateral_area = 2.0 * (a) * (l);
					
						printf("\nLateral Surface Area of a PYRAMID : %.2lf\n", lateral_area);

						surface_area = lateral_area + base_area;

						printf("\nSurface Area of a PYRAMID : %.2lf\n", surface_area);
						flag = 0;
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case perimeter:
				
				printf("\nPlease enter the base side and height of a Pyramid :\n");

				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					h = get_a_valid_f_number();
					if (h != -1.0)
					{
						p_meter = 4.0 * (a);

						printf("\nBase Surface Perimeter of a PYRAMID : %.2lf\n", p_meter);
						flag = 0;
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
				
			case volume:
				printf("\nPlease enter the base side and height of a Pyramid :\n");
	
				a = get_a_valid_f_number();
				if (a != -1.0)
				{
					h = get_a_valid_f_number();
					if (h != -1.0)
					{
						// Volume formula of a pyramid
						vol = (1.0/3.0) * (a) * (a) * (h);
						
						printf("\nVolume of a PYRAMID : %.2lf\n", vol);
						flag = 0;
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
			default:
				break;
		}
	} while (flag);

	return (0);
}

// cylinder calculations
int	calc_cylinder(Calculators calculator)
{
	int flag = 1; /* for the infinite loop for the wrong inputs */
	double	r, h, p_meter, base_area, lateral_area, surface_area, vol;

	do {
		switch (calculator)
		{
			case area:
				
				printf("\nPlease enter the radius and height of a Cylinder :\n");
	
				r = get_a_valid_f_number();
				if (r != -1.0)
				{
					h = get_a_valid_f_number();
					if (h != -1.0)
					{
						base_area = PI * (r * r);
					
						printf("\nBase Surface Area of a CYLINDER : %.2lf\n", base_area);
						
						lateral_area = 2.0 * (r) * (h) * PI;
					
						printf("\nLateral Surface Area of a CYLINDER : %.2lf\n", lateral_area);

						surface_area = 2.0 * (r) * PI * ((h) + (r));

						printf("\nSurface Area of a CYLINDER : %.2lf\n", surface_area);
						flag = 0;
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;

			case perimeter:
				
				printf("\nPlease enter the radius and height of a Cylinder :\n");

				r = get_a_valid_f_number();
				if (r != -1.0)
				{
					h = get_a_valid_f_number();
					if (h != -1.0)
					{
						p_meter = 2.0 * PI * (r);

						printf("\nBase Surface Perimeter of a CYLINDER : %.2lf\n", p_meter);
						flag = 0;
					}
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
				
			case volume:
				printf("\nPlease enter the radius and height of a Cylinder :\n");
	
				r = get_a_valid_f_number();
				if (r != -1.0)
				{
					h = get_a_valid_f_number();
					if (h != -1.0)
					{
						// Volume formula of a Cylinder
						vol = PI * (r) * (r) * (h);
						
						printf("\nVolume of a CYLINDER : %.2lf\n", vol);
						flag = 0;
					}
					else
						printf("\nERROR! Please enter a valid entry.\n");
				}
				else
					printf("\nERROR! Please enter a valid entry.\n");
				break;
			default:
				break;
		}
	} while (flag);

	return (0);
}

// calculation function
int	calculate(int (*select_shape)(), int (*select_calc)())
{
	Shapes shape;
	Calculators calculator;
	
	do {
		shape = select_shape();

		if (shape > 0 && shape <= 5)
		{
			calculator = select_calc();
			if (calculator >= 0 && calculator <= 3)
			{
				switch (shape)
				{
					case triangle:
						calc_triangle(calculator);
						break;

					case quadrilateral:
						calc_quadrilateral(calculator);
						break;

					case circle:
						calc_circle(calculator);
						break;

					case pyramid:
						calc_pyramid(calculator);
						break;

					case cylinder:
						calc_cylinder(calculator);
						break;
					
					default:
						break;
				}
			}
			else
				printf("\nERROR! Please Enter a Valid Entry!\n");
		}
		else if (shape == 0);
		else
			printf("\nERROR! Please Enter a Valid Number!\n");
	} while (shape != 0);
}

int	main(void)
{
	printf("Welcome to the geometric calculator!\n");
	calculate(select_shape, select_calc);
	return (0);
}