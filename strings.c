#include "main.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * _strlen - calculates the length of a string
 * @str: the string to calculate its length
 *
 * Return: the length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str && str[i])
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

	if (str == NULL)
		return (NULL);

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

/**
 * str_concat - concatenates two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: concatenated string
 */
char *str_concat(char *str1, char *str2)
{
	size_t l1 = _strlen(str1);
	size_t l2 = _strlen(str2);
	size_t counter, x;
	char *result = malloc((l1 + l2 + 1) * sizeof(char));

	if (!result)
		exit(12);

	for (counter = 0; str1 && counter < l1; counter++)
		result[counter] = str1[counter];

	for (x = 0; str2 && x < l2; x++, counter++)
		result[counter] = str2[x];

	result[counter] = '\0';

	return (result);
}
/**
 * _strcmp - compares two string if they are equal
 * @s1: is the first string
 * @s2: is the second string
 *
 * Return: 0 if equal or the difference in ASCII value
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (*s1 - *s2);
}
