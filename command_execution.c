#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * command_sanitizer - makes splits the command, calls the path_command
 * and also checks if it is an inbuild command
 * @cmd: the command
 * @times_invoked: the times the execute command has been invoked for error
 * handling
 * Return: an array of the command splited or null if it was invalid
 */
char **command_sanitizer(char *cmd, int times_invoked)
{
	char *temp;
	int status;
	/* tokenize the command */
	char **command = split_string(cmd);
	/* check if its not a a path */
	if (command[0] && command[0][0] != '/' && command[0][0] != '.')
	{
		temp = command[0];/* get its path */
		command[0] = path_command(command[0]);
		if (command[0][0] != '/')/*if path command ddnt return a path */
		{/* check if its an inbuilt cmd */
			status = execute_special_command(command);
			if (!status)
				print_error(command[0], times_invoked);
			else if (status > 9)
			{
				free_char_array(command);
				free(cmd);
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
			return (NULL);
		}
		else
			free(temp);
	}
	else if (!command[0])/*split _string returned NULL */
	{
		free_char_array(command);
		return (NULL);
	}
	return (command);
}

/**
 * execute - executes a command passed to it
 * @str_command: a string containing a raw command
 */
void execute(char *str_command)
{
	static int times_invoked = 1;
	pid_t child;
	char **command = command_sanitizer(str_command, times_invoked);
	struct stat st;

	if (command && command[0] && stat(command[0], &st) == 0)
	{
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
			free_char_array(command);
		}
	}
	else if (command)
		print_error(command[0], times_invoked);

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
