#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(double pl, double pw, double sl, double sw);
char dt1b(double pl, double pw, double sl, double sw);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int	dt3a(int x1, int x2, double x3, double x4, int x5, int x6);
int	dt3b(int x1, int x2, double x3, double x4, int x5, int x6);

#endif /* _UTIL_H_ */