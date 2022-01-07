#include <stdio.h>
#include <stdlib.h>

/* I have not used the ifndef and define statements. If the code doesnt work, kindly consider adding them here.*/
/*
typedef struct{
    Tkn name;
    char identfication_string[23];
    int lin_num;
} tkn;
*/
int main()
{
    /*
    typedef enum{
        A,B,C,D,E,F,G
    }days;
    day={"A","B","H"};
    for(i=0;i<3;i++){
        for (j=0;j<7;j++){
            if (days[j]==day[i]){
                printf("True\n")
            }
        }
        printf("False\n")
    }
    */

    char a[20]={"<\0"};
    char *b="<";
    if(strcmp(a,"<")==0){
        printf("True");
    }
    else{printf("False");}

}
