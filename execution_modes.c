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
	char **command;

	while (getline(&buffer, &n, stdin) > 0)
	{
		if ((_strcmp(buffer, "\n") == 0) || (_strcmp(buffer, "\0")))
			continue;
		command = split_string(buffer);
		execute(command);
		free(buffer);
		free_char_array(command);
	}
}

/**
 * interactive - keeps on prompting the user to enter a command
 */
void interactive(void)
{
	char *command;
	char **splitted_command;
	size_t command_len;

	while (1)
	{
		print("$ ");
		command = malloc(10 * sizeof(char));
		command_len = 10;

		if (getline(&command, &command_len, stdin) != EOF)
		{
			splitted_command = split_string(command);
			execute(splitted_command);
			free_char_array(splitted_command);
			free(command);
		}
		else
		{
			free(command);
			print("\n");
			exit(0);
		}
	}
}
