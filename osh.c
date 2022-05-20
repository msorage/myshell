#include "osh.h"


void osh_prompt(void){

    char** args;
    int shouldRun = 1; /* flag to determine when to exit program */
    char* line;

    while(shouldRun){
        
        printf("osh> ");
        line = osh_readLine();
        args = osh_parseLine(line);
        shouldRun = osh_executeCmd(args);

        safeFree(line);
        free(args);
    }

}

char* osh_readLine(){

    const size_t sizeIncrement = 10;
    size_t bufferSize = MAX_LINE;
    char* buffer = (char*) malloc(sizeof(char) * bufferSize);
    char* currentPosition = buffer;
    size_t length = 0;
    int character;

    if(currentPosition == NULL){
        fprintf(stderr, "osh: malloc error\n");
        exit(MALLOC_ERROR_EXIT);
    }

    while(1){

        character = fgetc(stdin);

        if(character == '\n'){
            break;
        } 

        if(++length >= bufferSize){
            char* newBuffer = realloc(buffer, bufferSize += sizeIncrement);

            if(newBuffer == NULL){
                safeFree(buffer);
                fprintf(stderr, "osh: realloc error\n");
                exit(REALLOC_ERROR_EXIT);
            }

            currentPosition = newBuffer + (currentPosition - buffer);   
            buffer = newBuffer;         
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}

void saferFree(char** ptr){
    if(ptr != NULL && *ptr != NULL){
        free(*ptr);
        *ptr = NULL;
    }
}