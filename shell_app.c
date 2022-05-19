#include <stdio.h>
#include <unistd.h>
#include "osh.c"

#define MAX_LINE 80 /* The maximum length command */

void osh_prompt(void){

    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */


    while(should_run){
        
        printf("osh> ");
        //if (fgets(args, MAX_LINE, stdin)==NULL){
        //prinft("Error");
        //}
    }

}

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

