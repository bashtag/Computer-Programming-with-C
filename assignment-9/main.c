#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUSTOMERS_FILE_NAME "customers.txt"
#define LOANS_FILE_NAME "loans.txt"

#define bool int
#define true 1
#define false 0

/**
 * @brief Person union
 * 
 */
union Person
{
	char name[50];
	char address[50];
	int phone;
};

/**
 * @brief arr[3] -> amount, interest rate, period
 * 
 */
union Loan
{
	float	arr[3];
};

/**
 * @brief Account struct for my accounts dynamicaly allocated struct array
 * 
 */
struct BankAccount
{
	int	personId;
	int	loanCount;
	union Person Customer;
	union Loan Loans[3];
};

/**
 * @brief list customer part
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	listCustomers(struct BankAccount *bankAccount, int accountSize)
{
	for (int i = 0; i < accountSize; i++)
	{
		printf("\n\nCustomer ID = %d"
			"\nCustomer Name = %s", bankAccount[i].personId, bankAccount[i].Customer.name);
	}
}

/**
 * @brief calculate loan recursive function
 * 
 * @param amount 
 * @param period 
 * @param interestRate 
 * @return float 
 */
float	calculateLoan(float amount, int period, float interestRate)
{
	if (period == 0)
		return (amount);
	else if (period == 1)
		return (amount*(1.0 + interestRate));
	else if (period > 1)
		return (calculateLoan(amount, period - 1, interestRate) * (1.0 + interestRate));
}

/**
 * @brief Get the Customers from files into the bankAccount dynamicaly allocated struct array
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	getCustomers(struct BankAccount *bankAccount, int *accountSize)
{
	FILE	*customersFile, *loansFile;
	char	buff[50];
	char	debug[50];
	/* -1 error value */
	int	id_buff = -1, loan_index;

	customersFile = fopen(CUSTOMERS_FILE_NAME, "r");
	loansFile = fopen(LOANS_FILE_NAME, "r");

	/* get names from customers.txt file */
	while (!feof(customersFile))
	{
		fgets(bankAccount[(*accountSize)++].Customer.name, 50, customersFile);
		bankAccount[(*accountSize) - 1].personId = (*accountSize) - 1;
		bankAccount[(*accountSize) - 1].loanCount = 0;

		if (!feof(customersFile))
			fgets(buff, 50, customersFile);
		if (!feof(customersFile))
			fgets(buff, 50, customersFile);
	}

	if (strcmp(bankAccount[(*accountSize) - 1].Customer.name, "") == 0)
		(*accountSize)--;
	/* getting names part is finished */


	/* get loans from loans.txt file */
	while (!feof(loansFile) && fgets(buff, 50, loansFile))
	{
		if (strcmp(buff, "") != 0)
		{
			sscanf(buff, "%d", &id_buff);

			if (id_buff < *accountSize && bankAccount[id_buff].loanCount < 3)
			{
				loan_index = bankAccount[id_buff].loanCount;
				sscanf(buff, "%d %f %f %f", &id_buff, &bankAccount[id_buff].Loans[loan_index].arr[0], &bankAccount[id_buff].Loans[loan_index].arr[1], &bankAccount[id_buff].Loans[loan_index].arr[2]);
				(bankAccount[id_buff].loanCount)++;
			}
			else
				printf("\nERROR! Invalid id\n");
		}
		else if (id_buff != -1)
		{
			(bankAccount[id_buff].loanCount)--;
		}
	}
	/* getting loans part is finished */

	fclose(customersFile);
	fclose(loansFile);
}

