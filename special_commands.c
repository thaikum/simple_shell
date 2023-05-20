#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_special_command - handles built-in comands (are not present in
 * /bin/ e.g cd, exit, etc.)
 * @args: an array of the command and its arguments
 *
 * Return: 1 if the command is a special function and 0 if not
 */
int execute_special_command(char **args)
{
	if (!_strcmp(args[0], "exit"))
	{
		return (exit_command(args[1]) + 10);
	}
	else if (!_strcmp(args[0], "cd"))
	{
		cd(args[1]);
		return (1);
	}
	else if (!_strcmp(args[0], "setenv"))
	{
		if (args[1] && args[2])
			set_environ(args[1], args[2]);
		return (1);
	}
	else if (!_strcmp(args[0], "unsetenv"))
	{
		unset_environ(args[1]);
		return (1);
	}
	else if (!_strcmp(args[0], "env"))
	{
		env();
		return (1);
	}
	return (0);
}

/**
 * exit_command - exits the shell
 * @status: the exit status
 *
 * Return: -1 if it fails or an exit code if it succeeds
 */
int exit_command(char *status)
{
	if (!status)
	{
		return (0);
	}
	else
	{
		if (is_valid_number(status))
			return (_atoi(status));

	return (-1);
	}
}
/**
 * cd - changes the directory
 * @path: the new dir
 */
void cd(char *path)
{
	char curdir[80], *k, *old_k, *cur_k, dir[80];
	int result;

	if (!path || !_strcmp(path, ""))
	{
		cur_k = getcwd(dir, 80);
		k = getenv("HOME");
		result = chdir(k);
		k = NULL;
	}
	else if (!_strcmp(path, "-"))
	{
		cur_k = getcwd(dir, 80);
		old_k = getenv("OLDPWD");
		result = chdir(old_k);
		k = getcwd(curdir, 80);

		setenv("PWD", k, 1);
		setenv("OLDPWD", cur_k, 1);
		print(k);
		print("\n");
		return;
	}
	else
	{
		cur_k = getcwd(dir, 80);
		result = chdir(path);
	}

	if (!result)
	{
		k = getcwd(curdir, 80);
		setenv("PWD", k, 1);
		setenv("OLDPWD", cur_k, 1);
	}
	else
	{
		print_e(program_invocation_name);
		print_e(": no such file or directory\n");
	}
}
/**
 * set_environ - sets an environmental variable
 * @variable: the environmental variable
 * @value: the value
 */
void set_environ(char *variable, char *value)
{
	int res;

	res = setenv(variable, value, 1);

	if (res)
	{
		print_e(program_invocation_name);
		print_e(": cannot set the value\n");
	}
}

/**
 * unset_environ - unsets an environmental variable)
 * @variable: variable to unset
 */
void unset_environ(char *variable)
{
	int res;

	res = unsetenv(variable);

	if (res)
	{
		print_e(program_invocation_name);
		print_e(": cannot unset the variable\n");
	}
}
