#include "main.h"

/**
 * _strtok - tokenizes a string into tokens
 * @str: is the string to be tokenized
 * @delim: is th string containing delimitor for tokeizing
 *
 * Return: a  pointer to the next token, or NULL if there are no more tokens.
 */

char *_strtok(char *str, char *delim)
{
	static char *backup;
	char *token;

	if (str == NULL)
		str = backup;
	if (str == NULL)
		return (NULL);

	while (1)
	{
		if (isdelim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}

	token = str;
	while (*str)
	{
		if (isdelim(*str, delim))
		{
			*str = '\0';
			backup = str + 1;
			return (token);
		}
		str++;
	}
	if (*str == '\0')
	{
		backup = str;
		return (token);
	}
	return (NULL);
}

/**
 * isdelim - check if a character matches the delimintor provided.
 * @c : is the chararcter to check
 * @delim: is the string containing the delimitor.
 *
 * Return: 1 if sucessful  or 0 if not successful.
 */
int isdelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
