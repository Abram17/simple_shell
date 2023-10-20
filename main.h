#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

/*get.c*/
char *readl(void);
char *_path(char *cmd);

/*mytools.c*/
char **tokenize(char *l);
int _exec(char **argv, char **cmd, int n);
void freea(char **a);
void _error(char *sh, char *cmd, int n);
char *_atoi(int n);

/*moretools.c*/
int isbuilt(char *cmd);
void built(char **cmd, char **argv, int *s, int n);
int is_positive(char *s);
int conv(char *s);

/*builtincmd.c*/
void _exitshell(char **cmd, char **argv, int *s, int n);
void _penv(char **cmd, int *s);

/*string.c*/
int _strlen(char *s);
char *_strdup(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/*string2.c*/
void rev_string(char *s);

#endif
