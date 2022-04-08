#include <stdio.h>

typedef enum {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
} Days;

typedef enum {
	harddisk,
	monitor,
	keyboard,
	mouse
} Products;

typedef enum {
	buy,
	orders,
	prices,
	exit
} Selections;

typedef enum {
	p_harddisk = 2,
	p_monitor = 5,
	p_keyboard = 3,
	p_mouse = 10
} Prices;

typedef enum {
	dolar = 4,
	euro = 5,
	pound = 9,
	peso = 10
} Currincies;

void print_days(int day)
{
	switch (day)
	{
		case 0:
			printf("Sunday");
			break;

		case 1:
			printf("Monday");
			break;

		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
		
		default:
			break;
	}
}

void print_products(Products product)
{
	switch (product)
	{
		case 0:
			printf("Harddisk");
			break;

		case 1:
			printf("Monitor");
			break;

		case 2:
			printf("Keyboard");
			break;
		case 3:
			printf("Mouse");
			break;
		
		default:
			break;
	}
}

void readOrderFile(void print_days())
{
	FILE *ptr;
	int bufnum;

	ptr = fopen("orders.txt", "r");

	while (!feof(ptr))
	{
		fscanf(ptr, "%d ", &bufnum);
		printf("Product ID: %d,Day: ", bufnum);
		fscanf(ptr, "%d ", &bufnum);
		print_days(bufnum);
		printf("\n");
	}

	fclose(ptr);
}

void readOrderFile_with_prdct(void print_days(), void print_products())
{
	FILE *ptr;
	int bufnum;

	ptr = fopen("orders.txt", "r");

	while (!feof(ptr))
	{
		fscanf(ptr, "%d ", &bufnum);
		printf("Product: ");
		print_products(bufnum);
		printf(",Day: ");
		fscanf(ptr, "%d ", &bufnum);
		print_days(bufnum);
		printf("\n");
	}

	fclose(ptr);
}

int add(int multiple())
{
	FILE *ptr;
	int buf, total = 0;

	ptr = fopen("orders.txt", "r");

	while (!feof(ptr))
	{
		fscanf(ptr, "%d ", &buf);
		total += multiple(buf);
		fscanf(ptr, "%d ", &buf);
	}
	
	fclose(ptr);

	return (total);
}

int multiple(Products product)
{
	switch (product)
	{
	case 0:
		return p_harddisk*dolar;
		break;

	case 1:
		return p_monitor*euro;
		break;

	case 2:
		return p_keyboard*pound;
		break;
	
	case 3:
		return p_mouse*peso;
		break;
	
	default:
		break;
	}
}

int	main(void)
{
	FILE *ptr;
	int	selection;
	Products product;
	Days day;

	do {
		printf("Welcome to the TechMarket.\n"
				" 1. Buy Product\n"
				" 2. Orders\n"
				" 3. All Orders Prices\n"
				" 4. EXIT\n"
				" -------------------------\n");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				printf("Select your product:\n"
						" 0. Harddisk\n"
						" 1. Monitor\n"
						" 2. Keyboard\n"
						" 3. Mouse\n"
						" 4. GO TO MAIN MENU\n"
						" ------------------------\n");
				scanf("%u", &product);

				if (product != 4)
				{
					printf("Select your arrival day[0-6]:\n"
							" Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n"
							"-------------------------------\n");
					scanf("%u", &day);
					
					ptr = fopen("orders.txt", "a");

					fprintf(ptr, "%u %u\n", product, day);

					fclose(ptr);
				}
				else continue;

				break;

			case 2:
				readOrderFile(print_days);
				break;

			case 3:
				readOrderFile_with_prdct(print_days, print_products);
				printf("Total prices: %d\n", add(multiple));
				break;

			default:
				break;
		}

	} while (selection != 4);
	
	return (0);
}