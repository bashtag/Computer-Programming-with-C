#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number */
	int num1, den1 = 0;
	printf("Please give me numerator of first number: ");
	scanf("%d", &num1);
	while (den1 == 0)
	{	
	   	printf("Please give me denominator of first number: ");
		scanf("%d", &den1);
	}
	/* A fractional number */
    int num2, den2 = 0;
	printf("Please give me numerator of second number: ");
	scanf("%d", &num2);
	while (den2 == 0)
	{	
   		printf("Please give me denominator of second number: ");
		scanf("%d", &den2);
	}
	/* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
	if (num2 != 0)
		fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
    return(0);
}
