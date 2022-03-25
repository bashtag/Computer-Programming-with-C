#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"


int main() {
	int p_num = 1; // problem number

	// variables for first problem
	double pl = 0.0, pw = 0.0, sl = 0.0, sw = 0.0;

	// variables for second problem and third problem.
	double x1 = 0.0, x2 = 0.0, x3 = 0.0, p3_x4;

	// some variables are specific for third problem. Because that variables which same name are different data type
	int x4 = 0, x5 = 0, x6 = 0, p3_x1 = 0, p3_x2 = 0;
	
	// results of problems for comparison
	char r_dt1a, r_dt1b;
	double r_dt2a, r_dt2b;
	int r_dt3a, r_dt3b;

	while (p_num != 0)
	{
		/* Ask for the problem selection (1,2,3) .....  */
		printf("\nMenu (for exit press 0)\nGive me the problem number: ");
		scanf("%d", &p_num);

		if (p_num == 1)
		{
			printf("------------------------------------------------\n");
			/* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
			printf("Give me inputs for the first problem - a (dt1a)\n");
			printf("double pl: ");
			scanf("%lf", &pl);
			printf("double pw: ");
			scanf("%lf", &pw);
			printf("double sl: ");
			scanf("%lf", &sl);
			printf("double sw: ");
			scanf("%lf", &sw);
			r_dt1a = dt1a(pl, pw, sl, sw);

			printf("Give me inputs for the first problem - b (dt1a)\n");
			printf("double pl: ");
			scanf("%lf", &pl);
			printf("double pw: ");
			scanf("%lf", &pw);
			printf("double sl: ");
			scanf("%lf", &sl);
			printf("double sw: ");
			scanf("%lf", &sw);
			r_dt1b = dt1b(pl, pw, sl, sw);

			/* Compare performances and print results */
			if (r_dt1a - r_dt1b == 0)
			{
				printf("result of dt1a -> ");
				switch (r_dt1a)
				{
				case 'S':
					printf("Setosa\n");
					break;
				case 'V':
					printf("Versicolor\n");
					break;
				case 'R':
					printf("Virginica\n");
					break;
				default:
					break;
				}
			}
			else if (abs(r_dt1a - r_dt1b) <= CLOSE_ENOUGH)
				printf("%f\n", (float)(r_dt1a + r_dt1b) / 2.0);
			else
			{
				printf("result of dt1a -> ");
				switch (r_dt1a)
				{
				case 'S':
					printf("Setosa\n");
					break;
				case 'V':
					printf("Versicolor\n");
					break;
				case 'R':
					printf("Virginica\n");
					break;
				default:
					break;
				}
				printf("result of dt1b -> ");
				switch (r_dt1b)
				{
				case 'S':
					printf("Setosa\n");
					break;
				case 'V':
					printf("Versicolor\n");
					break;
				case 'R':
					printf("Virginica\n");
					break;
				default:
					break;
				}
			}
		}
		else if (p_num == 2)
		{
			printf("------------------------------------------------\n");
			/* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
			printf("Give me inputs for the second problem - a (dt2a)\n");
			printf("double x1: ");
			scanf("%lf", &x1);
			printf("double x2: ");
			scanf("%lf", &x2);
			printf("double x3: ");
			scanf("%lf", &x3);
			printf("binary (1 or 0) x4: ");
			scanf("%d", &x4);
			printf("binary (1 or 0) x5: ");
			scanf("%d", &x5);
			r_dt2a = dt2a(x1, x2, x3, x4, x5);

			printf("Give me inputs for the second problem - b (dt2b)\n");
			printf("double x1: ");
			scanf("%lf", &x1);
			printf("double x2: ");
			scanf("%lf", &x2);
			printf("double x3: ");
			scanf("%lf", &x3);
			printf("binary (1 or 0) x4: ");
			scanf("%d", &x4);
			printf("binary (1 or 0) x5: ");
			scanf("%d", &x5);
			r_dt2b = dt2b(x1, x2, x3, x4, x5);
			/* Compare performances and print results */

			if (r_dt2a - r_dt2b == 0.0)
				printf("result of dt_2 -> %lf\n", r_dt2a);
			else if (abs(r_dt2a - r_dt2b) <= CLOSE_ENOUGH)
				printf("result of dt_2 (close enough to each other) -> %lf\n", (r_dt2a + r_dt2b) / 2.0);
			else
			{
				printf("result of dt_2a -> %lf\n", r_dt2a);
				printf("result of dt_2b -> %lf\n", r_dt2b);
			}
		}
		else if (p_num == 3)
		{
			printf("------------------------------------------------\n");
			/* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
			printf("Give me inputs for the third problem - a (dt3a)\n");
			printf("int x1: ");
			scanf("%d", &p3_x1);
			printf("int x2: ");
			scanf("%d", &p3_x2);
			printf("double x3: ");
			scanf("%lf", &x3);
			printf("double x4: ");
			scanf("%lf", &p3_x4);
			printf("binary (1 or 0) x5: ");
			scanf("%d", &x5);
			printf("binary (1 or 0) x6: ");
			scanf("%d", &x6);
			r_dt3a = dt3a(p3_x1, p3_x2, x3, p3_x4, x5, x6);
			
			printf("Give me inputs for the third problem - b (dt3b)\n");
			printf("int x1: ");
			scanf("%d", &p3_x1);
			printf("int x2: ");
			scanf("%d", &p3_x2);
			printf("double x3: ");
			scanf("%lf", &x3);
			printf("double x4: ");
			scanf("%lf", &p3_x4);
			printf("binary (1 or 0) x5: ");
			scanf("%d", &x5);
			printf("binary (1 or 0) x6: ");
			scanf("%d", &x6);
			r_dt3b = dt3b(p3_x1, p3_x2, x3, p3_x4, x5, x6);
			
			/* Compare performances and print results */
			if (r_dt3a - r_dt3b == 0)
				printf("result of dt_3 -> %d", r_dt3a);
			else if (abs(r_dt3a - r_dt3b) <= CLOSE_ENOUGH)
				printf("result of dt_3 (close enough to each other) -> %lf\n", (double)(r_dt3a + r_dt3b) / 2.0);
			else
			{
				printf("result of dt_3a -> %d\n", r_dt3a);
				printf("result of dt_3b -> %d\n", r_dt3b);
			}
		}
	}
	return 0;
}