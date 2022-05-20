#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MALLOC_ERROR_EXIT 1
#define BUFFER_LIMIT_ERROR_EXIT 2

#define MAX_LINE 80 /* The maximum length command */

void osh_prompt(void);
char* osh_readLine();
char** osh_parseLine(char* line);
int osh_executeCmd(char** args);