#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* header files */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

/* Constants */
#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

/* Global variables */
/*static char *current_directory;*/

/* Function prototypes */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
void panic(char *message);
int cd_builtin(char **args);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);
int alias_builtin(char **args);
int exit_builtin(char **args);
int run_script(char *filename);
int launch(char **args);
int file_input(char *filename);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int add_alias(char ***alias_list, int *alias_count, char *alias);
void print_aliases(char **alias_list, int alias_count, char *alias_name);


#endif
