#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * execute - executes a command passed to it
 * @str_command: a string containing a raw command
 */
void execute(char *str_command)
{
	static int times_invoked = 1;
	pid_t child;
	char *temp;
	int status;
	char **command = split_string(str_command);

	if (command[0])
	{
		if (command[0][0] != '/' && command[-0][0] != '.')
		{
			temp = command[0];
			command[0] = path_command(command[0]);

			if (command[0][0] != '/')
			{
				status = execute_special_command(command);
				if (!status)
					print_error(command[0], times_invoked);
				else if (status > 9)
				{
					free_char_array(command);
					free(str_command);
					exit(status - 10);
				}
				else if (status == 9)
				{
					temp = str_concat("Illegal number: ",
							  command[1]);
					custom_error(command[0], temp,
						     times_invoked);
					free(temp);
				}
				free_char_array(command);
				free(str_command);

				times_invoked++;

				return;
			}
			else
				free(temp);

		}
		child = fork();
		if (child == 0)
		{
			execve(command[0], command, __environ);
			print_error(command[0], times_invoked);
		}
		else
		{
			wait(NULL);
			fflush(stdout);
		}
	}
	free_char_array(command);
	free(str_command);

	times_invoked++;
}

/**
 * path_command - converts a simple command e.g ls to /bin/ls
 * @command: the command to convert
 *
 * Return: the converted command
 */
char *path_command(char *command)
{
	char *path = _strdup(getenv("PATH"));
	char *dir;
	char *sub1, *sub2;
	struct stat st;

	if (path)
	{
		for (dir = strtok(path, ":"); dir; dir = strtok(NULL, ":"))
		{
			sub1 = str_concat(dir, "/");
			sub2 = str_concat(sub1, command);

			free(sub1);
			sub1 = NULL;

			if (stat(sub2, &st) == 0)
			{
				free(path);
				return (sub2);
			}
			free(sub2);
			sub2 = NULL;
		}
		free(path);
		return (command);
	}
	else
		exit(98);
}
