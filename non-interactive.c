#include "main.h"

void non_interactive(void);
int _strcmp(char *s1, char *s2);
/**
 * non_interactive - executes the non interactive part of shell
 *
 * Return: nothing.
 */
void non_interactive(void)
{
	size_t n = 0;
	ssize_t nread;
	char *buffer = NULL;
	char **command;

	while ((nread = getline(&buffer, &n, stdin)) != -1)
	{
		if ((strcmp(buffer, "\n") == 0))
		{
			continue;
		}

		command = split_string(buffer);
		if (command == NULL)
		{
			free(buffer);
			printf("nothing");
			continue;
		}
		execute(command);
		free(buffer);
		free_token(command);
	}
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
