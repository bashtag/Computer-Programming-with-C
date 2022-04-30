#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT 200

/*
 * Function: alphabeticSort
 * --------------------------
 * It does: sorts strings alphabetical
 * 
 * n: size of string array
 * 
 * MAX_LEN: max lenght of strings in the given string array
 * 
 * arr: string array that we'll sort alphabetically
 * 
 * returns: void
 *
*/
void	alphabeticSort(char arr[][MAX_LENGHT], int n)
{
	int i, j;
	char	temp[100];
	
	// bubble sort loop
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			// if arr[i] > arr[j], I swap these strings
			if (strcmp(arr[i], arr[j]) > 0)
			{
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], temp);
			}
		}
	}
}


/*
 * Function: generateTagParser
 * --------------------------
 * It does: generates the tags on the words
 * 
 *  tags: << >>, * *, /+ +/
 * 
 * 	temp: temporary array to copying operators
 * 
 * 	arr: string taken from user and my return argument
 * 	
 * 	returns: void
 *
*/
void	generateTabParser(char temp[], char arr[])
{
	// len of taken array
	int arr_len = strlen(arr);

	if (arr_len < 5)
	{
		strcpy(temp, arr);
		strcpy(arr, "<<");

		strcat(arr, temp);
		strcat(arr, ">>");
	}
	
	else if (arr_len >= 5 && arr_len <= 10)
	{
		strcpy(temp, arr);
		strcpy(arr, "*");

		strcat(arr, temp);
		strcat(arr, "*");
	}
	
	else if (arr_len > 10)
	{
		strcpy(temp, arr);
		strcpy(arr, "/+");

		strcat(arr, temp);
		strcat(arr, "+/");
	}
}

int	main(void)
{
	int	n;
	char	arr[100][MAX_LENGHT], string[100], temp[100];

	/* alphabetical sort part */
	printf("enter the count of how many strings you will enter...\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("given - > %s\n", arr[i]);
	}

	alphabeticSort(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("sorted - > %s\n", arr[i]);
	}

	/* alphabetical sort part is finished */


	/* tab parser part */

	printf("Enter a string: ");
	scanf("%s", string);

	generateTabParser(temp, string);

	printf("%s\n", string);

	/* tab parser part is finished */

	return (0);
}