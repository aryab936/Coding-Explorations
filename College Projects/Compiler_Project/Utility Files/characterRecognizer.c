#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool identify_Alphabet(char *string){
    if (string=='a' || string=='b' || string=='c' || string=='d' || string=='e' || string=='f' || string=='g'){
        return true;
    }
    else if(string=='h' || string=='i' || string=='j' || string=='k' || string=='l' || string=='m' || string=='n'){
        return true;
    }
    else if(string=='o' || string=='p' || string=='q' || string=='r' || string=='s' || string=='t' || string=='u'){
        return true;
    }
    else if(string=='v' || string=='w' || string=='x' || string=='y' || string=='z'){
        return true;
    }
    else if(string=='A' || string=='B' || string=='C' || string=='D' || string=='E' || string=='F' || string=='G'){
        return true;
    }
    else if(string=='H' || string=='I' || string=='J' || string=='K' || string=='L' || string=='M' || string=='N'){
        return true;
    }
    else if(string=='O' || string=='P' || string=='Q' || string=='R' || string=='S' || string=='T' || string=='U'){
        return true;
    }
    else if(string=='V' || string=='W' || string=='X' || string=='Y' || string=='Z'){
        return true;
    }
    else{
        return false;
    }
}

bool identify_Space(char *string){
    if (string==' ' || string=='\t' ){          /*Not coded for \r carriage return*/
        return true;
    }
    return false;
}

bool identify_Digit(char *string){
    if (string=='0' || string=='1' || string=='2' || string=='3' || string=='4' || string=='5' || string=='6' || string=='7' || string=='8' || string=='9'){
        return true;
    }
    return false;
}

bool identify_newLine(char *string){
    if (string=='\n'){
        return true;
    }
    else{
        return false;
    }
}




int main(){
    char *str=' ';
    bool x=identify_Space(str);
    if(x==true){
        printf("True");
    }
    else{
        printf("False");
    }
}
