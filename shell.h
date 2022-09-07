#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>

#define MAXCOM 1000 /* max number of letters to be supported */
#define MAXLIST 100 /* max number of commands to be supported */

/* Clearing the shell using escape sequences */
#define clear() printf("\033[H\033[J")

char **environ;

/* Print functions */
int _printf(const char *format, ...);
int _putchar(char c);
int output_string(char *string);
int output_decimal(int number);
long number_to_base_10(int number, int base);
long int power(int base, int a);
int output_binary(int number);
int output_unsigned_int(unsigned int number);

/* Forward definitions */
int _strlen(char *s);
char *_strncpy(char *dest, const char *src);
int read_user_input(char *str);
void exec_cmds_without_pipe(char **cmd_to_execute, const char *filename);
/* void exec_cmds_with_pipe(char **args, char **args_pipe); */
void openHelp(void);
int inbuilt_cmd_handler(char **cmd_to_execute);
int parsePipe(char *str, char **input_CMD_piped);
void parseSpace(char *str, char **parsed);
int analyze_string(char *str, char **args, char **args_pipe);
char *_cut_string(char *dest, int pos);
char *_strcat(char *dest, char *src);
char *_strsep(char **str, char *delims);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);

#endif