#include "main.h"

/**
 * int_to_str - converts an integer to string
 * @num: number to convert
 *
 * Return: string from the converted number
 */
char *int_to_str(int num)
{
	char num_str[11];
	int times = 0, shift = 0;

	for (; num > 0; num /= 10, times++)
	{
		for (shift = times; shift > 0; shift--)
			num_str[shift] = num_str[shift - 1];

		num_str[0] = '0' + num % 10;
	}

	num_str[times] = '\0';

	return (_strdup(num_str));
}

#include "main.h"

/**
 * is_valid_number - checks whether a certain string contains only numbers
 * @str: the string to check
 *
 * Return: 1 if its a valid number 0 if not
 */
int is_valid_number(char *str)
{
	int x;

	for (x = 0; str[x]; x++)
	{
		if (str[x] < '0' || str[x] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - converts string to integer
 * @str: string to convert
 *
 * Return: converted integer
 */
int _atoi(char *str)
{
	int number = 0, x = 0, is_negative = 0;

	if (str[0] == '-')
	{
		x = 1;
		is_negative = 1;
	}

	for (; str[x]; x++)
		number = (number * 10) + (str[x] - '0');

	return (is_negative ? number * -1 : number);
}
