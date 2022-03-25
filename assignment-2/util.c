#include <stdio.h>
#include <math.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
	int r = 0;
	if (t>35 && w!=3) r = 1;
	else if (t<=35 && s==0) r = 1;
	return r;
}

char dt1a(double pl, double pw, double sl, double sw)
{
	if (pl < 2.45) return 'S'; // Setosa
	else if (pw < 1.65 && pl < 4.95) return 'V'; //Versicolor
	return 'R'; // Virginica
}

char dt1b(double pl, double pw, double sl, double sw)
{
	if (pl < 2.55) return 'S'; // Setosa
	else if (pw < 1.69 &&  pl < 4.85) return 'V'; // Versicolor
	return 'R'; // Virginica
}


double dt2a(double x1, double x2, double x3, int x4, int x5)
{
	if (x1 < 31.5)
	{
		if (x2 > -2.5) return 5.0;
		else if (x2 - 0.1 <= x1 && x1 <= x2 + 0.1) return 2.1;
		return -1.1;
	}
	else if (-1.0 <= x3 && x3 <= 2.0) return 1.4;
	else if (x4 && x5) return -2.23;
	return 11.0;
}

double dt2b(double x1, double x2, double x3, int x4, int x5)
{
	if (12.0 < x1 && x1 < 22.0)
	{
		if (x3 > 5.0 / 3.0) return -2.0;
		else if (x1 - 0.1 <= x3 && x3 <= x1 + 0.1) return 1.01;
		return -8.0;
	}
	else if (x4 && x5) return -1;
	else if (-1.0 <= x2 && x2 <= 2.0) return -1.0/7.0;
	return sqrt(2) / 3.0;
}

// My own desicion tree
int	dt3a(int x1, int x2, double x3, double x4, int x5, int x6)
{
	if (x1 <= 6 && x3 >= 7.38)
	{
		if(x1 > 3)
		{
			if (x4 >= 3.14)
			{
				if (x2 < 0) return 1;
				else return 32;
			}
			else if (x5) return 3;
			else return 7;
		}
		else return -1;
	}
	else if(x3 > 1.12 && x4 <= 15.5)
		if (x5 && x6) return 2;
	else return 0;
}

int	dt3b(int x1, int x2, double x3, double x4, int x5, int x6)
{
	if (x5 && x6)
	{
		if (x1 < 5 && x4 > 1.1)
		{
			if (x2 > -20 && x3 < 6.68) return 7;
		}
		else return -7;
	}
	else if (x1 > 1 && x3 > 10.2) return 8;
	else if (x4 < -4) return 13;
	else if (x2 < 10 && x1 > 10) return 14;
	else return -32;
}
/* Provide your implementations for all the requested functions here */