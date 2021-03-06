#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d/%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*d2 - n2*d1;
	*d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*n2;
	*d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	if (n2 == 0)  /* denominator of result cannot be zero */
	{
		printf("Division cannot be calculated");
		return ;
	}
	*n3 = n1*d2;
	*d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
	int	ebob;
	int	num;
	int	denum;
	int	flag;

	if (*n == 0) /* if result is equal to zero */
	{
		*d = 1;
		return ;
	}

	num = *n;
	denum = *d;
	flag = 0;
	if ((*n) * (*d) < 0) /* if sign of result is negative */
		flag = 1;
	if (num < 0)
		num *= -1;
	if (denum < 0)
		denum *= -1;
	if (num < denum)
		ebob = num;
	else
		ebob = denum;
	while (!(*n % ebob == 0 && *d % ebob == 0))
		ebob--;
	*n = num / ebob;
	*d = denum / ebob;
	if (flag)
		*n *= -1;
} /* end fraction_div */
