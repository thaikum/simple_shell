#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * non_interactive - executes the non interactive part of shell
 *
 * Return: nothing.
 */
void non_interactive(void)
{
	size_t n;
	char *buffer = NULL;

	while (getline(&buffer, &n, stdin) > 0)
	{
		/* execute function calls the split string function*/
		command_broker(buffer);
		free(buffer);
	}
	free_environ();
}

/**
 * interactive - keeps on prompting the user to enter a command
 */
void interactive(void)
{
	char *command;
	size_t command_len;

	while (1)
	{
		print("$ ");
		command = malloc(10 * sizeof(char));
		command_len = 10;

		if (getline(&command, &command_len, stdin) != EOF)
		{
			command_broker(command);
			free(command);
		}
		else
		{
			free(command);
			/*free_environ();*/
			print("\n");
			exit(0);
		}
	}
	free_environ();
}
