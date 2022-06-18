#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMOFITEMS 2
#define FILENAME "Lab11_data.bin"

typedef struct {
	int	id;
	char	name[50];
	float	price;
} item_t;

typedef union {
	char	phone[100];
	char	email[100];
} contactInfo_t;

typedef struct {
	item_t	item;
	contactInfo_t	contactInfo;
	int	contactChoice;
} itemWithCont_t;

/**
 * @brief clear the input buffer
 * 
 */
void	flushInputBuffer()
{
	char	tmp;

	do
	{
		scanf("%c", &tmp);
	} while (tmp != '\n');
}

/**
 * @brief Getting items from the user
 * 
 * @param items 
 * @param size 
 * @return item_t* 
 */
item_t	*getItems(item_t *items, int size)
{
	char	name[50];
	float	price;

	for (int i = 0; i < size; i++)
	{
		printf("Give me a new item Name => ");
		scanf(" %[^\n]%*c", name);
		fflush(stdin);
		printf("Price => ");
		scanf("%f", &price);
		fflush(stdin);

		strcpy(items[i].name, name);
		items[i].price = price;
	}

	return (items);
}

/**
 * @brief printing an item and its properties
 * 
 * @param item 
 */
void	printItem(item_t item)
{
	printf("ID => %d\n"
			"Name => %s\n"
			"Price => %.2f\n", item.id, item.name, item.price);
}

/**
 * @brief Writing items into a binary file
 * 
 * @param filename 
 * @param items 
 * @param size 
 * @return int 
 */
int	writeItems(char	filename[], item_t *items, int size)
{
	FILE *dataFile = fopen(filename, "ab");

	for (int i = 0; i < size; i++)
	{
		fprintf(dataFile, "%d\n", items[i].id);
		fprintf(dataFile, "%s\n", items[i].name);
		fprintf(dataFile, "%f\n", items[i].price);
	}

	fclose(dataFile);
	return (1);
}

/**
 * @brief Reading an item from binary file
 * 
 * @param file 
 * @return item_t 
 */
item_t readAnItem(FILE *file)
{
	item_t anItem;

	fscanf(file, "%d", &anItem.id);
	fscanf(file, " %[^\n]%*c", anItem.name);
	fscanf(file, "%f", &anItem.price);

	return (anItem);
}

/**
 * @brief Adding contact information for the items by item name
 * 
 * @param items 
 * @param size 
 * @param contacts 
 */
void	contactInfoAdder(item_t *items, int size, itemWithCont_t contacts[])
{
	for (int i = 0; i < size; i++)
	{
		printf("\nWhat would you like to enter for %s? Phone number(0), email(1): ", contacts[i].item.name);
		scanf("%d", &contacts[i].contactChoice);

		if (contacts[i].contactChoice)
		{
			printf("Enter the phone for %s => ", contacts[i].item.name);
			scanf(" %[^\n]%*c", contacts[i].contactInfo.phone);
			fflush(stdin);
		}
		else
		{
			printf("Enter a email for %s => ", contacts[i].item.name);
			scanf(" %[^\n]%*c", contacts[i].contactInfo.phone);
			fflush(stdin);
		}
	}
}

/**
 * @brief Printing items with contact information
 * 
 * @param itemWithCont 
 */
void	printItemWithContactInfo(itemWithCont_t itemWithCont)
{
	printf("ID: %d\n"
			"Name: %s\n"
			"Price: %.2f\n", itemWithCont.item.id, itemWithCont.item.name, itemWithCont.item.price);

	if (itemWithCont.contactChoice)
		printf("Phone number: %s\n", itemWithCont.contactInfo.phone);
	else
		printf("Mail: %s\n", itemWithCont.contactInfo.email);
}

int	main(void)
{
	item_t	*items = (item_t *)calloc(NUMOFITEMS, sizeof(item_t));
	item_t	anItem;
	itemWithCont_t	contacts[NUMOFITEMS*2];
	FILE *binFile;
	int	i, j, id = 0;

	for (i = 0; i < 2; i++)
	{
		items = getItems(items, NUMOFITEMS);
		
		for (j = 0; j < NUMOFITEMS; j++)
		{
			items[j].id = id++;
			contacts[id - 1].item = items[j];
		}

		printf("Printing...\n");
		for (j = 0; j < NUMOFITEMS; j++)
			printItem(items[j]);

		if (writeItems(FILENAME, items, NUMOFITEMS))
			printf("Succesfully wrote data to file\n");
		
	}

	/* reading part */
	printf("\nReading from File:\n");
	binFile = fopen(FILENAME, "rb");
	for (int i = 0; i < id; i++)
	{
		anItem = readAnItem(binFile);
		printf("Id: %d\n"
				"Name: %s\n"
				"Price: %.2f\n", anItem.id, anItem.name, anItem.price);
	}
	fclose(binFile);
	/* reading part is end */

	/* contact info part */
	contactInfoAdder(items, NUMOFITEMS*2, contacts);

	printf("\n");
	for (i = 0; i < NUMOFITEMS*2; i++)
		printItemWithContactInfo(contacts[i]);
	/* contact info part is end */

	return (0);
}