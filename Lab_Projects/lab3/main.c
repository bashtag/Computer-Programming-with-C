#include <stdio.h>
#include <math.h>

void x_star_display(int height)
{
	for (int i = height/2; i > 0; i--)
	{
		for (int j = 0; j < (height)/2 - i; j++)
		{
			printf(" ");
		}
		printf("*");
		
		if (i > 0)
		{
			for (int j = 0; j < 2*i - 1; j+= 1) printf(" ");
			printf("*");
		}
		printf("\n");

		if (i == 1)
		{
			for (int j = 0; j <height/2; j++) printf(" ");
			printf("*");
		}
	}
	printf("\n");

	for (int i = 1; i < (height)/2 + 1; i++)
	{
		for (int j = 0; j < (height)/2 - i; j++)
		{
			printf(" ");
		}
		printf("*");
		
		if (i > 0)
		{
			for (int j = 0; j < 2*i - 1; j+= 1) printf(" ");
			printf("*");
		}
		printf("\n");
	}
}

void diamond_star_display(int height)
{
	for (int i = 0; i < (height)/2; i++)
	{
		for (int j = 0; j < (height)/2 - i; j++)
		{
			printf(" ");
		}
		printf("*");
		
		if (i > 0)
		{
			for (int j = 0; j < 2*i - 1; j+= 1) printf(" ");
			printf("*");
		}
		printf("\n");
	}

	for (int i = height/2; i > 0; i--)
	{
		for (int j = 0; j < (height)/2 - i; j++)
		{
			printf(" ");
		}
		printf("*");
		
		if (i > 0)
		{
			for (int j = 0; j < 2*i - 1; j+= 1) printf(" ");
			printf("*");
		}
		printf("\n");

		if (i == 1)
		{
			for (int j = 0; j <height/2; j++) printf(" ");
			printf("*");
		}
	}
	printf("\n");
}

void multiplication_table_display(int size)
{
	for (int i = 1; i <= size; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	printf("------------------------------------------------------------------\n");

	for (int i = 1; i <= size; i++)
	{
		printf("%d*",i);
		for (int j = 1; j <= size; j++)
		{
			printf("\t%d", i*j);
		}
		printf("\n");
	}
}

int basamak(int num)
{
	int result = 0;

	while (num)
	{
		result++;
		num /= 10;
	}

	return(result);
}

void is_palindrome_integer(int n)
{
	int temp = n, flag = 1, bas = (basamak(n) - 1);
	for (int i = 0; i <= n/2; i++)
	{
		int buf1, buf2;

		buf1 = n / (int)pow(10, (bas - 2*i));
		buf2 = n % 10;

		if (buf1 != buf2)
		{
			flag = 0;
			break;
		}

		n %= (int)pow(10, (basamak(n) - 1));
		n /= 10;
	}

	if (flag) printf("%d is a palindrome.\n", temp);
	else printf("%d is not a palindrome.\n", temp);
}

int	main(void)
{
	int	selection, num;

	do {
		printf("Enter option 1 to x_star_display\n"
				"Enter option 2 to diamond_star_display\n"
				"Enter option 3 to multiplication_table_display\n"
				"Enter option 4 to palindrome check number\n"
				"Enter option -1 to exit!\n");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			printf("Enter an odd integer as the height:");
			scanf("%d", &num);
			x_star_display(num);
			break;

		case 2:
			printf("Enter an odd integer as the height:");
			scanf("%d", &num);
			diamond_star_display(num);
			break;

		case 3:
			printf("Enter an integer as the size:");
			scanf("%d", &num);
			multiplication_table_display(num);
			break;

		case 4:
			printf("Enter an integer as the palindrome:");
			scanf("%d", &num);
			is_palindrome_integer(num);
			break;
		
		default:
			break;
		}

	} while (selection != -1);


	return (0);
}