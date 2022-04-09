#include <stdio.h>

// generating 2d plaintext-keystream graph(array)
void	generate_2d_alphabet(char arr[][26], int rowSize)
{
	char	ch;

	for (int i = 0; i < rowSize; i++)
	{
		ch = 'A' + i;
		for (int j = 0; j < 26; j++)
		{
			// decreasing char single by single
			if (ch + j <= 'Z')
				arr[i][j] = ch + j;
			else // if char is greater than 'Z'
				arr[i][j] = ch + j - ('Z' - 'A') - 1;
		}
	}
}

// to print table
void	print_alphabet(char arr[][26], int rowSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 26; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}

void	encryption(char arr[][26], int rowSize)
{
	char	buff, plain_text[50], key[50], key_stream[50], ciphertext[50];
	int	i = 0, key_len = -1;

	printf("*** ENCRYPTION ***\n\n"
			"Plaintext: ");
	
	// get char until char is equal to '\n' new line character
	while ((buff = getchar()) != '\n')
	{
		plain_text[i++] = buff;
	}
	plain_text[i] = 0;

	printf("Key: ");

	// key inputs
	for (i = 0; (buff = getchar()) != '\n'; i++)
		key[i] = buff;
	key[i] = 0;

	// key strlen
	while (key[++key_len]);

	// creating keystream
	for (i = 0; plain_text[i]; i++)
	{
		key_stream[i] = key[i%key_len];
	}
	key_stream[i] = 0;

	printf("Keystream: ");

	// to print keystream
	for (i = 0; key_stream[i]; i++)
		printf("%c", key_stream[i]);
	printf("\n");

	// for ciphertext
	for (i = 0; plain_text[i]; i++)
		ciphertext[i] = arr[key_stream[i] - 'A'][plain_text[i] - 'A'];
	ciphertext[i] = 0;

	printf("Ciphertext: ");
	// to print ciphertext
	for (i = 0; ciphertext[i]; i++)
		printf("%c", ciphertext[i]);
	printf("\n");

}

void	decryption(char arr[][26], int rowSize)
{
	char	buff, plain_text[50], key[50], key_stream[50], ciphertext[50];
	int	i = 0, key_len = -1;

	printf("*** DECRYPTION ***\n\n"
			"Ciphertext: ");
	
	// get char until char is equal to '\n' new line character
	while ((buff = getchar()) != '\n')
	{
		ciphertext[i++] = buff;
	}
	ciphertext[i] = 0;

	printf("Key: ");

	// key inputs
	for (i = 0; (buff = getchar()) != '\n'; i++)
		key[i] = buff;
	key[i] = 0;

	// key strlen
	while (key[++key_len]);

	// creating keystream
	for (i = 0; ciphertext[i]; i++)
	{
		key_stream[i] = key[i%key_len];
	}
	key_stream[i] = 0;

	printf("Keystream: ");

	// to print keystream
	for (i = 0; key_stream[i]; i++)
		printf("%c", key_stream[i]);
	printf("\n");

	// for ciphertext
	for (i = 0; ciphertext[i]; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[key_stream[i] - 'A'][j] == ciphertext[i]) plain_text[i] = j + 'A';
		}
	}
	plain_text[i] = 0;

	printf("Plaintext: ");
	// to print plaintext
	for (i = 0; plain_text[i]; i++)
		printf("%c", plain_text[i]);
	printf("\n");

}

int	main(void)
{
	int	selection;
	char	alphabet[26][26];

	generate_2d_alphabet(alphabet, 26);


	do { // selection menu
		printf("\nWelcome to the menu\n"
				"1- Print the table\n"
				"2- Encryption\n"
				"3- Decryption\n"
				"4- Exit\n");

		selection = getchar() - '0';
		getchar();

		switch (selection)
		{
			case 1:
				print_alphabet(alphabet, 26);
				break;

			case 2:
				encryption(alphabet, 26);
				break;

			case 3:
				decryption(alphabet, 26);
				break;

			default:
				break;
		}

	} while (selection != 4);

	return (0);
}