#include "main.h"
#include <unistd.h>

/**
 * main - main for the environment
 *
 * @ac: arguments counter
 * @args: the arguments
 * @env: the environment
 * Return: 0 on success or 1 if it fails
 */
int main(int ac __attribute__((unused)), char **args __attribute__((unused)),
	 char **env)
{
	environ = env;

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		non_interactive();
	}

	return (0);
}
