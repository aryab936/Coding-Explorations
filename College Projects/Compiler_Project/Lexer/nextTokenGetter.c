#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void getNextToken(char *removedFile, tkn *tknArray){
  char *fixed_sized_piece[FIXED_SIZE] = '\0';
  char *lexeme[23] = '\0';
  int lexeme_dist = 0;
  int line_num = 0;
  int tknIndex;
  int dist = 0;
  int case_num = 0;
  tkn tk;
  bool er_flag=false;
  bool comment_flag=false;

  for(int i = 0; i < 23; i++){
    tk.identfication_string[i] = '\0';
  }

  FILE *file_pointer;
  file_pointer = fopen(removedFile, "r");
   if (fp == NULL) {
       printf("File does not exist.\n");
       return;
  file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);

  while(true){
    if((fixed_sized_piece[dist]=='\0' || strlen(fixed_sized_piece)==0) && feof(file_pointer)){
        tk.lin_num=line_num;
        strcpy(tk.identification_string,"EOF");
        tk.name=eof;
        tknArray[tknIndex]=tk;
        tknIndex++;
        lexeme_dist=0;
        case_num=0;
        return;
    }
    else{
        file_pointer=getFileStream(file_pointer_fixed_sized_piece,dist);
        dist=0;
    }
    switch(case_num){
      case 0:    /*Add code over here to first convert string to token  and then use token to get corresponding string and then compare*/
          if(fixed_sized_piece[dist] == '+' || fixed_sized_piece[dist] == '-' || fixed_sized_piece[dist] == '*' || fixed_sized_piece[dist] == '/' || fixed_sized_piece[dist] == ',' || fixed_sized_piece[dist] == ';' || fixed_sized_piece[dist] == '(' || fixed_sized_piece[dist] == ')' || fixed_sized_piece[dist] == '[' || fixed_sized_piece[dist] == ']'){
            tk.lin_num = line_num;
            strcpy(tk.identfication_string, fixed_sized_piece[dist]);
            tk.name = *(return_token_from_given_symbol(char* fixed_sized_piece[dist]));
            dist += 1;
            tokenArray[tknIndex] = tk;
            tknIndex += 1;
            lexeme_dist = 0;
            case_num = 0;
          }
          else if(fixed_sized_piece[dist]=='\n'){
            case_num = 0;
            dist += 1;
            line_num += 1;
          }
          else if(fixed_sized_piece[dist]==' ' || fixed_sized_piece[dist]=='\t' ||fixed_sized_piece[dist]=='\t'){
            case_num = 0;
            dist += 1;
          }
          else if(fixed_sized_piece[dist] == ':'){   /*Add code here to copy case 1 over here */
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                if(fixed_sized_piece[dist] == '='){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, ":=");
                tk.name = ASSIGNOP;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else{
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, ":");
                tk.name = COLON;
                // dist += 1; don't needed here as its in final state now
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
          }
          else if(fixed_sized_piece[dist] == '<'){
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
              if(fixed_sized_piece[dist] == '='){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, "<=");
                tk.name = LE;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else if(fixed_sized_piece[dist] == '<'){
                lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                if(fixed_sized_piece[dist] == '<'){
                  //'<<' is consumed and look ahead pointer is at fixed_sized_piece[dist]
                  lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                  tk.lin_num = line_num;
                  strcpy(tk.identfication_string, "<<<");
                  tk.name = DRIVERDEF;
                  // dist += 1;
                  tokenArray[tknIndex] = tk;
                  tknIndex += 1;
                  lexeme_dist = 0;
                  case_num = 0;
                }
                else{
                  tk.lin_num = line_num;
                  strcpy(tk.identfication_string, "<<");
                  tk.name = DEF;
                  //dist += 1;
                  tokenArray[tknIndex] = tk;
                  tknIndex += 1;
                  lexeme_dist = 0;
                  case_num = 0;
                }
              }
              else{
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, "<");
                tk.name = LT;
                //dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
          }
          else if(fixed_sized_piece[dist] == '>'){
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
              if(fixed_sized_piece[dist] == '='){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, ">=");
                tk.name = GE;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else if(fixed_sized_piece[dist] == '>'){
                lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                if(fixed_sized_piece[dist] == '>'){
                  //'<<' is consumed and look ahead pointer ia at fixed_sized_piece[dist]
                  lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                  tk.lin_num = line_num;
                  strcpy(tk.identfication_string, ">>>");
                  tk.name = DRIVERENDDEF;
                  dist += 1; //check if it should be incremented or not
                  tokenArray[tknIndex] = tk;
                  tknIndex += 1;
                  lexeme_dist = 0;
                  case_num = 0;
                }
                else{
                  tk.lin_num = line_num;
                  strcpy(tk.identfication_string, ">>");
                  tk.name = ENDDEF;
                  //dist += 1;
                  tokenArray[tknIndex] = tk;
                  tknIndex += 1;
                  lexeme_dist = 0;
                  case_num = 0;
                }
              }
              else{
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, ">");
                tk.name = GT;
                //dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
          }
          else if(fixed_sized_piece[dist] == '='){
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                if(fixed_sized_piece[dist] == '='){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, "==");
                tk.name = EQ;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else{
                lexeme[lexeme_dist]='\0';
                printf("Error of equal:Incorrect pattern on line %d. The lexeme extracted was %s\n",line_num,lexeme);
                case_num=0;
                er_flag=true;

              }
          }
          else if(fixed_sized_piece[dist] == '!'){
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                 if(fixed_sized_piece[dist] == '='){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, "!=");
                tk.name = NE;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else{
                lexeme[lexeme_dist]='\0';
                printf("Error of not:Incorrect pattern on line %d. The lexeme extracted was %s\n",line_num,lexeme);
                case_num=0;
                er_flag=true;
              }
          }
          else if(fixed_sized_piece[dist] == '.'){
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                if(fixed_sized_piece[dist] == '.'){
                tk.lin_num = line_num;
                strcpy(tk.identfication_string, "..");
                tk.name = RANGEOP;
                dist += 1;
                tokenArray[tknIndex] = tk;
                tknIndex += 1;
                lexeme_dist = 0;
                case_num = 0;
              }
              else{
                dist+=1;
                lexeme[lexeme_dist]='\0';
                printf("Error of not:Incorrect pattern on line %d. The lexeme extracted was %s\n",line_num,lexeme);
                case_num=0;
                er_flag=true;
              }
          }
          else if(identify_Digit(fixed_sized_piece[dist])){
            case_num = 2;
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
          }
          else if(identify_Alphabet(fixed_sized_piece[dist])){
            case_num = 1;
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
          }
          else{
            //error????????????????????????????????????????????????????????????????????/
          }
          break;
      case 1:
            while (true) {
                if((identify_Alphabet(fixed_sized_piece[dist]) || fixed_sized_piece[dist] == '_' || identify_Digit(fixed_sized_piece[dist]))){
                    case_num=1;
                    lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                    file_pointer = getFileStream(file_pointer, fixed_sized_piece, dist);
                }
                else{
                    break;
                }
            }
                lexeme[lexeme_dist] = '\0';
                tk = make_Token_for_ID(lexeme, line_num);
                if (tk.name == ID && (strlen(lexeme) > 20)) {
                     printf("Length Error: identifier is longer than limit of length at line %d",line_num);
                     case_num=0;
                     er_flag=true;
                } else {
                    tknArray[tknIndex] =tk;
                    tknIndex+=1;
                    lexeme_dist = 0;
                    case_num = 0;
                }
                break;
      case 2:
          for(;;;) {
                    if(identify_Digit(fixed_sized_piece[dist])){
                    case_num= 2;
                    lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                    file_pointer = getFileStream(file_pointer,fixed_sized_piece,);
                    }
                    else{
                        break;
                    }
                }
                if (fixed_sized_piece[dist] == '.') {
                    lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                    file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                    if (fixed_sized_piece[dist] == '.') {
                        lexeme[lexeme_dist++]= buffer[dist++];
                        lexme_dist-= 2;
                        dist-= 2;
                        lexeme[lexeme_dist]= '\0'; //flush the lexeme
                        tk.name = NUM;
                        tk.lin_num = line_num;
                        strcpy(tk.identification_string, lexeme);
                        tkArray[tkIndex] = tk;
                        tkIndex++;
                        lexeme_dist = 0;
                        case_num = 0;
                    } else if (identify_Digit(fixed_sized_piece[dist])) {
                        lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                        file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                        while ((dist < SIZE) && identify_Digit(fixed_sized_piece[dist])) {
                            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                            file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                        }
                        if (fixed_sized_piece[dist] == 'E' || fixed_sized_piece[dist] == 'e') {
                            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                            file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                            if (identify_Digit(bfixed_sized_piece[dist])) {
                                lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                                file_pointer = getFileStream(file_pointer, fixed_sized_piece, dist);
                                while (true) {
                                    if(dist < FIXED_SIZE && identify_Digit(fixed_sized_piece[dist])){
                                        lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                                        file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                                    }
                                    else{
                                        break;
                                    }
                                }
                                lexeme[lexeme_dist] = '\0';
                                tk.name = RNUM;
                                tk.lin_num = line_num;
                                strcpy(tk.identified_string,lexeme);
                                tknArray[tknIndex] = tk;
                                tknIndex++;
                                lexeme_dist = 0;
                                case_num = 0;
                            } else if (fixed_sized_piece[dist] == '+' || fixed_sized_piece[dist] == '-') {
                                lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                                file_pointer = getFileStream(file_pointer, fixed_sized_piece,dist);
                                case_num = 3;

                            } else {
                                lexeme[lexeme_dist]='\0';
                                printf("Unknown pattern error. We don't know this lexeme %s on line %d",lexeme,line_num);
                                state=0;
                                er_flag=true;
                            }
                        } else {
                            lexeme[lexeme_dist]= '\0';
                            tk.name = RNUM;
                            tk.lin_num = line_num;
                            strcpy(tk.identification_string,lexeme);
                            tknArray[tknIndex] = tk;
                            tknIndex++;
                            lexeme_dist = 0;
                            case_num = 0;
                        }
                    } else {
                        lexeme[lexeme_dist]='\0';
                        printf("Unknown pattern error. We don't know this lexeme %s on line %d",lexeme,line_num);
                        state=0;
                        er_flag=true;
                    }
                } else {
                    lexeme[lexeme_dist]= '\0';
                    tk.name= NUM;
                    tk.lin_num = line_num;
                    strcpy(tk.identification_string,lexeme);
                    tknArray[tknIndex] = tk;
                    tknIndex++;
                    lexeme_dist= 0;
                    case_num = 0;
                }
                break;
      case 3:
        if (identified_Digit(fixed_sized_piece[dist])) {
            lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
            file_pointer=getFileStream(file_pointer,fixed_sized_piece,dist);
            for(;;;) {
                if(dist < FIXED_SIZE && identify_Digit(fixed_sized_piece[dist])){
                    lexeme[lexeme_dist++] = fixed_sized_piece[dist++];
                    file_pointer = getFileStream(file_pointer,fixed_sized_piece,dist);
                }
                else{
                    break;
                }
                lexeme[lexeme_dist] = '\0';
                tk.name= RNUM;
                tk.lin_num = line_num;
                strcpy(tk.identification_string, lexeme);
                tknArray[tknIndex] = tk;
                tknIndex++;
                lexeme_dist = 0;
                case_num = 0;
         } else {
           lexeme[lexeme_dist]='\0';
           printf("Unknown pattern error. We don't know this lexeme %s on line %d",lexeme,line_num);
           state=0;
           er_flag=true;
         }
         break;
    }
    default:
        printf("Some error\n");
        dist+=1;
  }
  /*Check if we can make it void or int*/
}
