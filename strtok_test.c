#include "main.h"

int main()
{
	char hello[] = "hello world my name is fredrick";
	char *token = NULL;

	token = _strtok(hello, " ");
	while(token)
	{
		printf("word is: %s\n", token);
		token = _strtok(NULL, " ");
	}
	return (0);
}
