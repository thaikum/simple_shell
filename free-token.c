#include "main.h"

/**
 * free_token - frees all the memory allocated in toknenization
 * @token: pointer to array of pointers
 *
 * Return: nothing
 */
void free_token(char **token)
{
	int i;

	for (i = 0; token[i] != NULL; i++)
	{
		free(token[i]);
		token[i] = NULL;
	}
	free(token);
}
