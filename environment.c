#include "main.h"

/**
 * set_environ - sets an environmental variable
 * @variable: the environmental variable
 * @value: the value
 */
void set_environ(char *variable, char *value)
{
	int res;
	int pos;
	char *temp;

	if (environ == NULL)
	{
		environ = (char **) malloc(sizeof(char *) * 2);
		if (!environ)
			return;
		else
		{
			set_value(&environ[0], value, variable);
			environ[1] = NULL;
			return;
		}
	}

	temp = search_value(value);
	if (temp)
	{
		set_value(&temp, value, variable);
	}
	else
	{
		res = char_char_len(environ);
		set_value(&environ[0], value, variable);
		realloc(environ, (res + 2) * sizeof(char *));
		environ[res + 1] = NULL;
	}
}
/**
 * char_char_len: finds the length of an array of character character pointer
 * @arr: the array to be tested
 *
 * Return: the lenght of the array
 */
int char_char_len(char **arr)
{
	int x = 0;

	for (; arr[x]; x++)
		;
	return (x);
}
/**
 * set_value - sets the value of an environmental variable
 * @variable: the variable to be set
 * @value: the value to alter
 * @environ_val: the environmental value pointer
 */
void set_value(char **environ_val, char *value, char *variable)
{
	char *temp;

	(*environ_val) = malloc((_strlen(variable) +
			     _strlen(value) + 2 * sizeof(char)));
	temp = str_concat(value, "=");
	*environ_val = str_concat(temp, variable);
	(*environ)[_strlen(variable) + _strlen(value) + 1] = '\0';
	free(temp);
}
/**
 * _strn_cmp - compares two strings if they are equal upto a certain length
 * @str1: the first string
 * @str2: the second string
 * @n: the number of characters to compare
 *
 * Return: 1 if they match or 0 if they dont
 */
int _strn_cmp(char *str1, char *str2, int n)
{
	int x = 0;

	for (; x < n && str1[x] && str2[x]; x++)
	{
		if (str1[x] != str2[x])
		    return (0);
	}

	if ( x == n)
		return (1);
	return (0);
}

/**
 * search_value - finds whether a value is present in the environ array
 * @value: the value to search
 *
 * Return: pointer to the value or null if not found
 */
char *search_value(char *value)
{
	int x;

	for (x = 0; environ[x]; x++)
		if (_strn_cmp(value, environ[x]), (int)_strlen(value))
			return (environ[x]);

	return (NULL);
}
