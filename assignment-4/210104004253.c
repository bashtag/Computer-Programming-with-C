#include <stdio.h>

#define DEFAULT_COLOR "\033[0m"
#define BLUE_COLOR "\033[0;34m"
#define YELLOW_COLOR "\033[0;33m"

void part1()
{
	int a, b, c;
	printf("\nPlease enter the coefficient for the following equation x=a*(y*y) + b*y + c\n"
			"\na: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("c: ");
	scanf("%d", &c);

	FILE *coefficients;

	coefficients = fopen("coefficients.txt", "w");

	fprintf(coefficients, "%d\n", a);
	fprintf(coefficients, "%d\n", b);
	fprintf(coefficients, "%d\n", c);

	fclose(coefficients);

	printf("\ncoefficients.txt file has been created.\n");
}

//  this function handles where # should be placed
int	is_point_valid(int i, int j, int a, int b, int c)
{
	int y = 16 - i; // y-axis
	int x = j - 56; // x-axis

	// if points are not within the bounds, return false
	if (x == 56 || x == -56 && y == 16) return (0);
	
	// if points provide the quadratic equation, return true.
	if (x == a*y*y + b*y + c) return (1);
	
	return (0);
}

void part2()
{
	FILE *coefficients;
	int a, b, c;

	coefficients = fopen("coefficients.txt", "r");

	if (coefficients == NULL)
	{
		printf("The coefficients.txt file doesn't exist.\n"
				"Please make sure this file exist.\n");
		return;
	}

	fscanf(coefficients, "%d", &a);
	fscanf(coefficients, "%d", &b);
	fscanf(coefficients, "%d", &c);

	fclose(coefficients);

	printf("\nCoefficients has been read from the coefficient.txt file."
			"\nPrinting the graph of x = %d*(y*y) + %d*y + %d\n", a, b, c);
	
	for (int i = 0; i < 32; i++)	// 32 is the number of rows.
	{								// 1(for ^) + 15 + 1(for zero) + 15
		printf("\n");
		for (int j = 0; j < 113; j++)	// 113 is the number of columns
		{								// 1(for <) + 55 + 1(for zero) + 55 + 1(for >)
			int hashtag = is_point_valid(i, j, a, b, c);

			//  for hashtag
			if (hashtag) printf("%s#%s", BLUE_COLOR, DEFAULT_COLOR); // color blue

			else if (j == 56) // for y-axis of the graph
			{
				if (i != 0) printf("|");
				else printf("^");
			}

			else if (i == 16) // for x-axis of the graph
			{
				if (j == 0) printf("<");
				else if (j == 112) printf(">");
				else printf("-");
			}

			// for zeros on the graph
			else if ((i == 6 && j == 54) || // for 10 on the y-axis
					(i == 17 && j == 55) || // for 0 on the y-axis
					(i == 26 && j == 54) || // for -10 on the y-axis
					(i == 17 && j == 5) || // for -50 on the x-axis
					(i == 17 && j == 15) || // for -40 on the x-axis
					(i == 17 && j == 25) || // for -30 on the x-axis
					(i == 17 && j == 35) || // for -20 on the x-axis
					(i == 17 && j == 45) || // for -10 on the x-axis
					(i == 17 && j == 65) || // for 10 on the x-axis
					(i == 17 && j == 75) || // for 20 on the x-axis
					(i == 17 && j == 85) || // for 30 on the x-axis
					(i == 17 && j == 95) || // for 40 on the x-axis
					(i == 17 && j == 105)) // for 50 on the x-axis
				printf("%s0%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for ones on the graph
			else if ((i == 1 && j == 53) || // for 15 on the y-axis
					(i == 6 && j == 53) || // for 10 on the y-axis
					(i == 26 && j == 53) || // for -10 on the y-axis
					(i == 31 && j == 53) || // for -15 on the y-axis
					(i == 17 && j == 44) || // for -10 on the x-axis
					(i == 17 && j == 64)) // for 10 on the x-axis
				printf("%s1%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for fives on the graph
			else if ((i == 1 && j == 54) || // for 15 on the y-axis
					(i == 11 && j == 54) || // for 5 on the y-axis
					(i == 21 && j == 54) || // for -5 on the y-axis
					(i == 31 && j == 54) || // for -15 on the y-axis
					(i == 17 && j == 4) || // for -50 on the x-axis
					(i == 17 && j == 104)) // for 50 on the y-axis
				printf("%s5%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for fours on the graph
			else if ((i == 17 && j == 14) || // for -40 on the x-axis
					(i == 17 && j == 94)) // for 40 on the x-axis
				printf("%s4%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for threes on the graph
			else if ((i == 17 && j == 24) || // for -30 on the x-axis
					(i == 17 && j == 84)) // for 30 on the x-axis
				printf("%s3%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for twos on the graph
			else if ((i == 17 && j == 34) || // for -20 on the x-axis
					(i == 17 && j == 74)) // for 20 on the x-axis
				printf("%s2%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			// for minuses on the graph
			else if ((i == 21 && j == 53) || // for -5 on the y-axis
					(i == 26 && j == 52) || // for -10 on the y-axis
					(i == 31 && j == 52) || // for -15 on the y-axis
					(i == 17 && j == 3) || // for -50 on the x-axis
					(i == 17 && j == 13) || // for -40 on the x-axis
					(i == 17 && j == 23) || // for -30 on the x-axis
					(i == 17 && j == 33) || // for -20 on the x-axis
					(i == 17 && j == 43)) // for -10 on the x-axis
				printf("%s-%s", YELLOW_COLOR, DEFAULT_COLOR); // yellow color

			else printf(" ");
		}

	}

	printf("\n");
}

void part3()
{
	FILE *coefficients;
	int a, b, c;

	coefficients = fopen("coefficients.txt", "r");

	if (coefficients == NULL)
	{
		printf("The coefficients.txt file doesn't exist.\n"
				"Please make sure this file exist.\n");
		return;
	}

	fscanf(coefficients, "%d", &a);
	fscanf(coefficients, "%d", &b);
	fscanf(coefficients, "%d", &c);

	fclose(coefficients);

	printf("\nCoefficients has been read from the coefficient.txt file.\n");

	FILE *graph;

	graph = fopen("graph.txt", "w");

	// writing to graph
	for (int i = 0; i < 32; i++)	// 32 is the number of rows.
	{								// 1(for ^) + 15 + 1(for zero) + 15
		fprintf(graph, "\n");
		for (int j = 0; j < 113; j++)	// 113 is the number of columns
		{								// 1(for <) + 55 + 1(for zero) + 55 + 1(for >)
			int hashtag = is_point_valid(i, j, a, b, c);

			//  for hashtag
			if (hashtag) fprintf(graph, "#");

			else if (j == 56) // for y-axis of the graph
			{
				if (i != 0) fprintf(graph, "|");
				else fprintf(graph, "^");
			}

			else if (i == 16) // for x-axis of the graph
			{
				if (j == 0) fprintf(graph, "<");
				else if (j == 112) fprintf(graph, ">");
				else fprintf(graph, "-");
			}

			else fprintf(graph, " ");
		}
	}
	fclose(graph);

	printf("The graph of x = %d*(y*y) + %d*y + %d has been written to graph.txt file.\n", a, b, c);
}

int	main(void)
{
	int	selection;
	do {
		printf("\nSelect an operation...\n"
				"1 -> Enter the coefficients.\n"
				"2 -> Draw the graph.\n"
				"3 -> Print the graph inhto a .txt file.\n"
				"4 -> Exit.\n"
				"\nChoice: ");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				part1();
				break;

			case 2:
				part2();
				break;

			case 3:
				part3();
				break;

			default:
				break;
		}

	} while (selection != 4);
	return (0);
}