/**
 * @brief Get Credit Details from file
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	getCreditDetail(struct BankAccount *bankAccount, int accountSize)
{
	float	totalLoan;

	for (int i = 0; i < accountSize; i++)
	{
		printf("\n\nCustomer ID = %d"
			"\nCustomer Name = %s"
			"\nLoans = [", bankAccount[i].personId, bankAccount[i].Customer.name);

		if (bankAccount[i].loanCount != 0)
		{
			totalLoan = 0.0;

			for (int j = 0; j < bankAccount[i].loanCount; j++)
			{
				printf("%.2f + ", bankAccount[i].Loans[j].arr[0]);
				totalLoan += bankAccount[i].Loans[j].arr[0];
			}
			printf("\b\b\b] => %.2f\n", totalLoan);
		}
		else
			printf("\b0\n");
	}

}

/**
 * @brief Get Loan Details from file
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	getLoanDetail(struct BankAccount *bankAccount, int accountSize)
{
	float	totalCreditValue, eachMonth;
	int	loanSelection;
	int	idSelection;
	int	period;

	printf("\nGetting Loan Detail\n"
		"\nCustomer ID: ");
	if (!scanf("%d", &idSelection))
	{
		printf("\nWrong type\n");
		while (getchar() != '\n');
		return;
	}
	while (getchar() != '\n');

	printf("\nWhich Loan: ");
	if (!scanf("%d", &loanSelection))
	{
		printf("\nWrong type\n");
		while (getchar() != '\n');
		return;
	}

	if (idSelection < accountSize && loanSelection <= bankAccount[idSelection].loanCount)
	{
		period = (int)(bankAccount[idSelection].Loans[loanSelection - 1].arr[2]);
		
		totalCreditValue = calculateLoan(bankAccount[idSelection].Loans[loanSelection - 1].arr[0], 
			period,
			bankAccount[idSelection].Loans[loanSelection - 1].arr[1]);

		eachMonth = totalCreditValue / (float)(period);

		printf("\nTotal Credit Value = %.4f", totalCreditValue);

		for (int i = 0; i < period; i++)
			printf("\n%d. Month Installment = %.4f", i + 1, eachMonth);
		printf("\n");
	}
}

/**
 * @brief to add a customer in file and struct
 * 
 * @param bankAccount 
 * @return struct BankAccount* 
 */
struct BankAccount*	addCustomer(struct BankAccount *bankAccount, int (*accountSize))
{
	struct BankAccount *resizeAccount = (struct BankAccount *)calloc(++(*accountSize), sizeof(struct BankAccount));
	FILE	*accountsFile;
	int	scanfValue = 1;
	union Person	nameBuff;

	for (int i = 0; i < (*accountSize) - 1; i++)
		resizeAccount[i] = bankAccount[i];

	accountsFile = fopen(CUSTOMERS_FILE_NAME, "a");

	printf("\nCustomer Name: ");
	scanf(" %[^\n]%*c", resizeAccount[(*accountSize) - 1].Customer.name);
	fprintf(accountsFile, "%s\n", resizeAccount[(*accountSize) - 1].Customer.name);
	strcpy(nameBuff.name, resizeAccount[(*accountSize) - 1].Customer.name);

	printf("\nCustomer Address: ");
	scanf(" %[^\n]%*c", resizeAccount[(*accountSize) - 1].Customer.address);
	fprintf(accountsFile, "%s\n", resizeAccount[(*accountSize) - 1].Customer.address);
	do
	{
		printf("\nCustomer Phone: ");
		scanfValue = scanf("%d", &resizeAccount[(*accountSize) - 1].Customer.phone);
		if (scanfValue == 0)
		{
			printf("\nPlease enter a valid phone number.");

			/* to clear buffer */
			while (getchar() != '\n');
		}
		else
		{
			fprintf(accountsFile, "%d\n", resizeAccount[(*accountSize) - 1].Customer.phone);
			resizeAccount[(*accountSize) - 1].personId = (*accountSize) - 1;
		}
	} while (scanfValue == 0);

	fclose(accountsFile);

	/* to clear buffer */
	while (getchar() != '\n');

	strcpy(resizeAccount[(*accountSize) - 1].Customer.name, nameBuff.name);

	resizeAccount[(*accountSize) - 1].loanCount = 0;

	return (resizeAccount);
}

