#include <stdio.h>
#include <unistd.h>
#include <string.h>

void osh_prompt(void);
char* osh_readLine();
char** osh_parseLine(char* line);
int osh_executeCmd(char** args);