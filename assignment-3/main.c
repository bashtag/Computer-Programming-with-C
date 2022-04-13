#include <stdio.h>
#include <math.h>


int sum(int n1, int n2, int flag)
{
	int total = 0;

	switch (flag)
	{
		case 0: // for even numbers
			for (int i = n1 + 1; i < n2; i++)
			{
				// i % 2 is equal to i & 1
				// but i & 1 is faster because & is a bitwise operator
				if (!(i & 1)) total += i;
			}
			break;
		
		case 1: // for odd numbers
			for (int i = n1 + 1; i < n2; i++)
			{
				if (i & 1) total += i;
			}
			break;
			
		default:
			break;
	}

	return (total);
}

int multi(int n1, int n2, int flag)
{
	int product = 1;

	switch (flag)
	{
		case 0: // for even numbers
			for (int i = n1 + 1; i < n2; i++)
			{
				if (!(i & 1)) product *= i;
			}
			break;
		
		case 1: // for odd numbers
			for (int i = n1 + 1; i < n2; i++)
			{
				if (i & 1) product *= i;
			}
			break;
			
		default:
			break;
	}

	return (product);
}

int isprime(int a)
{
	int is_prime = 1;

	for (int i = (int)sqrt(a); i > 1; i--)
	{
		if (a % i == 0) is_prime = 0; 
	}
	
	return (is_prime);
}

void write_file(int number)
{
	FILE *ptr;

	ptr = fopen("results.txt", "a");

	fprintf(ptr, "%d ", number);

	fclose(ptr);
}

void print_file()
{
	FILE *ptr;
	int num;

	ptr = fopen("results.txt", "r");

	for (int i = 0; !feof(ptr); i++)
	{
		fscanf(ptr, "%d ", &num);
		printf("%d ", num);
	}
	printf("\n");

	fclose(ptr);
}

// finds minimum value of txt file after the given number
// if there isn't any minimum value after given number, it will be return max value of integer.
int find_next_min(FILE *ptr, int min)
{
	int temp, next_min = __INT_MAX__; // max value of integer data type
	rewind(ptr);
	
	while (!feof(ptr))
	{
		fscanf(ptr, "%d ", &temp);
		if (next_min > temp && temp > min) next_min = temp;
	}

	return (next_min);
}

// finds how much duplicate numbers are there
int how_much_same_num(FILE *ptr, int num)
{
	int temp, counter = 0;
	rewind(ptr);
	
	while (!feof(ptr))
	{
		fscanf(ptr, "%d ", &temp);
		if (temp == num) counter++;
	}

	return (counter);
}

// write contents of temporary file to result.txt file.
// temporary file just contains integer values.
void write_rfile_from_tfile()
{
	FILE *tempFile, *results;
	int temp;

	tempFile = fopen("temp.txt", "r");
	results = fopen("results.txt", "w");

	while (!feof(tempFile))
	{
		fscanf(tempFile, "%d ", &temp);
		fprintf(results, "%d ", temp);
	}

	fclose(tempFile);
	fclose(results);
}

void sort_file()
{
	FILE *tempFile, *results;
	int min1, min2, min3 = 0;	// default value of min3 is 0. Because there are just pozitive values in results.txt
	int hm_buff = 0; // for duplicate integers

	results = fopen("results.txt", "r");
	tempFile = fopen("temp.txt", "w");

	while (!(min1 == __INT_MAX__ || min2 == __INT_MAX__ || min3 == __INT_MAX__))
	{
		if (hm_buff < 1)
		{
			min1 = find_next_min(results, min3);
			if (min1 != __INT_MAX__)
			{
				hm_buff = how_much_same_num(results, min1);
				fprintf(tempFile, "%d ", min1);
			}
			hm_buff--;
		}
		else
		{
			min1 = min3;
			fprintf(tempFile, "%d ", min1);
			hm_buff--;
		}

		if (hm_buff < 1)
		{
			min2 = find_next_min(results, min1);
			if (min2 != __INT_MAX__)
			{
				hm_buff = how_much_same_num(results, min2);
				fprintf(tempFile, "%d ", min2);
			}
			hm_buff--;
		}
		else
		{
			min2 = min1;
			fprintf(tempFile, "%d ", min2);
			hm_buff--;
		}

		if (hm_buff < 1)
		{
			min3 = find_next_min(results, min2);
			if (min3 != __INT_MAX__)
			{
				hm_buff = how_much_same_num(results, min3);
				fprintf(tempFile, "%d ", min3);
			}
			hm_buff--;
		}
		else
		{
			min3 = min2;
			fprintf(tempFile, "%d ", min3);
			hm_buff--;
		}
	}

	fclose(results);
	fclose(tempFile);

	write_rfile_from_tfile();
}

