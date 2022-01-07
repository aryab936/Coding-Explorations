#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void* commentRemover(char *originalFile,char *removedFile);

void* commentRemover(char *originalFile, char *removedFile){
    printf("Inside here\n");
    int size=strlen(originalFile);   /*Figuring out the length of the original text file*/

    int p=0;
    int q=0;
    //int count=0;
    while(true){
        //printf(" %d\n",count);
        if(originalFile[p]=='\0'){
            //printf("End of string\n");
            break;
        }
        else{
            //printf("Inside else\n");
            if(originalFile[p]=='*' && originalFile[p+1]=='*'){
                //printf("Found a comment\n");
                //If you find two *'s then that means a comment is about to start
                int x=q+2;
                for (;q<x;q++){
                    removedFile[q]=' ';
                }
                printf("Removed file is %s\n",removedFile);
                p+=2;
                for(;p<size-1;){
                    if(originalFile[p]=='*' && originalFile[p+1]=='*'){
                        break;
                    }
                    else{
                        if(originalFile[p]=='\n'){
                            removedFile[q]='\n';
                        }
                        else{
                            removedFile[q]=' ';
                        }
                        p+=1;
                        q+=1;
                    }
                }
                x=q+2;
                for (;q<x;q++){
                    removedFile[q]=' ';
                }
                p+=2;
             }
             else{
                removedFile[q]=originalFile[p];
                removedFile[q+1]='\0';
                p+=1;
                q+=1;
             }
        }
        //count++;
    }

}

/*To check*/
int main(){
    char *string="**Comment me**this is a **fuck me** file.Please don't read this 1000 times **help me**why are you like this.";
    char *clean=(char*)malloc(200*sizeof(char));
    commentRemover(string,clean);
    printf("%s",clean);
}
