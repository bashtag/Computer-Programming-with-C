#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define WORDS_SIZE 50
#define WORD_LENGHT 6
#define WORD_COUNT 7
#define ROW_SIZE 15
#define COL_SIZE 15

typedef enum {
	east,
	southeast,
	south,
	southwest,
	west,
	northwest,
	north,
	northeast
} Directions;

/* to store seven words */
typedef struct
{
	int	row;
	int	col;
	char	word[WORD_LENGHT];
	Directions direction;
} WordToFind;


// if given location on the board is empty return 1 else 0
bool	isEmpty(char board[][COL_SIZE], int row, int col, Directions direction, int word_len)
{
	int i, j;
	bool	flag = true;

	switch (direction)
	{
		// east direction
		case east:
			for (j = col; j < col + word_len && flag; j++)
				if (board[row][j] != 0)
					flag = false;
			break;

		// southeast direction
		case southeast:
			for (i = row, j = col; i < row + word_len && flag; i++, j++)
				if (board[i][j] != 0)
					flag = false;
			break;
		
		// south direction
		case south:
			for (i = row; i < row + word_len && flag; i++)
				if (board[i][col] != 0)
					flag = false;
			break;

		// southwest direction
		case southwest:
			for (i = row, j = col; i < row + word_len && flag; i++, j--)
				if (board[i][j] != 0)
					flag = false;
			break;

		// west direction
		case west:
			for (j = col; j > col - word_len && flag; j--)
				if (board[row][j] != 0)
					flag = false;
			break;

		// northwest direction
		case northwest:
			for (i = row, j = col; i > row - word_len && flag; i--, j--)
				if (board[i][j] != 0)
					flag = false;
			break;

		// north direction
		case north:
			for (i = row; i > row - word_len && flag; i--)
				if (board[i][col] != 0)
					flag = false;
			break;

		// northeast direction
		case northeast:
			for (i = row, j = col; i > row - word_len && flag; i--, j++)
				if (board[i][j] != 0)
					flag = false;
			break;

		default:
			break;
	}

	return (flag);
}

/**
 * @brief place random words in the words string array on the board
 * 
 * @param words 
 * @param board 
 * @param chosen_word 
 * @param direction 
 * @return WordToFind 
 */
WordToFind	wordRandomPlacer(char words[][WORD_LENGHT], char board[][COL_SIZE], int chosen_word, Directions direction)
{
	WordToFind word_to_find;
	int	i, j, r_row, r_col, word_len;
	bool	has_it_been_placed = false;

	do {
		word_len = strlen(words[chosen_word]);

		switch (direction)
		{
			// east direction
			case east:
				r_row = rand() % (15);
				r_col = rand() % (15 - word_len); /* for not exceed the limit while increasing*/
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (j = r_col; j < r_col + word_len; j++)
						board[r_row][j] = words[chosen_word][j - r_col];
					has_it_been_placed = true;
				}
				break;

			// southeast direction
			case southeast:
				r_row = rand() % (15 - word_len);
				r_col = rand() % (15 - word_len);
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row, j = r_col; i < r_row + word_len; i++, j++)
						board[i][j] = words[chosen_word][i - r_row];
						has_it_been_placed = true;
				}
				break;

			// south direction
			case south:
				r_row = rand() % (15 - word_len);
				r_col = rand() % (15);
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row; i < r_row + word_len; i++)
						board[i][r_col] = words[chosen_word][i - r_row];
						has_it_been_placed = true;
				}
				break;

			// southwest direction
			case southwest:
				r_row = rand() % (15 - word_len);
				r_col = rand() % (15 - word_len) + word_len; /* for not exceed the limit while reducing*/
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row, j = r_col; i < r_row + word_len; i++, j--)
						board[i][j] = words[chosen_word][i - r_row];
						has_it_been_placed = true;
				}
				break;

			// west direction
			case west:
				r_row = rand() % (15);
				r_col = rand() % (15 - word_len) + word_len;
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (j = r_col; j > r_col - word_len; j--)
						board[r_row][j] = words[chosen_word][r_col - j];
						has_it_been_placed = true;
				}
				break;

			// northwest direction
			case northwest:
				r_row = rand() % (15 - word_len) + word_len;
				r_col = rand() % (15 - word_len) + word_len;
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row, j = r_col; i > r_row - word_len; i--, j--)
						board[i][j] = words[chosen_word][r_col - j];
						has_it_been_placed = true;
				}
				break;

			// north direction
			case north:
				r_row = rand() % (15 - word_len) + word_len;
				r_col = rand() % (15);
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row; i > r_row - word_len; i--)
						board[i][r_col] = words[chosen_word][r_row - i];
						has_it_been_placed = true;
				}
				break;

			// northeast direction
			case northeast:
				r_row = rand() % (15 - word_len) + word_len;
				r_col = rand() % (15 - word_len);
				if (isEmpty(board, r_row, r_col, direction, word_len))
				{
					for (i = r_row, j = r_col; i > r_row - word_len; i--, j++)
						board[i][j] = words[chosen_word][r_row - i];
						has_it_been_placed = true;
				}
				break;
			
			default:
				break;
		}
	} while (!isEmpty(board, r_row, r_col, direction, word_len) && !has_it_been_placed);

	word_to_find.row = r_row;
	word_to_find.col = r_col;
	strcpy(word_to_find.word, words[chosen_word]);
	word_to_find.direction = direction;

	return (word_to_find);
}

