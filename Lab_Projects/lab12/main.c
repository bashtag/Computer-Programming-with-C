#include <stdio.h>
#include <stdlib.h>

/**
 * @brief bool definition
 * 
 */
#define bool int
#define true 1
#define false 0


/**
 * @brief my dynamic array structer
 * 
 */
typedef struct {
	int	*array;
	int	currentSize;
} dynamic_array;

/**
 * @brief to increase the array size by 1
 * 
 * @param array 
 * @param currentSize 
 * @return int* 
 */
int	*resize_array(int *array, int currentSize)
{
	int	*resizeArr = (int *)calloc(currentSize + 1, sizeof(int));

	for (int i = 0; i < currentSize; i++)
		resizeArr[i] = array[i];

	free(array);
	return (resizeArr);
}

/**
 * @brief to write the values in that file into dynamic_array
 * 
 * @param filename 
 * @param arr 
 */
void	read_from_file(char *filename, dynamic_array *arr)
{
	FILE *file = fopen(filename, "r");
	arr->currentSize = 0;

	while (!feof(file))
	{
		arr->array = resize_array(arr->array, arr->currentSize);
		fscanf(file, "%d", &(arr->array)[(arr->currentSize)++]);
	}

	fclose(file);
}

/**
 * @brief to remove value given as a parameter from dynamic_array
 * and reduces size of dynamic_array by 1
 * 
 * @param arr 
 * @param number 
 */
void	removeData(dynamic_array *arr, int number)
{
	bool	isDeleted = false;

	int	*resizeArr = (int *)calloc((arr->currentSize) - 1, sizeof(int));
	for (int i = 0, j = 0; i < arr->currentSize; i++)
		if (isDeleted || arr->array[i] != number)
			resizeArr[j++] = arr->array[i];
		else
			isDeleted = true;

	free(arr->array);
	arr->array = resizeArr;
	(arr->currentSize)--;
}

/**
 * @brief to print dynamic_array
 * 
 * @param arr 
 */
void	print_array(dynamic_array arr)
{
	for (int i = 0; i < arr.currentSize; i++)
		printf("%d\n", arr.array[i]);
}

int	main(void)
{
	dynamic_array array;
	int	del_num;

	read_from_file("file.txt", &array);

	print_array(array);

	printf("give me a number you want to be deleted: ");
	scanf("%d", &del_num);

	removeData(&array, del_num);
	print_array(array);


	return (0);
}