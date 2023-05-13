#include <stdlib.h>
#include <stddef.h>

/**
 * free_char_array - frees an array of strings which is null terminated
 * @char_array: an array of strings to free
 */
void free_char_array(char **char_array)
{
	int x = 0;

	for (; char_array && char_array[x]; x++)
	{
		free(char_array[x]);
		char_array[x] = NULL;
	}

	free(char_array);
	char_array = NULL;
}