/**
 * @brief to add a loan for related account
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	newLoan(struct BankAccount *bankAccount, int accountSize)
{
	FILE *loansFile;
	bool	isUserFound = false;
	int	accountId;
	int	howMuchCredit;
	int	i;

	printf("\nAdding New Loan\n"
		"\nCustomer ID: ");
	if (!scanf("%d", &accountId))
	{
		printf("\nWrong type\n");
		while (getchar() != '\n');
		return;
	}
	while (getchar() != '\n');

	i = accountId;

	if (i < accountSize)
		isUserFound = true;

	if (!isUserFound)
		printf("\nUser hasn't been found.");
	else
	{
		printf("\nEnter how much credit you want to enter: ");
		if (!scanf("%d", &howMuchCredit))
		{
			printf("\nWrong type\n");
			while (getchar() != '\n');
			return;
		}
		while (getchar() != '\n');

		if (howMuchCredit + bankAccount[i].loanCount > 3)
			printf("\nEach account can have up to three credits. Please try again.");
		else
		{
			for (int j = bankAccount[i].loanCount; j < howMuchCredit + bankAccount[i].loanCount; j++)
			{
				printf("\n%d. loan amount: ", j + 1);
				if (!scanf("%f", &bankAccount[i].Loans[j].arr[0]))
				{
					printf("\nWrong type\n");
					while (getchar() != '\n');
					return;
				}
				while (getchar() != '\n');
				printf("\n%d. loan interest rate: ", j + 1);
				if (!scanf("%f", &bankAccount[i].Loans[j].arr[1]))
				{
					printf("\nWrong type\n");
					while (getchar() != '\n');
					return;
				}
				while (getchar() != '\n');
				printf("\n%d. loan period: ", j + 1);
				if (!scanf("%f", &bankAccount[i].Loans[j].arr[2]))
				{
					printf("\nWrong type\n");
					while (getchar() != '\n');
					return;
				}
				while (getchar() != '\n');
			}
			bankAccount[i].loanCount += howMuchCredit;
		}
	}


	/* loan.txt part */
	loansFile = fopen(LOANS_FILE_NAME, "w");

	for (int j = 0; j < accountSize; j++)
		for (int k = 0; k < bankAccount[j].loanCount; k++)
			fprintf(loansFile, "%d %.2f %.2f %.2f\n", bankAccount[j].personId, bankAccount[j].Loans[k].arr[0], bankAccount[j].Loans[k].arr[1], bankAccount[j].Loans[k].arr[2]);

	fclose(loansFile);
	/* loan.txt part end */
}

/**
 * @brief Report Function
 * 
 * @param bankAccount 
 * @param accountSize 
 */
void	getReport(struct BankAccount *bankAccount, int accountSize)
{
	int	selection = 0;

	do
	{
		printf("\nReport:"
			"\t1. Credit Detail\n"
			"\t2. Loan Detail\n");
		
		if (!scanf("%d", &selection))
		{
			printf("\nWrong type\n");
			while (getchar() != '\n');
			return;
		}

		if (selection != 1 && selection != 2)
			printf("\nTry Again\n");
		else if (selection == 1)
			getCreditDetail(bankAccount, accountSize);
		else if (selection == 2)
			getLoanDetail(bankAccount, accountSize);
	} while (selection != 1 && selection != 2);
}

int	main(void)
{
	int	selection, accountSize = 0;
	struct BankAccount *bankAccount = (struct BankAccount*)calloc(50, sizeof(struct BankAccount));

	getCustomers(bankAccount, &accountSize);

	do {
		printf("\n====================================\n"
			"Welcome to the Bank Management System\n"
			"====================================\n"
			"\t1. List All Customers\n"
			"\t2. Add New Customer\n"
			"\t3. New Loan Application\n"
			"\t4. Report Menu\n"
			"\t5. Exit System\n");
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				listCustomers(bankAccount, accountSize);
				break;

			case 2:
				bankAccount = addCustomer(bankAccount, &accountSize);
				break;

			case 3:
				newLoan(bankAccount, accountSize);
				break;

			case 4:
				getReport(bankAccount, accountSize);
				break;

			case 5:
				break;

			default:
				printf("Please give a number range from 1 to 5\n");
				break;
		}

	} while (selection != 5);
	return (0);
}