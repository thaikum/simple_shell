#include "main.h"

char **split_string(char *str);
int _strlen(char *str);
char *_strcpy(char *s1, char *s2);
char *_strdup(char *str);

/**
 * split_string - tokenizes a string into words
 * @str: is the string to be split
 *
 * Return: a pointer to an array of string or NULL;
 */
char **split_string(char *str)
{
	int i, tokennum = 0;
	char *dup = NULL, *token = NULL, *token1 = NULL, *delim = " \n\t\r";
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
/**
 * _strlen - calculates the length of a string
 * @str: the string to calculate its length
 *
 * Return: the length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}

	return (i);
}
/**
 * _strcpy - copies one string to another.
 * @s1: is the destination string
 * @s2: is the source string
 *
 * Return: destination sstring
 */
char *_strcpy(char *s1, char *s2)
{
	char  *dest;

	dest = s1;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}

	*s1 = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: is the string
 *
 * Return: a the duplicated string
 */
char *_strdup(char *str)
{
	char *dup = NULL, *dup_offset;
	int len;

	len = _strlen(str);

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		return (NULL);
	}

	dup_offset = dup;

	while (*str)
	{
		*dup_offset = *str;
		dup_offset++;
		str++;
	}
	*dup_offset = '\0';

	return (dup);
}
