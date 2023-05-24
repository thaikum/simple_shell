#include "main.h"

/**
 * _strchr - finds the first occurrence of a given character in given string
 * @str: the string to check
 * @ch: the character to test for
 *
 * Return: the first index where the character apears or -1 if it doesn't
 */
int _strchr(char *str, char ch)
{
	int x;

	for (x = 0; str && str[x]; x++)
		if (str[x] == ch)
			return (x);

	return (-1);
}

/**
 * _getline - reads characters from a line
 * @buffer: thr characters read are stored in the buffer
 * @len: number of bytes stored in buffer
 * @stream: is the source of the text to be read.
 *
 * Return: number if bytes read or -1 on failure to read a line
 */
ssize_t _getline(char **buffer, size_t *len, FILE *stream)
{
	static char char_replaced = '\0';
	int last_index = -1;
	ssize_t nread;
	int endline_pos;
	char *temp;

	if (!buffer || !len || !stream)
		return (-1);

	*len = 120;

	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * 1024);
		if (*buffer == NULL)
			return (-1);
	}

	if (last_index != -1)
	{
		(*buffer)[last_index + 1] = char_replaced;
		temp = _strdup((*buffer) + last_index + 1);
		free(*buffer);
		(*buffer) = temp;

		endline_pos = _strchr(*buffer, '\n');
	endline_handler:
		if (endline_pos != -1 && endline_pos < _strlen(*buffer) - 1)
		{
			printf("found previous data\n");
			char_replaced = (*buffer)[endline_pos];
			last_index = endline_pos;
			(*buffer)[endline_pos + 1] = '\0';
			return (endline_pos);
		}
		else
		{
			char_replaced = '\0';
			last_index = -1;
			return (_strlen(*buffer));
		}
	}

	while ((nread = read(fileno(stream), *buffer, 1024)) > 0)
	{
		endline_pos = _strchr(*buffer, '\n');
		if (endline_pos != -1 && endline_pos < _strlen(*buffer) - 1)
			goto endline_handler;

		if ((*buffer)[nread - 1] == '\n')
			return (nread);
		else
		{
			*len = *len * 2;
			*buffer = realloc(*buffer, *len);
			if (!*buffer)
				return (-1);
		}
	}

	return (nread);

}

