#include <stdio.h>
#include <unistd.h>
#include "osh.c"

char** osh_parseLine(char* line);
int osh_executeCmd(char** args);

int main(void){

    osh_prompt();
    
        
        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */

return 0;
}

