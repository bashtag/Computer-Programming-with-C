#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

int	main(void)
{
	database	*db = NULL;
	table	*t = NULL;
	int	selection = 0, creatingSel = 0, i;
	int	isYes = 2; /* for do-while loop */
	char	*name = (char *)calloc(30, sizeof(char));
	char	*field = (char *)calloc(30, sizeof(char));

	do {
		printf("\nWelcome to DataBase Manangement System\n"
			"\t1- Create\n"
			"\t2- Show Tables\n"
			"\t3- Describe Table\n"
			"\t4- Insert Table\n"
			"\t5- Remove Table\n"
			"\t6- Insert Primary Key\n"
			"\t7- Save DB\n"
			"\t0- Exit\n\n");
		scanf("%d", &selection);
		fflush_();

		switch (selection)
		{
			case 1:
				printf("Creating Database\n"
					"\t1- Create from a bin file\n"
					"\t2- Create a new Database\n");
				scanf("%d", &creatingSel);
				fflush_();

				switch (creatingSel)
				{
					case 1:
						printf("Give me the Binary File Name: ");
						scanf("%s", name);
						fflush_();
						db = createFromBinFile(name);
						break;

					case 2:
						printf("Give me a DataBase Name: ");
						scanf("%s", name);
						fflush_();
						db = create_database(name);
						break;
					
					default:
						break;
				}
				break;

			case 2:
				show_table(db);
				break;

			case 3:
				printf("Give me a table name for describing a table: ");
				scanf("%s", name);
				fflush_();
				desc_table(db, name);
				break;

			case 4:
				t = (table *)malloc(sizeof(table));
				t->n = 0;
				printf("Inserting a Table\n"
					"Give me the table name: ");
				scanf("%s", name);
				t->tableName = (char *)calloc(30, sizeof(char));
				strcpy(t->tableName, name);

				printf("Give me number of columns: ");
				scanf("%d", &(t->n));
				fflush_();

				t->field = (char **)calloc(t->n, sizeof(char *));
				t->type = (char **)calloc(t->n, sizeof(char *));
				t->isNull = (bool *)calloc(t->n, sizeof(bool));
				t->isKey = (bool *)calloc(t->n, sizeof(bool));

				for (i = 0; i < t->n; i++)
				{
					printf("%d. Column (field)\n", i + 1);
					printf("Give me field name: ");
					scanf("%s", name);
					fflush_();

					t->field[i] = (char *)calloc(30, sizeof(char));
					strcpy(t->field[i], name);

					printf("Give me type name: ");
					scanf("%s", name);
					fflush_();

					t->type[i] = (char *)calloc(30, sizeof(char));
					strcpy(t->type[i], name);

					do
					{
						printf("Is Field Null? (YES/NO 1/0): ");
						scanf("%d", &isYes);
						fflush_();
					} while (!(isYes == 1 || isYes == 0));
					t->isNull[i] = isYes;

					isYes = 2;
					do
					{
						printf("Is Field a Primary Key? (YES/NO 1/0): ");
						scanf("%d", &isYes);
						fflush_();
					} while (!(isYes == 1 || isYes == 0));
					t->isKey[i] = isYes;
				}
				insert_table(db, t);
				break;

			case 5:
				printf("Remove Table\n"
					"Give me a table name to remove: ");
				scanf("%s", name);
				fflush_();

				remove_table(db, name);
				break;

			case 6:
				printf("Insert Primary Key\n"
					"Give me a table name: ");
				scanf("%s", name);
				fflush_();

				printf("Give me a field name: ");
				printf("%s", field);
				fflush_();

				insert_key(db, name, field);
				break;

			case 7:
				printf("Save the Database to a Binary File\n"
					"Give me a new file name(ending with .bin): ");
				scanf("%s", name);

				writeToBinFile(name, db);
				break;

			default:
				break;
		}
	} while (selection);
	
	return (0);
}