#include "main.h"

/**
 * command_broker - intercepts the command to check for any occurence of ; ||
 * and infuture &&
 * @command: the command to check;
 */
void command_broker(char *command)
{
	int contains_pipe, index;
	int contains_semicolon;
	char *token;
	char *commands[1024];

	contains_pipe = _strchr(command, '|');
	contains_semicolon = _strchr(command, ';');

	if (contains_pipe != -1 || contains_semicolon != -1)
	{
		for (index = 0, token = _strtok(command, "||;"); token;
		     token = _strtok(NULL, "||;"), index++)
			commands[index] = token;

		commands[index] = NULL;

		for (index = 0; commands[index]; index++)
			execute(commands[index]);

	}
	else
		execute(command);
}
