#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

tkn make_Token_for_ID(char *characters, int p){
    tkn tk;
    tk.lin_num=p;
    tk.name=ID;
    strcpy(tk.identification_string,characters);

    if(key_from_str(characters)!=NULL){
        tk.name=key_from_str(characters);
    }
    return tk;
}
