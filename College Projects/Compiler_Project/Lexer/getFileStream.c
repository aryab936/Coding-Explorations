#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* First we will try to check if we have read a \0 from the file but at the same time,
    we have not reached the end of the file. If this is true, then we go  forward with another fetch
    cycle. If not, that means that we have reached the end of the file. */

#define FIXED_SIZE 200

FILE* getFileStream(FILE *file_pointer, char *fixed_sized_piece,int dist){
    char *temporary_string[FIXED_SIZE]='\0';

    while(!feof(file_pointer)){
        if(fixed_sized_piece[dist]=='\0' || strlen(fixed_sized_piece)==0){
            memset(fixed_sized_piece,'\0',FIXED_SIZE);

            fread(temporary_string,1,FIXED_SIZE-1,file_pointer);

            commentRemover(temporary_string,fixed_sized_piece);

            fixed_sized_piece[FIXED_SIZE-1]='\0';

            dist=0;
        }
    }
    return file_pointer;
}
