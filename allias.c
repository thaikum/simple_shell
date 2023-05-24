#include "main.h"

/**
 * alias - prints, adds, and updates alias name or value
 * @arg: are the arguments passed to alias command
 */
void alias(char **arg)
{
	int find, j = 0, i = 0;

	static aliasEntry lists[30] = {{NULL, NULL}};

	if (arg[1] == NULL)
	{
		for (; lists[i].aliasName != NULL; i++)
			printAlias(lists[i].aliasName, lists[i].realName);

	}
	else
	{
		i = 1;
		while (arg[i] != NULL)
		{
			find = _strchr(arg[i], '=');
			if (find == -1)
			{
				for (; lists[j].aliasName != NULL; j++)
				{
					if (!_strcmp(arg[i], lists[j].aliasName))
						printAlias(lists[j].aliasName, lists[j].realName);
				}
				aliasError(arg[i]);
			}
			else
			{
				addAlias(arg[i], lists);

			}
			i++;
		}
	}
}

/**
 * printAlias- prints the alias name and value to the stdout.
 * @name: is the name of the allas
 * @value: is the value of alias
 */
void printAlias(char *name, char *value)
{
		print(name);
		print("=");
		print(value);
		print("\n");
}

/**
 * tokenizer - breaks the name and value apart
 * @arg: is the string containg name=value alias
 *
 * Return: a double pointer or NULL
 */
char **tokenizer(char *arg)
{
	char *sub;
	int i = 0;

	char **token = malloc(sizeof(char *) * (_strlen(arg) + 1));

	sub = _strtok(arg, "=");
	while (sub != NULL)
	{
		token[i] = _strdup(sub);
		i++;
		sub = _strtok(NULL, "=");
	}
	token[i] = NULL;

	return (token);
}

/**
 * addAlias - adds if not present and updates the alias value if name present
 * @arg: string containg name1 name2.... or name=value....
 * @lists: is an array containing all the lists of name and value
 */
void addAlias(char *arg, aliasEntry *lists)
{
	int k, j = 0;
	char **token;

	for (k = 0; lists[k].aliasName != NULL; k++)
		;
	token = tokenizer(arg);
	if (token[1] == NULL)
	{
		aliasError(token[0]);
		free_char_array(token);
		return;
	}

	for (; lists[j].aliasName != NULL; j++)
	{
		if (!_strcmp(token[0], lists[j].aliasName))
		{
			lists[j].realName = token[1];
			free_char_array(token);
			return;
		}
	}

	lists[k].aliasName = _strdup(token[0]);
	lists[k].realName = _strdup(token[1]);
	lists[k + 1].aliasName = NULL;
	lists[k + 1].realName = NULL;

	free_char_array(token);
}
/**
 * _strchr - finds the first occurrence of a given character in given string
 * @str: the string to check
 * @ch: the character to test for
 *
 * Return: the first index where the character apears or -1 if it doesn't
 */
int _strchr(char *str, char ch)
{
	int x;

	for (x = 0; str && str[x]; x++)
	{
		if (str[x] == ch)
			return (x);
	}

	return (-1);
}
