#ifndef SHELL1_H
#define SHELL1_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct my_dirs
{
	char *fpath;
	struct my_dirs *next;
} dirs;

char **split(char *str, char delim);
char* _strcpy(char *dest, const char *src);
int wrd_cnt(char *s, char delim);
int _strlen(char *str);
char *_strtok(char *, char *);
char *_strcat(char *, char *);
int _strcmp(const char *, const char *);
char *_getenv(const char *name);
char **create_path_list(void);
void add_new_node_end(dirs **head, char *fpath);
char **prompt(ssize_t *noc, int *is_pipe);
void exec_com(char **com, ssize_t *noc);
void exec_com_pipe(char **com, char **com2, ssize_t *noc);
char *parse(char *str);
#endif
