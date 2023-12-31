#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>



#define SPECIFIER " \t\n"
extern char **environ;
char *user_input(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void free_arr(char **arr);
char **spliter(char *line);
int exe_cute(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *get_path(char *cmd);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
int builtin_check(char *cmd);
void builtin_handle(char **cmd, char **argv, int *status, int idx);
void shell_exit(char **cmd, char **argv, int *status, int idx);
void envir_print(char **cmd, int *status);
int is_positive_number(char *str);
int _atoi(char *str);



#endif
