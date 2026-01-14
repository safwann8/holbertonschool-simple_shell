#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
extern int last_status;

char *trim_spaces(char *str);
void split_line(char *line, char **argv);
void execute_cmd(char **argv, unsigned int line_count);
char *get_path_cmd(char *cmd);
char *get_env_path(void);
int handle_builtins(char **argv, char *line);

#endif
