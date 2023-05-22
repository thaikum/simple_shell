#include "main.h"

/**
 * command_broker - intercepts the command to check for any occurence of ; ||
 * and infuture &&
 * @command: the command to check;
 */
void command_broker(char *command)
{
	int contains_pipe;
	int contains_semicolon;
	char *token;
	char *ind_command;

	contains_pipe = _strchr(command, '|');
	contains_semicolon = _strchr(command, ';');

	if (contains_pipe != -1 || contains_semicolon != -1)
	{
		token = strtok(command, ";");
		while(token != NULL)
		{
			ind_command = _strdup(token);
			execute(ind_command);
			free(ind_command);
			token = strtok(NULL, ";");
		}
	}
	else
		execute(command);
}
