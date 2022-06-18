#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief linked list node
 * 
 */
typedef struct Node {
	char	bookname[30];
	char	author[30];
	int	year;
	struct Node	*next;
} Node;

/**
 * @brief insert
 * 
 * @param root 
 * @param bookname 
 * @param author 
 * @param year 
 * @return Node* 
 */
Node*	insert_node(Node *root, char *bookname, char *author, int year)
{
	Node	*head = root;
	Node	*newNode;
	Node	*parent;

	if (head == NULL)
	{
		head = (Node *)malloc(sizeof(Node));

		head->next = NULL;
		strcpy(head->author, author);
		strcpy(head->bookname, bookname);
		head->year = year;

		return (head);
	}

	while (head->next != NULL && year > head->year)
	{
		parent = head;
		head = head->next;
	}

	newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	strcpy(newNode->bookname, bookname);
	strcpy(newNode->author, author);
	newNode->year = year;

	if (root == head)
	{
		newNode->next = head;

		return (newNode);
	}

	parent->next = newNode;
	newNode->next = head;

	return (root);
}

/**
 * @brief read file function
 * 
 * @return Node* 
 */
Node*	read_file()
{
	FILE	*ptr = fopen("source.txt", "r");

	char	bookname[30];
	char	author[30];
	int	year;

	Node	*root = NULL;

	while (!feof(ptr))
	{
		fscanf(ptr, "%s %s %d", bookname, author, &year);
		// printf("%s %s %d\n", bookname, author, year);
		root = insert_node(root, bookname, author, year);
	}

	return (root);
}

/**
 * @brief printing linked list
 * 
 * @param root 
 * @return Node* 
 */
Node*	print_nodes(Node *root)
{
	Node*	head = root;
	while (head != NULL)
	{
		printf("%s\t%s\t%d\n", head->bookname, head->author, head->year);
		head = head->next;
	}
}

/**
 * @brief deleting nodes
 * 
 * @param root 
 * @param bookname 
 * @return Node* 
 */
Node	*delete_node(Node *root, char *bookname)
{
	Node	*head = root;

	while (head->next != NULL && strcmp(head->next->bookname, bookname) != 0)
	{
		head = head->next;
	}

	if (head->next == NULL && strcmp(head->bookname, bookname) != 0)
	{
		return (root->next);
	}

	if (strcmp(head->next->bookname, bookname) == 0)
	{
		head->next = head->next->next;
	}

	return (root);
}

int	main(void)
{
	Node	*root = NULL;

	root = read_file();

	root = delete_node(root, "MrsDalloway");
	root = delete_node(root, "MobyDick");
	root = delete_node(root, "EastOfEden");

	print_nodes(root);

	return (0);
}