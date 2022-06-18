#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/**
 * @brief Create a database object
 * 
 * @param name 
 * @return database* 
 */
database	*create_database(char *name)
{
	database	*newDatabase = (database *)malloc(sizeof(database));

	newDatabase->tList = NULL;
	newDatabase->n = 0;
	newDatabase->name = (char *)calloc(30, sizeof(char));
	strcpy(newDatabase->name, name);

	return (newDatabase);
}

/**
 * @brief showing tables
 * 
 * @param d 
 */
void	show_table(database *d)
{
	tables	*nextPtr = NULL;

	if (d != NULL)
	{
		printf("-----------------------------\n"
			"Tables in %s database\n"
			"-----------------------------\n", d->name);
		nextPtr = d->tList;
		while (nextPtr != NULL)
		{
			printf("%s\n", nextPtr->t->tableName);

			nextPtr = nextPtr->next;
		}
		printf("-----------------------------\n");
	}
	else
		printf("ERROR: NULL Pointer Exception.\n");
}

/**
 * @brief table descriptions
 * 
 * @param d 
 * @param name 
 */
void	desc_table(database *d, char *name)
{
	tables	*nextPtr = NULL;

	if (d != NULL)
	{
		nextPtr = d->tList;
		while (nextPtr != NULL && strcmp(nextPtr->t->tableName, name) != 0)
			nextPtr = nextPtr->next;

		if (nextPtr != NULL)
		{
			printf("---------------------------------------\n"
				"Field\tType\tNull\tKey\n"
				"---------------------------------------\n");

			for (int i = 0; nextPtr != NULL && i < nextPtr->t->n; i++)
			{
				printf("%s\t%s\t", nextPtr->t->field[i], nextPtr->t->type[i]);

				if (nextPtr->t->isNull[i])
					printf("YES\t");
				else
					printf("NO\t");

				if (nextPtr->t->isKey[i])
					printf("YES\n");
				else
					printf("\n");
			}
			printf("---------------------------------------\n");
		}
		else
			printf("ERROR: No Such Element Exception.\n");
	}
	else
		printf("ERROR: NULL Pointer Exception.\n");
}

/**
 * @brief inserting a table
 * 
 * @param d 
 * @param t 
 */
void	insert_table(database *d, table *t)
{
	tables	*nextPtr = NULL;

	if (d != NULL)
	{
		nextPtr = d->tList;
		while (nextPtr !=NULL)
			nextPtr = nextPtr->next;

		nextPtr = (tables *)malloc(sizeof(tables));
		nextPtr->t = t;
		nextPtr->next = NULL;
		(d->n)++;
	}
	else
		printf("ERROR: NULL Pointer Exception.\n");
}

/**
 * @brief removing a table
 * 
 * @param d 
 * @param name 
 */
void	remove_table(database *d, char *name)
{
	tables	*parentPtr = NULL, *buff = NULL;
	if (d != NULL)
	{
		parentPtr = (tables *)malloc(sizeof(tables));
		buff = parentPtr;
		parentPtr->next = d->tList;

		while (parentPtr->next != NULL && strcmp(parentPtr->next->t->tableName, name) != 0)
			parentPtr->next = parentPtr->next->next;

		if (parentPtr->next != NULL)
		{
			parentPtr = parentPtr->next->next;

			if (parentPtr == buff)
				parentPtr->next = NULL;
			else
				parentPtr = parentPtr->next->next;
			(d->n)--;
		}
		else
			printf("ERROR: No Such Element Exception.\n");
	}
	else
		printf("ERROR: NULL Pointer Exception.\n");
}

/**
 * @brief inserting a primary key
 * 
 * @param d 
 * @param name 
 * @param field 
 */
