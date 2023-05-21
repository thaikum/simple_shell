#include "main.h"
#include <stdio.h>


int main(){
	char *buf = NULL;
	size_t s = 0;

	_getline(&buf, &s, stdin);
	printf("String is: %s", buf);

		_getline(&buf, &s, stdin);
	printf("String is: %s", buf);

	return (0);
}
