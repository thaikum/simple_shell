#include "main.h"

/**
 * main - it determine which mode of shell to use
 *
 * Return: 0 on sucess or 1 on fail
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(void);
	}
	else
	{
		non_interactive();
	}

	return (0);
}
