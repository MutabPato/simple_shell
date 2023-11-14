#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
ssize_t get_line(char **input, size_t *len, FILE *file);
void is_env(char **argv);
char **tokenize(char *input);
void exec_ve(char **argv);
void is_exit(char **argv);
char *get_path(char **argv);

#endif /* SHELL_H */
