#include <stdio.h>
#include <math.h>

int gcd_calculator(int num1, int num2)
{
	int ebob;

	if (num1 <= num2) ebob = num1;
	else ebob = num2;

	for (;;ebob--)
	{
		if (num2 % ebob == 0 && num1 % ebob == 0) return (ebob);
	}
	return (ebob);
}

int lcm_calculator(int num1, int num2)
{
	return (num1 * num2) / gcd_calculator(num1, num2);
}

int calculate_mean()
{
	FILE *ptr;
	ptr = fopen("results.txt", "r");
	int index = 0, num = 0, total = 0;

	while(!feof(ptr))
	{
		index++;
		fscanf(ptr, "%d", &num);
		total += num;
	}
	fclose(ptr);
	return (total / index);
}

double standart_deviation_calculator()
{
	FILE *ptr;
	ptr = fopen("results.txt", "r");
	int index = 0, num = 0, sigma = 0;
	int mean = calculate_mean();
	double result;
	double inside;

	while(!feof(ptr))
	{
		index++;
		fscanf(ptr, "%d", &num);
		sigma += (num - mean) * (num - mean);
	}
	fclose(ptr);

	inside = (1.0 / (double)index) * (double)sigma;
	result = sqrt(inside);
	return (result);
}

void write_file(int result)
{
	FILE *ptr;
	ptr = fopen("results.txt", "a");

	fprintf(ptr, " %d", result);

	fclose(ptr);
}

int main(void)
{
	int selection, num1, num2, result;

	while (selection)
	{
		printf("Enter the calculator type\n");
		printf(" 1. GCD Calculator\n");
		printf(" 2. LCM Calculator via GCD\n");
		printf(" 3. Standart Deviation Calcultor\n");
		printf("---------------------------\n");
		scanf("%d", &selection);

		if (selection == 1)
		{
			printf("Please enter two different number:\n");
			printf("Number 1: ");
			scanf("%d", &num1);
			printf("Number 2: ");
			scanf("%d", &num2);
			result = gcd_calculator(num1, num2);
			printf("GCD of these two numbers: %d\n", result);

			write_file(result);

			printf("The result is written to the results.txt file\n");
		}
		else if (selection == 2)
		{
			printf("Please enter two different number:\n");
			printf("Number 1: ");
			scanf("%d", &num1);
			printf("Number 2: ");
			scanf("%d", &num2);
			result = lcm_calculator(num1, num2);
			printf("LCM of these two numbers: %d\n", result);

			write_file(result);
			
			printf("The result is written to the results.txt file\n");
		}
		else if (selection == 3)
		{
			FILE *ptr;
			ptr = fopen("results.txt", "r");
			int index = 0, num = 0;

			while(!feof(ptr))
			{
				index++;
				fscanf(ptr, "%d", &num);
				printf(" %d . Number: %d\n", index, num);
			}
			fclose(ptr);

			printf("Mean: %d\n", calculate_mean());
			printf("Total Count: %d\n", index);
			printf("Standart Deviation %.2lf\n", standart_deviation_calculator());
		}
	}
	return (0);
}