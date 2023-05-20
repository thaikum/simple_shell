#include "main.h"

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
	static ssize_t nread;

	if (!buffer || !len || !stream)
		return (-1);

	*len = 1024;

	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * 1024);
		if (*buffer == NULL)
			return (-1);
	}

	while ((nread = read(fileno(stream), *buffer, 1024)) > 0)
	{
		if ((*buffer)[nread - 1] == '\n')
			return (nread);
		if (nread >= (ssize_t)(*len - 1))
		{
			*len = *len * 2;
			*buffer = realloc(*buffer, *len);
			if (!*buffer)
				return (-1);
		}
	}
	return (nread);
}
