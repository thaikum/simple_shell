#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
extern char *program_invocation_name;
extern char **environ;

/*================ command_execution.c =========================*/
void execute(char *command);
char *path_command(char *command);

/*================ printing_functions.c ========================*/
void print(char *);
void print_e(char *);
void print_error(char *, int);
void custom_error(char *command, char *error, int times_invoked);
void print_error(char *command, int times_invoked);
void custom_error(char *command, char *error, int times_invoked);

/*================ string_functions.c ==========================*/
char **split_string(char *str);
int _strlen(char *str);
char *_strcpy(char *s1, char *s2);
char *_strdup(char *str);
void non_interactive(void);
char *str_concat(char *str1, char *str2);
int _strcmp(char *, char *);
void _putchar(char *str);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **buffer, size_t *len, FILE *stream);

/*================ memory_functions.c ==========================*/
void free_char_array(char **array);

/*================ utility.c ===================================*/
char *int_to_str(int num);
int is_valid_number(char *str);
int _atoi(char *str);
int isdelim(char c, char *delim);

/*================ execution_mode.c =============================*/
void non_interactive(void);
void interactive(void);

/*================ special functions(inbuilt functions) =================*/
int execute_special_command(char **);
int exit_command(char *);
void cd(char *);
void set_environ(char *, char *);
void unset_environ(char *);
void env(void);

/*================ environ.c ====================================*/
int char_char_len(char **);
int search_value(char *);
int _strn_cmp(char *, char *, int);
void set_value(char **, char *, char *);
#endif
