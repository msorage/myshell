#include "osh.h"


void osh_prompt(void){

    char** args;
    int should_run = 1; /* flag to determine when to exit program */
    char* line;

    while(should_run){
        
        printf("osh> ");
        line = osh_readLine();
        args = osh_parseLine(line);
        should_run = osh_executeCmd(args);

        safe_free(line);
        safe_free(args);
    }

}

char* osh_readLine(){

    int buffer_size = MAX_LINE;
    int position = 0;
    char *buffer = (char*) malloc(sizeof(char) * buffer_size);
    int c;

    if(buffer == NULL){
        fprintf(stderr, "osh: malloc error\n");
        exit(MALLOC_ERROR_EXIT);
    }

    while(1){

        c = getchar();

        if(c == EOF || c == '\n'){
            buffer[position] = '\n';
            return buffer;
        } else{
            buffer[position] = c;
        }
        position++;

        if(position >= buffer_size){
            fprintf(stderr, "osh: command too long\n");
            exit(BUFFER_LIMIT_ERROR_EXIT);
        }

    }

}