void	insert_key(database *d, char *name, char *field)
{
	tables	*nextPtr = NULL;
	bool	isFind = false;

	if (d != NULL)
	{
		nextPtr = d->tList;
		while (nextPtr != NULL && strcmp(nextPtr->t->tableName, name) != 0)
			nextPtr = nextPtr->next;

		if (nextPtr != NULL)
		{
			for (int i = 0; i < nextPtr->t->n && !isFind; i++)
			{
				if (strcmp(nextPtr->t->field[i], field) == 0)
				{
					nextPtr->t->isKey[i] = true;
					isFind = true;
				}
				else
					printf("ERROR: No Such Element Exception.(field)\n");
			}
		}
		else
			printf("ERROR: No Such Element Exception.(table)\n");
	}
	else
		printf("ERROR: NULL Pointer Exception.\n");
}

/**
 * @brief Create a database object from bin file
 * 
 * @param fileName 
 * @return database* 
 */
database	*createFromBinFile(char	*fileName)
{
	FILE	*binFile = NULL;
	database	*db = NULL;
	tables	*nextPtr = NULL;
	int	i, j;

	db = create_database("fileDB");
	binFile = fopen(fileName, "rb");
	if (binFile != NULL)
	{
		db->name = (char *)calloc(30, sizeof(char));
		fread(db->name, sizeof(char) * 30, 1, binFile);
		fread(&(db->n), sizeof(int), 1, binFile);

		if (db->n != 0)
		{
			db->tList = (tables *)malloc(sizeof(tables));
			nextPtr = db->tList;
			
			for (i = 0; i < db->n; i++)
			{
				fread(nextPtr->t->tableName, sizeof(char) * 30, 1, binFile);
				fread(&(nextPtr->t->n), sizeof(int), 1, binFile);
				
				for (j = 0; j < nextPtr->t->n; j++)
				{
					fread(nextPtr->t->field[j], sizeof(char) * 30, 1, binFile);
					fread(nextPtr->t->type[j], sizeof(char) * 30, 1, binFile);
					fread(&(nextPtr->t->isKey[j]), sizeof(bool), 1, binFile);
					fread(&(nextPtr->t->isNull[j]), sizeof(bool), 1, binFile);
				}

				if (i <= db->n)
					nextPtr->next = (tables *)malloc(sizeof(tables));
				else
					nextPtr->next = NULL;
				nextPtr = nextPtr->next;
			}
		}
	}
	else
		printf("NULL Pointer Exception: Wrong file name.\n");
}

/**
 * @brief writing db to bin file
 * 
 * @param fileName 
 * @param d 
 * @return int 
 */
int	writeToBinFile(char *fileName, database *d)
{
	FILE	*binFile = NULL;
	tables	*nextPtr = NULL;
	int	i;

	if (d != NULL)
	{
		binFile = fopen(fileName, "wb");

		if (binFile != NULL)
		{
			fwrite(d->name, sizeof(char) * 30, 1, binFile);
			fwrite(&(d->n), sizeof(int), 1, binFile);
			
			nextPtr = d->tList;
			while (nextPtr != NULL)
			{
				fwrite(nextPtr->t->tableName, sizeof(char) * 30, 1, binFile);
				fwrite(&(nextPtr->t->n), sizeof(int), 1, binFile);

				for (i = 0; i < nextPtr->t->n; i++)
				{
					fwrite(nextPtr->t->field[i], sizeof(char) * 30, 1, binFile);
					fwrite(nextPtr->t->type[i], sizeof(char) * 30, 1, binFile);
					fwrite(&(nextPtr->t->isKey[i]), sizeof(bool), 1, binFile);
					fwrite(&(nextPtr->t->isNull[i]), sizeof(bool), 1, binFile);
				}
				nextPtr = nextPtr->next;
			}
		}
		else
		{
			printf("NULL pointer Exception.\n");
			return (-1);
		}

		fclose(binFile);
	}
	return (0);
}

/**
 * @brief cleaning buffer
 * 
 */
void	fflush_()
{
	while (getchar() != '\n');
}
