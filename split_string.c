#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * split_string - tokenizes a string into words
 * @str: is the string to be split
 *
 * Return: a pointer to an array of string or NULL;
 */
char **split_string(char *str)
{
	int i, tokennum = 0;
	char *dup = NULL, *token = NULL, *token1 = NULL, *delim = " \n\t";
	char **token_str = NULL;

	dup = _strdup(str);

	token = strtok(dup, delim);
	while (token != NULL)
	{
		tokennum++;
		token = strtok(NULL, delim);
	}

	token_str = malloc(sizeof(char *) * (tokennum + 1));
	if (token_str == NULL)
	{
		free(dup);
		return (NULL);
	}

	token1 = strtok(str, delim);
	for (i = 0; token1 != NULL; i++)
	{
		token_str[i] = malloc(sizeof(char) * (_strlen(token1) + 1));
		if (token_str[i] == NULL)
		{
			free(dup);
			return (NULL);
		}

		_strcpy(token_str[i], token1);
		token1 = strtok(NULL, delim);
	}
	token_str[i] = NULL;
	free(dup);
	return (token_str);
}
