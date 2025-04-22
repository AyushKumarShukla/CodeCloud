#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct{
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
}InputBuffer;

InputBuffer* getInputBuffer(){
    InputBuffer* bfr = (InputBuffer*)malloc(sizeof(InputBuffer));
    bfr -> buffer = NULL;
    bfr -> buffer_length = 0;
    bfr -> input_length = 0;
    return bfr;
}

void print_prompt(){printf("litedb > ");}

void close_input_buffer(InputBuffer* bfr){
    free(bfr->buffer);
    free(bfr);
}
void getInput(InputBuffer* bfr){
    ssize_t bytes_read = getline(&(bfr->buffer),&(bfr->buffer_length),stdin);
    
    if(bytes_read < 0){
        printf("Error reading input");
        exit(EXIT_FAILURE);
    }
    bfr->input_length = bytes_read - 1;
    bfr->buffer[bytes_read - 1] = 0;
}

int main(int argc, char* argv[]){
    InputBuffer *inputbfr = getInputBuffer();
    while(true){
        print_prompt();
        getInput(inputbfr);
        if(strcmp(inputbfr->buffer,".exit") == 0){
            close_input_buffer(inputbfr);
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Unrecognized command %s .\n",inputbfr->buffer);
        }
    }
}
