#include "main.h"

/**
 * env - prints environmental variables
 *
 * Return: nothing
 */
void env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i] != NULL)
	{
		_putchar(env[i]);
		_putchar("\n");
		i++;
	}
}
/**
 * _putchar - prints string to the stdout
 * @str: is the string to be printed
 */
void _putchar(char *str)
{
	write(1, str, _strlen(str));
}
