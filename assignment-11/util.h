#ifndef _UTIL_H_
#define _UTIL_H_

/**
 * @brief table structer
 * 
 * @param int n -> number of columns
 * @param char *tableName -> name of current 
 */
typedef struct table {
	char	**field;
	char	**type;
	bool	*isNull;
	bool	*isKey;
	char	*tableName;
	int	n;
} table;

/**
 * @brief tables linked list
 * 
 */
typedef struct tables {
	struct tables	*next;
	table	*t;
} tables;

/**
 * @brief db structer
 * 
 * @param tables tList
 * @param int n -> num of entries
 * @param char name -> db name
 * 
 */
typedef struct database {
	tables	*tList;
	int	n;
	char	*name;
} database;

database	*create_database(char *name);
void	show_table(database *d);
void	desc_table(database *d, char *name);
void	insert_table(database *d, table *t);
void	remove_table(database *d, char *name);
void	insert_key(database *d, char *name, char *field);
database	*createFromBinFile(char	*fileName);
int	writeToBinFile(char *fileName, database *d);
void	fflush_();

#endif /* _UTIL_H_ */