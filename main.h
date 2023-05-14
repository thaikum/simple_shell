#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
char **split_string(char *str);
int _strlen(char *str);
char *_strcpy(char *s1, char *s2);
char *_strdup(char *str);
void free_token(char **token);
void non_interactive(void);
void execute(char **args);
#endif
