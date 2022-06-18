#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define bool int

/**
 * @brief my book definition
 * 
 */
typedef struct {
	int	book_id;
	int	year;
	char	title[100];
	char	author[100];
	char	subject[100];
} Book;


/**
 * @brief to add books to the books dynamicly array
 * 
 * @param books 
 * @param n 
 * @return Book* 
 */
Book	*addBook(Book *books, int *n)
{
	Book *resizeBooks = (Book *)calloc(++(*n), sizeof(Book));

	/* to transfer values to the new array with new size */
	for (int i = 0; i < (*n) - 1; i++)
	{
		strcpy(resizeBooks[i].author, books[i].author);
		strcpy(resizeBooks[i].subject, books[i].subject);
		strcpy(resizeBooks[i].title, books[i].title);
		resizeBooks[i].year = books[i].year;
		resizeBooks[i].book_id = books[i].book_id;
	}

	printf("***********************\n"
		"SUBMENU\n"
		"Please enter book title = ");
	
	fflush(stdin);
	scanf(" %[^\n]%*c", resizeBooks[(*n) - 1].title);
	printf("Please enter book author = ");
	fflush(stdin);
	scanf(" %[^\n]%*c", resizeBooks[(*n) - 1].author);
	printf("Please enter book subject = ");
	fflush(stdin);
	scanf(" %[^\n]%*c", resizeBooks[(*n) - 1].subject);
	printf("Please enter book year = ");
	fflush(stdin);
	scanf("%d", &resizeBooks[(*n) - 1].year);
	
	/* book id */
	resizeBooks[(*n) - 1].book_id = (*n);

	printf("\n**********************\n");

	return (resizeBooks);
}

void	print_books(Book *books, int n)
{
	printf("\nList of Books\n");
	printf("\n**********************\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d. Book;\n", i + 1);
		printf("Title => %s\n", books[i].title);
		printf("Author => %s\n", books[i].author);
		printf("Subject => %s\n", books[i].subject);
		printf("Year => %d\n", books[i].year);

		printf("\n**********************\n");
	}
}

/**
 * @brief to list books in the books struct
 * 
 * @param books 
 * @param n 
 */
void	listBooks(Book *books, int n)
{
	int	selection, i;
	bool	flag = false;
	char	getByString[100];
	char	temp_s[100];
	int	temp_i;

	do {
		printf("SUBMENU\n"
			"\t1. Get by Title\n"
			"\t2. Get by Author\n"
			"\t3. Get by Subject\n"
			"\t4. Sorted List All Books (DESC)\n"
			"\t5. List All Books\n"
			"\t6. EXIT SUBMENU\n"
			"\nChoose = ");
		scanf("%d", &selection);

		switch (selection)
		{
			/**
			 * @brief get by title
			 * 
			 */
			case 1:
				printf("\n**********************\n");
				printf("Enter a books title = ");
				fflush(stdin);
				scanf(" %[^\n]%*c", getByString);

				for (i = 0; i < n && !flag; i++)
				{
					if (strcmp(getByString, books[i].title) == 0)
						flag = true;
				}

				if (flag)
				{
					printf("Book found\n");
					printf("Title => %s\n", books[i - 1].title);
					printf("Author => %s\n", books[i - 1].author);
					printf("Subject => %s\n", books[i - 1].subject);
					printf("Year => %d\n", books[i - 1].year);
				}
				else
					printf("Book not found\n");
				printf("\n**********************\n");
				flag = false;
				break;

			/**
			 * @brief get by author
			 * 
			 */
			case 2:
				printf("\n**********************\n");
				printf("Enter a books Author = ");
				fflush(stdin);
				scanf(" %[^\n]%*c", getByString);

				for (i = 0; i < n && !flag; i++)
				{
					if (strcmp(getByString, books[i].author) == 0)
						flag = true;
				}

				if (flag)
				{
					printf("Book found\n");
					printf("Title => %s\n", books[i - 1].title);
					printf("Author => %s\n", books[i - 1].author);
					printf("Subject => %s\n", books[i - 1].subject);
					printf("Year => %d\n", books[i - 1].year);
				}
				else
					printf("Book not found\n");
				printf("\n**********************\n");
				flag = false;
				break;

			/**
			 * @brief get by subject
			 * 
			 */
			case 3:
				printf("\n**********************\n");
				printf("Enter a books Subject = ");
				fflush(stdin);
				scanf(" %[^\n]%*c", getByString);

				for (i = 0; i < n && !flag; i++)
				{
					if (strcmp(getByString, books[i].subject) == 0)
						flag = true;
				}

				if (flag)
				{
					printf("Book found\n");
					printf("Title => %s\n", books[i - 1].title);
					printf("Author => %s\n", books[i - 1].author);
					printf("Subject => %s\n", books[i - 1].subject);
					printf("Year => %d\n", books[i - 1].year);
				}
				else
					printf("Book not found\n");
				printf("\n**********************\n");
				flag = false;
				break;

			/**
			 * @brief Sorted List by Year (DESC)
			 * 
			 */
			case 4:
				for (i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (books[i].year > books[j].year)
						{
							temp_i = books[i].year;
							books[i].year = books[j].year;
							books[j].year = temp_i;

							temp_i = books[i].book_id;
							books[i].book_id = books[j].book_id;
							books[j].book_id = temp_i;

							strcpy(temp_s, books[i].author);
							strcpy(books[i].author, books[j].author);
							strcpy(books[j].author, temp_s);

							strcpy(temp_s, books[i].subject);
							strcpy(books[i].subject, books[j].subject);
							strcpy(books[j].subject, temp_s);

							strcpy(temp_s, books[i].title);
							strcpy(books[i].title, books[j].title);
							strcpy(books[j].title, temp_s);
						}

				print_books(books, n);
				break;

			case 5:
				for (i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (books[i].book_id < books[j].book_id)
						{
							temp_i = books[i].year;
							books[i].year = books[j].year;
							books[j].year = temp_i;

							temp_i = books[i].book_id;
							books[i].book_id = books[j].book_id;
							books[j].book_id = temp_i;

							strcpy(temp_s, books[i].author);
							strcpy(books[i].author, books[j].author);
							strcpy(books[j].author, temp_s);

							strcpy(temp_s, books[i].subject);
							strcpy(books[i].subject, books[j].subject);
							strcpy(books[j].subject, temp_s);

							strcpy(temp_s, books[i].title);
							strcpy(books[i].title, books[j].title);
							strcpy(books[j].title, temp_s);
						}

				print_books(books, n);
				break;
			
			default:
				break;
		}

	} while (selection != 6);
}

int	main(void)
{
	int	selection, n = 0;
	Book *books;

	do {
		printf("Menu\n"
			"\t1. Add New Book\n"
			"\t2. List Books\n"
			"\t3. EXIT\n"
			"\nChoose = ");
		scanf("%d", &selection);
		
		switch (selection)
		{
			case 1:
				books = addBook(books, &n);
				break;

			case 2:
				listBooks(books, n);
				break;

			default:
				break;
		}

	} while (selection != 3);

	free(books);
	return (0);
}