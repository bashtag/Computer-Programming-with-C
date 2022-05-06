#include <stdio.h>
#include <string.h>

#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define THREE_MIN(a,b,c) MIN(MIN(a,b),c)

/**
 * @brief Find Maximum Distance between cities using recursive algorithm 
 * 
 * @param distanceOfCities 
 * @param start 
 * @param end 
 * @param result 
 */
void	findMaximumDistance(int distanceOfCities[], int start, int end, int result[])
{
	int mid = (start + end) / 2;
	int	arr1[2], arr2[2];

	if (start == end)
	{
		result[0] = distanceOfCities[start];
		result[1] = distanceOfCities[start];
		return;
	}
	else if (start + 1 == end)
	{
		if (distanceOfCities[start] < distanceOfCities[end])
		{
			result[0] = distanceOfCities[start];
			result[1] = distanceOfCities[end];
		}
		else
		{
			result[0] = distanceOfCities[end];
			result[1] = distanceOfCities[start];
		}
		return;
	}

	findMaximumDistance(distanceOfCities, start, mid, arr1);
	findMaximumDistance(distanceOfCities, mid + 1, end, arr2);

	/**
	 * @brief result[0] -> min value
	 * result[1] -> max value
	 * 
	 */
	if (arr1[0] < arr2[0])
		result[0] = arr1[0];
	else
		result[0] = arr2[0];

	if (arr1[1] > arr2[1])
		result[1] = arr1[1];
	else
		result[1] = arr2[1];
}

/**
 * @brief Minimum number of operations required to convert str1 into str2
 * Recursively algorithm
 * 
 * @param str1 
 * @param str2 
 * @param m 
 * @param n 
 * @return int 
 */
int	recursiveMinStrDiff(char str1[], char str2[], int m, int n)
{	
	/* base cases */
	if (m == 0)
		return (n);
	else if (n == 0)
		return (m);
	else if (str1[m-1] == str2[n-1])
		return recursiveMinStrDiff(str1, str2, m-1, n-1);

	return (THREE_MIN(recursiveMinStrDiff(str1, str2, m, n-1),
		recursiveMinStrDiff(str1, str2, m-1, n),
		recursiveMinStrDiff(str1, str2, m-1, n-1)) + 1);
}

int	main(void)
{
	int distanceOfCities[5] = {20, 56, 18, 45, 40};
	int	maxArr[2];

	findMaximumDistance(distanceOfCities, 0, 4, maxArr);

	printf("%d, %d\n", maxArr[0], maxArr[1]);

	char s1[7] = "sunday";
	char s2[9] = "saturday";
	int	len1 = strlen(s1);
	int	len2 = strlen(s2);

	printf("%d, %d\n", len1, len2);

	printf("minStrDiff -> %d \n", recursiveMinStrDiff(s1, s2, len1, len2));

	// printf("%d\n", THREE_MIN(9,6,7));

	return (0);
}