#include "main.h"

/**
 * delim_checker - checks the occurence of the first delimiter
 * @str: the string to check
 * @delim: the delimiter
 *
 * Return: the first index of the occurrence of the first character in the delim
 */
int delim_checker(char *str, char *delim)
{
	int x;
	int delim_index = -1;
	int index;
	for (x = 0; x < delim[x]; x++)
	{
		index = _strchr(str, delim[x]);
		if (index < delim_index && delim_index != -1)
			delim_index = index;
		else if (delim_index == -1)
			delim_index = index;
	}

	return (delim_index);
}

/**
 * _strtok - emulates the library strtok
 * @str: the string to split
 * @delim: the delimiter to use
 *
 * Return: a pointer to the splitted string
 */
char *_strtok(char *str, char *delim)
{
	static char *str_store = NULL;
	static int hist_ind = -1;
	int delim_ind, len, x, y;

	if (str)
		str_store = str;
	else
	{
		len = (int)_strlen(str_store);
		if (hist_ind == len - 1)
			return (NULL);
		else
			str_store = str_store + (hist_ind + 1);
	}

	for (x = 0; str_store; x++)
	{
		for (y = 0; delim[y]; y++)
			if (delim[y] != str_store[x])
		       		goto updater;
	}
	if (str_store[x] == '\0')
		return (NULL);
updater:
	str_store = str_store + x;
	len = (int)_strlen(str_store);
	if (len == 0)
		return (NULL);

	delim_ind = delim_checker(str_store, delim);

	if (delim_ind != -1)
	{
		str_store[delim_ind] = '\0';
		hist_ind = delim_ind + 1;
	}
	else
		hist_ind = len - 1;

	return (str_store);
}
