#include "main.h"

/**
 * _getline - reads a line from the stream and stores in buffer
 * @buffer: is the buffer that stores the line
 * @len: is the size of bufffer
 * @stream: is the the source of line
 *
 * Return: number of characters read or -1 on failure
 */
ssize_t _getline(char **buffer, size_t *len, FILE *stream)
{
	size_t c, i = 0;
	char *temp;

	if (!buffer || !len || !stream)
		return (-1);
	*len = 120;
	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * (*len));
		if (!*buffer)
			return (-1);
	}

	while ((read(STDIN_FILENO, &c, 1)) != -1)
	{
		(*buffer)[i] = c;
		if (c == '\n')
		{
			break;
		}
		if (i == ((*len) - 1))
		{
			*len += 1;
			temp = _realloc(*buffer, sizeof(char) * (*len), sizeof(char) * (*len));
			if (temp == NULL)
				return (-1);
			*buffer = temp;
		}
		i++;
	}
	if (i == 0)
		return (-1);

	(*buffer)[i] = '\0';

	return (i);
}

#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocated memory
 * @ptr: is the pointer to previous allocated with malloc.
 * @old_size: is size in bytes of ptr.
 * @new_size: is the new size, in bytes of the new memory block
 *
 * Return: pointer to new memory or NULL if fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *ptr1, *ptrnew;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);

		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	ptrnew = malloc(new_size);
	ptr1 = ptr;

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptrnew[i] = ptr1[1];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptrnew[i] = ptr1[1];
	}
	free(ptr);
	return (ptrnew);
}
