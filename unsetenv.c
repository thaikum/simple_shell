#include "main.h"

/**
 * track_number_of_environ_alloc - tracks the number of environmental variables
 * allocated
 * @set: updates the number: -1 on unsetting, 1 on updating, 0 on reading
 *
 * Return: number of set variables
 */
int track_number_of_environ_alloc(int set)
{
	static int set_environ = -1;

	if (set_environ == -1 && set != 0)
	{
		set_environ = 1;
	}
	else if (set != 0)
		set_environ += set;

	return (set_environ);
}

/**
 * free_environ - frees all allocated environ variables;
 */
void free_environ(void)
{
	int times = track_number_of_environ_alloc(0);
	int environ_len = char_char_len(environ);
	int l;

	for (l = 1; l <= times; l++)
		free(environ[environ_len - l]);
}

/**
 * unset_environ - unsets a set value in the environment
 * @value: the value to unset
 */
void unset_environ(char *value)
{
	int environ_len = char_char_len(environ);
	int set_val = track_number_of_environ_alloc(0);
	int val_pos;

	if (environ != NULL)
	{
		val_pos = search_value(value);
		if (val_pos != -1)
		{
			if (val_pos > environ_len - set_val)
				track_number_of_environ_alloc(-1);

			free(environ[val_pos]);

			for (; val_pos < environ_len; val_pos++)
			{
				environ[val_pos] = environ[val_pos + 1];
			}
			 environ[val_pos] = NULL;
		}
	}
}
