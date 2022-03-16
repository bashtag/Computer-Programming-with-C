#include "utils.h"
#include <stdio.h>

int	find_divisible(int x, int y, int z)
{
	int	f_i = 0;

	for (f_i = x + 1; f_i % z != 0 && f_i < y; f_i++);
	
	if (f_i >= y)
		return (-1);
	else
		return (f_i);
}

int	find_nth_divisible(int n, int f_I, int z)
{
	/* f_I += z * n; */
	for (int i = 0; i < n; i++)
		f_I += z;
	return (f_I);
}

int	validate_identity_number(char identity_number[])
{
	int	i, len = -1, odds_total = 0, evens_total = 0;
	
	while (identity_number[++len] != '\0'); /* strlen function */
	if (len != 11) return (0);
	else if (identity_number[0] == 0) return (0);  /* the identity number's last digit cannot be zero */

	for (i = 0; i < len; i++)
	{
		if (i % 2 == 0 && i != 10) odds_total += identity_number[i] - '0';
		if (i % 2 == 1 && i != 9) evens_total += identity_number[i] - '0';
	}
	/* some rules of the identity number */
	if ((odds_total * 7 - evens_total) % 10 != identity_number[9] - '0') return (0);
	if ((odds_total + evens_total + identity_number[9] - '0') % 10 != identity_number[10] - '0') return (0);
	return (1);
}

int	create_customer(char identity_number[], int password)
{
	FILE	*customer_accounts;

	customer_accounts = fopen("customeraccount.txt", "w");

	fprintf(customer_accounts, "%s,%d\n", identity_number, password);

	fclose(customer_accounts);
	return (1);
}

int	check_login(char identity_number[], int password)
{
	char	check_identity[12], buffer[2]; /* 12 because of null character */
	int		check_passwd = 0, i;
	FILE *check_customer;

	check_customer = fopen("customeraccount.txt", "r");

	fscanf(check_customer, "%11s", check_identity);
	fscanf(check_customer, "%1s", buffer);
	fscanf(check_customer, "%d", &check_passwd);

	for (i = 0; check_identity[i]
		&& check_identity[i] == identity_number[i]; i++);
	fclose(check_customer);
	
	/* return 1 if password and identity number match */
	if (i != 11) return (0);
	if (password != check_passwd) return(0);

	return (1);
}

int	withdrawable_amount(float cash_amount)
{
	int withdrawable = (int)cash_amount;
	int mod = 0;

	/* for example 232.12tl cash amount => 230 withdrawable amount*/
	mod = withdrawable % 10;
	
	return (withdrawable - mod);
}