// Board Build Part
// 15x15 board with 7 words from "worldlist.txt" file
void	buildBoard(char words[][WORD_LENGHT], char board[][COL_SIZE], WordToFind words_to_find[])
{
	FILE	*words_file;
	Directions direction;
	
	/* hash_map to avoid getting same word*/
	int	i, j, chosen_word, hash_map[WORDS_SIZE];

	/* Fill the hash_map with zeros */
	for (i = 0; i < WORDS_SIZE; i++)
		hash_map[i] = 0;

	/* Extract words from file */
	words_file = fopen("wordlist.txt", "r");

	for (i = 0; !feof(words_file); i++)
		fscanf(words_file, "%s", words[i]);

	fclose(words_file);
	/* File partition is finished */

	// Fill the board with zeros because of overlapping words
	for (i = 0; i < ROW_SIZE; i++)
		for (j = 0; j < COL_SIZE; j++)
			board[i][j] = 0;

	/* build a 15x15 board with randomly located words and random letters */
	for (i = 0; i < WORD_COUNT; i++)
	{
		while (hash_map[chosen_word = rand()%50]++ != 0);
		direction = rand()%8;
		
		words_to_find[i] = wordRandomPlacer(words, board, chosen_word, direction);
	}
	/* building board is finished */

	/* Fill the remaining area of the board with randomly chosen letters */
	/*for (i = 0; i < ROW_SIZE; i++)
		for (j = 0; j < COL_SIZE; j++)
			board[i][j] = rand() % ('z' - 'a' + 1) + 'a';*/
	
	/* the end of the creating board function */
}

/* to print the board */
void	printBoard(char board[][COL_SIZE])
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			if (board[i][j] != 0) printf("%c ", board[i][j]);
			else printf(". ");
		}
		printf("\n");
	}
}

/**
 * @brief Return 1 if words_to_find contains user input,
 * return 0 otherwise
 * 
 * @param words_to_find
 * @param row
 * @param col
 * @param given_word
 * @return true 
 * @return false 
 */
bool	isThereOnBoard(WordToFind words_to_find[], int row, int col, char given_word[])
{
	int	flag = false;

	for (int i = 0; i < WORD_COUNT && !flag; i++)
		if (words_to_find[i].row == row &&
			words_to_find[i].col == col &&
			strcmp(words_to_find[i].word, given_word) == 0)
			flag = true;
	
	return (flag);
}

/**
 * @brief remove the found words from WordToFind and board
 * 
 * @param board 
 * @param words_to_find 
 * @param row 
 * @param col 
 * @param given_word 
 */
void	removeTheFound(char board[][COL_SIZE], WordToFind words_to_find[], int row, int col, char given_word[])
{
	int	i, j, word_len;
	bool	is_x_placed = false;

	for (int k = 0; k < WORD_COUNT && !is_x_placed; k++) {
		if (words_to_find[k].row == row &&
			words_to_find[k].col == col &&
			strcmp(words_to_find[k].word, given_word) == 0)
		{
			word_len = strlen(given_word);
			switch (words_to_find[k].direction)
			{
				// east direction
				case east:
					for (j = col; j < col + word_len; j++)
						board[row][j] = 'X';
					break;

				// southeast direction
				case southeast:
					for (i = row, j = col; i < row + word_len; i++, j++)
						board[i][j] = 'X';
					break;

				// south direction
				case south:
					for (i = row; i < row + word_len; i++)
						board[i][col] = 'X';
					break;

				// southwest direction
				case southwest:
					for (i = row, j = col; i < row + word_len; i++, j--)
						board[i][j] = 'X';
					break;

				// west direction
				case west:
					for (j = col; j > col - word_len; j--)
						board[row][j] = 'X';
					break;

				// northwest direction
				case northwest:
					for (i = row, j = col; i > row - word_len; i--, j--)
						board[i][j] = 'X';
					break;

				// north direction
				case north:
					for (i = row; i > row - word_len; i--)
						board[i][col] = 'X';
					break;

				// northeast direction
				case northeast:
					for (i = row, j = col; i > row - word_len; i--, j++)
						board[i][j] = 'X';
					break;
				
				default:
					break;
			}
			strcpy(words_to_find[k].word, "X");
			is_x_placed = true;
		}
	}
}

int	main(void)
{
	char	words[WORDS_SIZE][WORD_LENGHT];
	char	board[ROW_SIZE][COL_SIZE];
	WordToFind words_to_find[WORD_COUNT];
	int	i, j, mistakes = 3, score = 0;
	
	char	user_input[50];
	int	row, col;
	char	given_word[WORDS_SIZE];

	srand(time(NULL));

	buildBoard(words, board, words_to_find);

	/* to print the content of words_to_find */
	for (i = 0; i < WORD_COUNT; i++)
		printf("row-> %d, column-> %d, word-> %s\n",
			words_to_find[i].row,
			words_to_find[i].col,
			words_to_find[i].word);

	do
	{
		printBoard(board);
		printf("Enter coordinates and word:");
		fgets(user_input, 50, stdin);
		user_input[strlen(user_input) - 1] = 0; /* '\n' character */
		
		if (strcmp(user_input, ":q") != 0)
		{
			row = atoi(user_input);
			col = atoi(&user_input[2]);

			/* for the given word,
			it looks for the last space */
			for (i = strlen(user_input) - 1; user_input[i] != ' '; i--);
			strcpy(given_word, &user_input[i + 1]);

			if (isThereOnBoard(words_to_find, row, col, given_word))
			{
				score += 2;
				printf("Founded! You got 2 points. Your total points: %d\n", score);
				removeTheFound(board, words_to_find, row, col, given_word);
			}
			else
				printf("Wrong choice! You have only %d lefts.\n", --mistakes);
		}
	} while (mistakes != 0 && strcmp(user_input, ":q") != 0 && score != 14);
	
	printf("Game Finished. Your total points: %d\n", score);

	return (0);
}