// this function will be check if there is any even/odd numbers in (n1, n2) range.
// this function will be return boolean
int is_there_even_odd(int n1, int n2, int even_odd)
{
	int flag = 0;
	for (int i = n1 + 1; i < n2; i++)
	{
		switch (even_odd)
		{
			case 0: // for even numbers
				if (!(i & 1)) flag = 1;
				break;
			
			case 1: // for odd numbers
				if (i & 1) flag = 1;
				break;
				
			default:
				break;
		}
	}

	return (flag);
}

void part1()
{
	int sum_multi, even_odd, n1, n2;
	
	printf("Select operation\n"
			"Please enter \'0\' for sum, \'1\' for multiplication.\n");
	scanf("%d", &sum_multi);

	printf("Please enter \'0\' to work on even numbers, \'1\' to work on odd numbers.\n");
	scanf("%d", &even_odd);

	printf("Please enter two different number:\n"
			"Number 1: ");
	scanf("%d", &n1);
	printf("Number 2: ");
	scanf("%d", &n2);

	printf("Result\n");

	// it must be a valid range. Like (1, 9).
	// (9, 1) is a invalid range.
	if ((n1 >= 0 && n2 >= 0) && (n2 > n1) && is_there_even_odd(n1, n2, even_odd))
	{
		switch (sum_multi)
		{
			case 0: // for sum
				switch (even_odd)
				{
					case 0: // for even numbers

						for (int i = n1 + 1; i < n2; i++)
						{
							if (!(i & 1))
							{
								printf(" %d ", i);
								
								if (i < n2 - 2) printf("+");
							}
						}

						printf("= %d\n", sum(n1, n2, even_odd));
						
						write_file(sum(n1, n2, even_odd));
						printf("The result is written to the results.txt file.\n");
						break;

					case 1: // for odd numbers

						for (int i = n1 + 1; i < n2; i++)
						{
							if (i & 1)
							{
								printf(" %d ", i);
								
								if (i < n2 - 2) printf("+");
							}
						}

						printf("= %d\n", sum(n1, n2, even_odd));
						
						write_file(sum(n1, n2, even_odd));
						printf("The result is written to the results.txt file.\n");
						break;

					default:
						printf("Invalid operation (odd/even).\n");
						break;
				}
				break;
			
			case 1: // for multiplication
				switch (even_odd)
				{
					case 0: // for even numbers

						for (int i = n1 + 1; i < n2; i++)
						{
							if (!(i & 1))
							{
								printf(" %d ", i);
								
								if (i < n2 - 2) printf("*");
							}
						}

						printf("= %d\n", multi(n1, n2, even_odd));

						write_file(multi(n1, n2, even_odd));
						printf("The result is written to the results.txt file.\n");
						break;

					case 1: // for odd numbers

						for (int i = n1 + 1; i < n2; i++)
						{
							if (i & 1)
							{
								printf(" %d ", i);
								
								if (i < n2 - 2) printf("*");
							}
						}

						printf("= %d\n", multi(n1, n2, even_odd));

						write_file(multi(n1, n2, even_odd));
						printf("The result is written to the results.txt file.\n");
						break;
						
					default:
						printf("Invalid operation (odd/even).\n");
						break;
				}
				break;

			default:
				printf("Invalid operation (sum/multiplication).\n");
				break;
		}
	}
	else printf("Invalid number or numbers.\n");
}

void part2()
{
	int num, div = 0;
	printf("Please enter an integer: ");
	scanf("%d", &num);

	if (num > 1)
	{
		for (int i = 2; i < num; i++)
		{
			switch (isprime(i))
			{
				case 0: // not prime
					
					for (int j = 2; j <= (int)sqrt(i); j++)
						if (i % j == 0) div = j;

					printf("%d is not a prime number, it is dividible by %d.\n", i, div);
					break;

				case 1: // prime
					printf("%d is a prime number.\n", i);
					break;
				
				
				default:
					break;
			}
		}
	}
	else printf("Invalid number.\n");
}

void part3()
{
	printf("Result :\n");
	print_file();
}

void part4()
{
	sort_file();
	printf("Sorting is complete.\n"
			"Result :\n");
	print_file();
}

int	main(void)
{
	int selection = 1;

	while (selection)
	{
		printf("Select operation (for exit press 0)\n"
				" 1. Calculate sum/multiplication between two numbers\n"
				" 2. Calculate prime numbers\n"
				" 3. Show number sequence in file\n"
				" 4. Sort number sequence in file\n"
				" -------------------------\n");
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

			case 4:
				part4();
				break;

			default:
				break;
		}
	}

	return (0);
}