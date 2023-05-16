#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print - prints to the stdout
 * @str: the string to print
 */
void print(char *str)
{
	size_t len = _strlen(str);

	write(STDOUT_FILENO, str, len);
}

/**
 * print_e - prints on the stderr
 * @str: string to print
 */
void print_e(char *str)
{
	size_t len = _strlen(str);

	write(STDERR_FILENO, str, len);
}

/**
 * print_error - prints an error like that of sh
 * @command: the command that was inputed
 * @times_invoked: number of times commands have been run on the system
 */
void print_error(char *command, int times_invoked)
{
	char *sub1, *sub2, *sub3, *times_invoked_str;

	if (isatty(STDIN_FILENO) == 0)
	{
	sub1 = str_concat(program_invocation_name, ": ");
	times_invoked_str = int_to_str(times_invoked);
	sub2 = str_concat(sub1, times_invoked_str);
	sub3 = str_concat(sub2, ": ");
	free(sub1);
	sub1 = str_concat(sub3, command);

	perror(sub1);

	free(sub1);
	free(sub2);
	free(sub3);
	free(times_invoked_str);
	}

	else if (isatty(STDIN_FILENO))
	{
		sub1 = str_concat(program_invocation_name, ": ");
		sub2 = str_concat(sub1, command);

		perror(sub2);

		free(sub1);
		free(sub2);
	}
}

/**
 * custom_error - prints an error from the user
 * @command: command given
 * @times_invoked: times run
 * @error: the error message
 */
void custom_error(char *command, char *error, int times_invoked)
{
	char *times_str = int_to_str(times_invoked);

	print_e(program_invocation_name);
	print_e(": ");
	print_e(times_str);

	print_e(": ");
	print_e(command);

	print_e(": ");
	print_e(error);

	print_e("\n");
	free(times_str);
}
