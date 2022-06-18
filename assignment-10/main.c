#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
#define STACK_BLOCK_SIZE 10

/**
 * @brief stack definition and declaration
 * 
 */
typedef struct {
	int *array;
	int currentsize;
	int maxsize;
} stack; 
  
int	push(stack * s, int d);
/* the stack array will grow STACK_BLOCK_SIZE entries at a time */ 
  
int	pop(stack * s);
/* the stack array will shrink STACK_BLOCK_SIZE entries at a time */ 
  
stack	*init_return();
/* initializes an empty stack */

int	init(stack * s);
/* returns 1 if initialization is successful */

void	deleteStack(stack *s);
/* deletes stack */

bool	initSticks(stack *stack_A, stack *stack_B, stack *stack_C);
/* initializes sticks */

void	moveDisk(stack **stacks, int disk, int isSizeOdd);
/* to move disks */

void	towerOfHanoi(stack *stack_A, stack *stack_B, stack *stack_C, int towerSize);
/* tower of hanoi solution */

int	main(void)
{
	int	towerSize;
	stack	*stack_A, *stack_B, *stack_C;
	bool	flag = true;

	stack_A = init_return();
	if (!init(stack_A))
	{
		printf("\nStick-A isn't mallocated.");
		flag = false;
	}

	stack_B = init_return();
	if (!init(stack_B))
	{
		printf("\nStick-B isn't mallocated.");
		flag = false;
	}

	stack_C = init_return();
	if (!init(stack_C))
	{
		printf("\nStick-C isn't mallocated.");
		flag = false;
	}

	printf("\nEnter the Tower Size: ");
	scanf("%d", &towerSize);

	towerOfHanoi(stack_A, stack_B, stack_C, towerSize);

	printf("\n");

	deleteStack(stack_A);
	deleteStack(stack_B);
	deleteStack(stack_C);
	return (0);
}

/**
 * @brief Iterative Tower of Hanoi Solution
 * 
 * @param stack_A 
 * @param stack_B 
 * @param stack_C 
 * @param towerSize 
 */
void	towerOfHanoi(stack *stack_A, stack *stack_B, stack *stack_C, int towerSize)
{
	stack	**stacks = (stack **)calloc(3, sizeof(stack*));
	int	isSizeOdd = towerSize & 1;
	size_t	i, j, buff;

	stacks[0] = stack_A;
	stacks[1] = stack_B;
	stacks[2] = stack_C;

	for (i = towerSize; i > 0 ; i--)
		push(stack_A, i);

	/* left shifting for power operation by 2 */
	for (i = 1; i < (1 << towerSize); i++)
	{
		buff = i;
		j = 1;

		/* bitwise and for number is odd or not */
		while (!(buff & 1))
		{
			buff >>= 1;
			j++;
		}
		moveDisk(stacks, j, isSizeOdd);
	}	
}

/**
 * @brief Move disks
 * 
 * @param stacks 
 * @param disk 
 * @param isSizeOdd 
 */
void	moveDisk(stack **stacks, int disk, int isSizeOdd)
{
	int	buff, i;
	bool	isPlaced = false;

	for (i = 0; i < 3 && !isPlaced; i++)
	{
		buff = pop(stacks[i]);

		if (buff == disk)
		{
			/* my brute force algorithm */
			if (((disk & 1) && isSizeOdd) || (!(disk & 1) && !isSizeOdd))
			{
				push(stacks[(i + 2) % 3], buff);
				printf("\nMove the disk %d from '%d' to '%d'", disk, i + 1, (i + 2) % 3 + 1);
			}
			else
			{
				push(stacks[(i + 1) % 3], buff);
				printf("\nMove the disk %d from '%d' to '%d'", disk, i + 1, (i + 1) % 3 + 1);
			}
			isPlaced = true;
		}
		else if (buff == -1);
		else
			push(stacks[i], buff);
	}
}

/**
 * @brief initializes stack
 * 
 * @return stack* 
 */
stack	*init_return()
{
	stack	*newStack = NULL;
	newStack = (stack *)malloc(sizeof(stack));

	newStack->array = NULL;
	newStack->currentsize = 0;
	newStack->maxsize = 0;

	return (newStack);
}

/**
 * @brief Return 1 if initialization is successful, otherwise 0
 * 
 * @param s 
 * @return bool 
 */
int	init(stack *s)
{
	bool	flag = true;
	if (s == NULL)
		flag = false;

	return (flag);
}

/**
 * @brief pop function for stack
 * 
 * @param s 
 * @return int 
 */
int	pop(stack *s)
{
	int	result;

	if (s->currentsize >= 1)
	{
		result = s->array[s->currentsize - 1];

		(s->currentsize)--;

		/* shrink */
		if (s->maxsize - s->currentsize > 9)
			(s->maxsize) -= STACK_BLOCK_SIZE;

		return (result);
	}

	return (-1);
}

/**
 * @brief push function for stack
 * 
 * @param s 
 * @param d 
 * @return int 
 */
int	push(stack *s, int d)
{
	if (s->maxsize - s->currentsize < 1)
	{
		(s->maxsize) += STACK_BLOCK_SIZE;
		int	*resizeArray = (int *)calloc(s->maxsize, sizeof(int));

		for (int i = 0; i < s->currentsize; i++)
			resizeArray[i] = s->array[i];

		resizeArray[(s->currentsize)++] = d;

		s->array = resizeArray;
	}
	else
		s->array[(s->currentsize)++] = d;

	return (true);
}

/**
 * @brief deletes stack
 * 
 * @param s 
 */
void	deleteStack(stack *s)
{
	if (s->array != NULL)
		free(s->array);
	
	if (s != NULL)
		free(s);
}