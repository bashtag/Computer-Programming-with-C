#include <stdio.h>
#include "utils.h"

int	main(void)
{
	printf("Part-1\n");
	printf("-----------------------------------\n");
	int	x, y, divisor, f_I, n, nth_I;

	printf("Enter the first integer: ");
	scanf("%d", &x);
	printf("Enter the second integer: ");
	scanf("%d", &y);
	printf("Enter divisor: ");
	scanf("%d", &divisor);

	f_I = find_divisible(x, y, divisor);
	if (f_I == -1)
		printf("Output> There is not any integer between %d and %d can be divided by %d\n", x, y, divisor);
	else
	{
		printf("Output> The first integer between %d and %d divided by %d is %d\n", x, y, divisor, f_I);
		printf("Enter the number how many next: ");
		scanf("%d",&n);
		nth_I = find_nth_divisible(n, f_I, divisor);
		/* I handled the range of nth_I */
		if (nth_I >= y)
			printf("Output> No possible to find %dth divisible between %d and %d divided by %d\n", n+1, x, y, divisor);
		else
			printf("Output> The %dth integer between %d and %d divided by %d is %d\n", n, x, y, divisor, nth_I);
	}
	printf("-----------------------------------\n");

	printf("Part-2\n");
	printf("-----------------------------------\n");
	char	identity_number[12];  /* 12 because of null character */
	int password = 0, validate_identity = 0; /* to get into loops */

	/* It will ask to enter a identity number until a valid identity number */
	while (!validate_identity)
	{
		printf("Enter your identity number: ");
		scanf("%s", identity_number);
		validate_identity = validate_identity_number(identity_number);
		if (!validate_identity) printf("Output> \"Identity number is invalid!\"\n");
	}

	/* It will ask to enter a password until password is a 4 digit number */
	while (password < 1000 || password > 9999)
	{
		printf("Enter your 4 digit password: ");
		scanf("%d", &password);
	}
	
	create_customer(identity_number, password);
	printf("-----------------------------------\n");
	
	printf("Part-3\n");
	printf("-----------------------------------\n");
	char	check_identity[12];
	password = 0; /* to use the same variable */
	
	printf("Enter your identity number: ");
	scanf("%s", check_identity);
	printf("Enter your password: ");
	scanf("%d", &password);

	if (!check_login(check_identity, password))
		printf("Output> \"Invalid identity number or password\"\n");
	else
	{
		/* I have declared withdraw_amount here because if login fails, the variable won't take up memory space*/
		float	withdraw_amount = 0;
		printf("Output> \"Login Successful\"\n");
		printf("Enter your withdraw amount: ");
		scanf("%f", &withdraw_amount);
		printf("Output> Withdrawable amount is: %d\n", withdrawable_amount(withdraw_amount));
	}
	printf("-----------------------------------\n");

	return (0);
}