#include <stdio.h>
#include <string.h>

// recursive palindrome string check
void	reverse(char str[], char reversed[], int i)
{
	// len for the palindrome
	int	len = strlen(str);

	if (i != 0)
		reverse(str, reversed, i - 1);
	reversed[i] = str[len - 1 - i];
}


// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
	arr[k] = M[j];
	j++;
	k++;
	}
}

// recursive merge sort function
void	mergeSort(int arr[], int l, int r)
{
	int	middle;

	if (l < r)
	{
		middle = (l + r)/2;
		mergeSort(arr, l, middle);
		mergeSort(arr, middle+1, r);
		merge(arr, l, middle, r);
	}
}

int	main(void)
{
	char	str[50] = "bilal gokce";
	char	reversed[50];
	int i = 23, compare;

	reverse(str, reversed, i);

	compare = strcmp(str, reversed);

	if (compare)
		printf("String is not a palindrome.\n");
	else
		printf("String is a palindrome.\n");


	// merge sort part

	int	arr[6] = {6, 5, 12, 10, 9, 1};
	int l = 0, r = 5;

	mergeSort(arr, l, r);

	// print an array
	for (int i = 0; i < 6; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	return (0);
}