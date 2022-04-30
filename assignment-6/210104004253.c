#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// color macros
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[31;1m"
#define YELLOW_COLOR "\033[33;1m"
#define BLUE_COLOR "\033[34;1m"
#define PURPLE_COLOR "\033[35;1m"
#define DEFAULT_COLOR "\033[0m"

// random number generator in range of [1, 6]
int	dice()
{
	int	result;

	srand(time(NULL));
	result = rand() % 6 + 1;

	return (result);
}

// to print the map
void	printMap(char map[][30], int rowSize, int player1, int player2)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			// red color
			if ((i == 1 && j == 14) || (i == 7 && j == 28) || (i == 13 && j == 14) || // penalty positions of player1
					(i == 3 && j == 10 ) || (i == 3 && j == 18) || (i == 5 && j == 26) || (i == 10 && j == 26) || (i == 11 && j == 10) || (i == 11 && j == 18)) // penalty positions of player2
				printf("%s%c%s", RED_COLOR, map[i][j], DEFAULT_COLOR);
			
			// Yellow color for Player1 positions

			// Upper part
			else if ((player1 <= 27) && 
					(j == player1 + 1 && i == 1))
				printf("%s%c%s", YELLOW_COLOR, map[i][j], DEFAULT_COLOR);

			// Right part
			else if ((player1 > 27 && player1 <= 39) && 
					(i == player1 % 27 + 1 && j == 28))
				printf("%s%c%s", YELLOW_COLOR, map[i][j], DEFAULT_COLOR);

			// Bottom part
			else if ((player1 > 39 && player1 <= 66) &&
					(j == 29 - (player1 % 39 + 1) && i == 13))
				printf("%s%c%s", YELLOW_COLOR, map[i][j], DEFAULT_COLOR);

			// Left part
			else if ((player1 > 66 && player1 <= 78) &&
					(i == 14 - (player1 % 66 + 1) && j == 1))
				printf("%s%c%s", YELLOW_COLOR, map[i][j], DEFAULT_COLOR);


			// Blue color for Player2 positions

			// Upper part
			else if ((player2 <= 23) && 
					(j == player2 + 3 && i == 3))
				printf("%s%c%s", BLUE_COLOR, map[i][j], DEFAULT_COLOR);

			// Right part
			else if ((player2 > 23 && player2 <= 31) && 
					(i == player2 % 23 + 3 && j == 26))
				printf("%s%c%s", BLUE_COLOR, map[i][j], DEFAULT_COLOR);

			// Bottom part
			else if ((player2 > 31 && player2 <= 54) &&
					(j == 29 - (player2 % 31 + 3) && i == 11))
				printf("%s%c%s", BLUE_COLOR, map[i][j], DEFAULT_COLOR);

			// Left part
			else if ((player2 > 54 && player2 <= 62) &&
					(i == 14 - (player2 % 54 + 3) && j == 3))
				printf("%s%c%s", BLUE_COLOR, map[i][j], DEFAULT_COLOR);

			// green color for ending positions
			else if ((i == 2 && j == 1) || (i == 4 && j == 3)) // positions of the finish lines
				printf("%s%c%s", GREEN_COLOR, map[i][j], DEFAULT_COLOR);
			
			else
				printf("%s%c%s", PURPLE_COLOR, map[i][j], DEFAULT_COLOR);
		}
		printf("\n");
	}
}

// dice function for player 1
int	player1Dice()
{
	int dice1;

	printf("%sPLAYER 1... press ENTER to dice%s", YELLOW_COLOR, DEFAULT_COLOR);
	while (getchar() != '\n'); // waiting a character

	dice1 = dice();
	printf("%sDICE: %d%s\n", YELLOW_COLOR, dice1, DEFAULT_COLOR);

	return (dice1);
}

// dice function for player 2
int	player2Dice()
{
	int	dice2;

	printf("%sPLAYER 2... press ENTER to dice%s", BLUE_COLOR, DEFAULT_COLOR);
	while (getchar() != '\n'); // watiting a character

	dice2 = dice();
	printf("%sDICE: %d%s\n", BLUE_COLOR, dice2, DEFAULT_COLOR);
	
	return (dice2);
}

// start function to determine who will start
int	startGame()
{
	int dice1, dice2;
	printf("\nTo start to game, players should dice and decide who is going to start first according to it...\n");
	
	for (int i = 0; i == 0 || dice1 == dice2; i++) /* I used the short circuit evaluation */
	{
		if (i != 0)
			printf("\nSame dice value... Please try again.\n");

		dice1 = player1Dice();
		dice2 = player2Dice();
	}
	
	if (dice1 > dice2)
		return (1);
	return (2);
}

