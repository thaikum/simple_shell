#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct alias - for aliases,
 * @aliasName: is the alias name
 * @realName: is the real name of t alias a a command
 */
typedef struct alias
{
	char *aliasName;
	char *realName;
} aliasEntry;

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
void printAlias(char *name, char *value);
void aliasError(char *arg);
void cdError(char *str);
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
char **tokenizer(char *arg);
int _strchr(char *str, char ch);
int _strchr(char *, char);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*================ memory_functions.c ==========================*/
void free_char_array(char **array);

/*================ utility.c ===================================*/
char *int_to_str(int num);
int is_valid_number(char *str);
int _atoi(char *str);
int isdelim(char c, char *delim);
void addAlias(char *arg, aliasEntry *lists);
int is_valid_env_value(char *str);

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
void alias(char **arg);

/*================ environ.c ====================================*/
int char_char_len(char **);
int search_value(char *);
int _strn_cmp(char *, char *, int);
void set_value(char **, char *, char *);

/*==================== unsetenv.c ==================================*/
int track_number_of_environ_alloc(int set);
void free_environ(void);

/*=================== command broker ==============================*/
void command_broker(char *command);

/*================== _strtok ==============================*/
char *_strtok(char *, char *);
#endif
