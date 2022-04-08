#include <stdio.h>

void	create_1d_array(int arr[], int n)
{
	// fill the array using user inputs
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

void	display_1d_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	
	printf("\n");
}

// part 1 function
void	convolutional_filter()
{
	int	arr[10], result[8], i;

	printf("1D Array\n");
	create_1d_array(arr, 10);

	// for filter
	// there isn't any segmentation fault. Because i must less than 8
	for (i = 0; i < 8; i++)
		result[i] = arr[i]*(-1) + arr[i + 1] + arr[i + 2]*(-1);

	// printing result
	printf("\nConvolutional Filter Result:\n");
	display_1d_arr(result, 8);
	
	printf("\n");
}

void	create_matrix(int arr[][3], int n)
{
	int i, j;

	// inputs from user for matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
}

void	display_matrix(int arr[][3], int n)
{
	int i, j;

	// printing matrix
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

// part 2
void	matrix_multiplication()
{
	int	f_matrix[3][3], s_matrix[3][3], result[3][3], i, j;

	printf("First Matrix:\n");

	create_matrix(f_matrix, 3);
	
	printf("Second Matrix:\n");

	create_matrix(s_matrix, 3);

	// multiplication of two matrix
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				// row of the first matrix and column of the second matrix
				result[i][j] += f_matrix[i][k] * s_matrix[k][j]; 
			}
		}
	}

	printf("Multiplication of matrix:\n");

	display_matrix(result, 3);
}

// part 3
void	trace_matrix()
{
	int	f_matrix[3][3], s_matrix[3][3], trace = 0, i, j;

	printf("Trace of the First Matrix:\n");

	create_matrix(f_matrix , 3);

	for (i = 0; i < 3; i++)
		trace += f_matrix[i][i];
	printf("Trace of matrix is: %d\n", trace);
	
	printf("Trace of the Second Matrix:\n");

	create_matrix(s_matrix, 3);

	trace = 0;
	for (i = 0; i < 3; i++)
	{
		trace += s_matrix[i][i];
	}
	printf("Trace of matrix is: %d\n", trace);
}

// part 4
void	transpose()
{
	int	f_matrix[3][3], s_matrix[3][3], result[3][3], i, j, temp;

	printf("First Matrix:\n");

	create_matrix(f_matrix, 3);

	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 3; j++)
		{
			temp = f_matrix[i][j];
			f_matrix[i][j] = f_matrix[j][i];
			f_matrix[j][i] = temp;
		}
	}

	printf("Transpose of the first matrix:\n");
	
	display_matrix(f_matrix, 3);

	printf("Second Matrix:\n");

	create_matrix(s_matrix, 3);

	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 3; j++)
		{
			temp = s_matrix[i][j];
			s_matrix[i][j] = s_matrix[j][i];
			s_matrix[j][i] = temp;
		}
	}

	printf("Transpose of the second matrix:\n");
	
	display_matrix(s_matrix, 3);
}

int	main(void)
{
	int	selection;
	do {
		printf("\nChoose the matrix operation,\n"
				"----------------------------\n"
				"1. Convolutional Filter for 1D array\n"
				"2. Multiplication\n"
				"3. Trace\n"
				"4. Transpose\n"
				"5. Exit\n"
				"----------------------------\n"
				"Enter your choice: ");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				convolutional_filter();
				break;

			case 2:
				matrix_multiplication();
				break;

			case 3:
				trace_matrix();
				break;

			case 4:
				transpose();
				break;

			default:
				break;
		}

	} while (selection != 5); /* for exit press 5 */
	return (0);
}