// my createMap function to create the map
void	createMap(char map[][30], int rowSize, int player1, int player2)
{
	int i, j;

	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < 30; j++)
		{
			// i & 1 => i % 2 same meaning but faster in processing
			if ((i < 5) && !(i & 1) && (i <= j && i + j <= 29) || // upper part
				(i > 9) && !(i & 1) && ((14 - i) <= j && (14 - i) + j <= 29)) // bottom part	
				map[i][j] = '-';

			else if ((j < 5) && !(j & 1) && (j - i <= -1 && j + i <= 13) || // left part
					(j > 24) && (j & 1) && ((29 - j) - i <= -1 && (29 - j) + i <= 13)) // right part
				map[i][j] = '|';

			else if ((i == 1 && j == 14) || (i == 7 && j == 28) || (i == 13 && j == 14) || // penalty positions of player1
					(i == 3 && j == 10 ) || (i == 3 && j == 18) || (i == 5 && j == 26) || (i == 10 && j == 26) || (i == 11 && j == 10) || (i == 11 && j == 18)) // penalty positions of player2
				map[i][j] = 'X';


			// Player1 positions

			// Upper part
			else if ((player1 <= 27) && 
					(j == player1 + 1 && i == 1))
				map[i][j] = '1';

			// Right part
			else if ((player1 > 27 && player1 <= 39) && 
					(i == player1 % 27 + 1 && j == 28))
				map[i][j] = '1';

			// Bottom part
			else if ((player1 > 39 && player1 <= 66) &&
					(j == 29 - (player1 % 39 + 1) && i == 13))
				map[i][j] = '1';

			// Left part
			else if ((player1 > 66 && player1 <= 78) &&
					(i == 14 - (player1 % 66 + 1) && j == 1))
				map[i][j] = '1';


			// Player2 positions

			// Upper part
			else if ((player2 <= 23) && 
					(j == player2 + 3 && i == 3))
				map[i][j] = '2';

			// Right part
			else if ((player2 > 23 && player2 <= 31) && 
					(i == player2 % 23 + 3 && j == 26))
				map[i][j] = '2';

			// Bottom part
			else if ((player2 > 31 && player2 <= 54) &&
					(j == 29 - (player2 % 31 + 3) && i == 11))
				map[i][j] = '2';

			// Left part
			else if ((player2 > 54 && player2 <= 62) &&
					(i == 14 - (player2 % 54 + 3) && j == 3))
				map[i][j] = '2';

			// positions of the finish lines
			else if ((i == 2 && j == 1) || (i == 4 && j == 3))
				map[i][j] = '_';

			else
				map[i][j] = ' ';
		}
	}
}

int	main(void)
{
	char	map[15][30];
	int player1 = 0, player2 = 0, game = 1, startFlag;

	for (int i = 0; game; i++)
	{
		if (player1 >= 78 && player2 < 62)
		{
			printf("%s *** PLAYER 1 WON THE GAME ***%s\n", YELLOW_COLOR, DEFAULT_COLOR);
			player1 -= 78;
			game = 0; 
		}
		else if (player2 >= 62 && player1 < 78)
		{
			printf("%s *** PLAYER 2 WON THE GAME ***%s\n", BLUE_COLOR, DEFAULT_COLOR);
			player2 -= 62;
			game = 0;
		}
		else if (player1 >= 78 && startFlag == 1) /* if two players cross the finish line at the same time */
		{
			printf("%s *** PLAYER 1 WON THE GAME ***%s\n", YELLOW_COLOR, DEFAULT_COLOR);
			player1 -= 78;
			player2 -= 62;
			game = 0; 
		}
		else if (player2 >= 68 && startFlag == 2)
		{
			printf("%s *** PLAYER 2 WON THE GAME ***%s\n", BLUE_COLOR, DEFAULT_COLOR);
			player2 -= 62;
			player1 -= 78;
			game = 0;
		}

		// map part
		createMap(map, 15, player1, player2);
		printMap(map, 15, player1, player2);

		// beginning of the game
		if (i == 0) startFlag = startGame();

		// game
		if (game && startFlag == 1)
		{
			if (i == 0) printf("\n *** PLAYER 1 will start the game... ***\n");
			
			player1 += player1Dice();
		
			// penalty for player1
			if (player1 == 13 ||
				player1 == 33 ||
				player1 == 53 )
			{
				printf("%sPenalty for player 1...%s\n", YELLOW_COLOR, DEFAULT_COLOR);
				player1 -= 2;
			}
		
			player2 += player2Dice();

			// penalty for player2
			if (player2 == 7 ||
				player2 == 15 ||
				player2 == 25 ||
				player2 == 30 ||
				player2 == 39 ||
				player2 == 47)
			{
				printf("%sPenalty for player 2...%s\n", BLUE_COLOR, DEFAULT_COLOR);
				player2 -= 2;
			}
		}
		else if (game)
		{
			if (i == 0) printf("\n *** PLAYER 2 will start the game... ***\n");
			
			player2 += player2Dice();
			
			// penalty for player2
			if (player2 == 7 ||
				player2 == 15 ||
				player2 == 25 ||
				player2 == 30 ||
				player2 == 39 ||
				player2 == 47)
			{
				printf("%sPenalty for player 2...%s\n", BLUE_COLOR, DEFAULT_COLOR);
				player2 -= 2;
			}

			player1 += player1Dice();

			// penalty for player1
			if (player1 == 13 ||
				player1 == 33 ||
				player1 == 53 )
			{
				printf("%sPenalty for player 1...%s\n", YELLOW_COLOR, DEFAULT_COLOR);
				player1 -= 2;
			}
		}


	}

	return (0);
}