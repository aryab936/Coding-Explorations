#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Mappings are as follows: Tkn is token and tkn is Token */
typedef struct{
    Tkn identified_token;
    char *name;
}mapping;
int main()
{
    /*Creating a mapping of enumerated token to its corresponding terminal. This will help in identification if an extracted token is valid or not.*/
    mapping *terminal_mapping=(mapping*)malloc(55*sizeof(mapping));

    terminal_mapping[0].identified_token=OR;   /*mapping OR */
    terminal_mapping[0].name="OR";

    terminal_mapping[1].identified_token=ID;   /*mapping ID */
    terminal_mapping[1].name="ID";

    terminal_mapping[2].identified_token=MUL;   /*mapping MUL */
    terminal_mapping[2].name="*";

    terminal_mapping[3].identified_token=RNUM;   /*mapping RNUM */
    terminal_mapping[3].name="RNUM";

    terminal_mapping[4].identified_token=LT;   /*mapping LT */
    terminal_mapping[4].name="<";

    terminal_mapping[5].identified_token=AND;   /*mapping AND */
    terminal_mapping[5].name="AND";

    terminal_mapping[6].identified_token=PRINT;   /*mapping PRINT */
    terminal_mapping[6].name="PRINT";

    terminal_mapping[7].identified_token=DRIVER;   /*mapping DRIVER */
    terminal_mapping[7].name="DRIVER";

    terminal_mapping[8].identified_token=INPUT;   /*mapping INPUT */
    terminal_mapping[8].name="INPUT";

    terminal_mapping[9].identified_token=CASE;   /*mapping CASE */
    terminal_mapping[9].name="CASE";

    terminal_mapping[10].identified_token=PARAMETERS;   /*mapping PARAMETERS */
    terminal_mapping[10].name="PARAMETERS";

    terminal_mapping[11].identified_token=DEFAULT;   /*mapping DEFAULT */
    terminal_mapping[11].name="DEFAULT";

    terminal_mapping[12].identified_token=DRIVERENDDEF;   /*mapping DRIVERENDDEF */
    terminal_mapping[12].name="DRIVERENDDEF";

    terminal_mapping[13].identified_token=GT;   /*mapping OR */
    terminal_mapping[13].name="GT";

    terminal_mapping[14].identified_token=MODULE;   /*mapping MODULE */
    terminal_mapping[14].name="MODULE";

    terminal_mapping[15].identified_token=PROGRAM;   /*mapping PROGRAM */
    terminal_mapping[15].name="PROGRAM";

    terminal_mapping[16].identified_token=NE;   /*mapping NE */
    terminal_mapping[16].name="NE";

    terminal_mapping[17].identified_token=FALSE;   /*mapping FALSE */
    terminal_mapping[17].name="FALSE";

    terminal_mapping[18].identified_token=SEMICOL;   /*mapping SEMICOL */
    terminal_mapping[18].name="SEMICOL";

    terminal_mapping[19].identified_token=SQBC;   /*mapping SQBC */
    terminal_mapping[19].name="SQBC";

    terminal_mapping[20].identified_token=GE;   /*mapping GE */
    terminal_mapping[20].name="GE";

    terminal_mapping[21].identified_token=ENDDEF;   /*mapping ENDDEF */
    terminal_mapping[21].name="ENDDEF";

    terminal_mapping[22].identified_token=INTEGER;   /*mapping INTEGER */
    terminal_mapping[22].name="INTEGER";

    terminal_mapping[23].identified_token=USE;   /*mapping OR */
    terminal_mapping[23].name="USE";

    terminal_mapping[24].identified_token=BREAK;   /*mapping BREAK */
    terminal_mapping[24].name="BREAK";

    terminal_mapping[25].identified_token=START;   /*mapping START */
    terminal_mapping[25].name="START";

    terminal_mapping[26].identified_token=RETURNS;   /*mapping RETURNS */
    terminal_mapping[26].name="RETURNS";

    terminal_mapping[27].identified_token=TAKES;   /*mapping TAKES */
    terminal_mapping[27].name="TAKES";

    terminal_mapping[28].identified_token=BOOLEAN;   /*mapping BOOLEAN */
    terminal_mapping[28].name="BOOLEAN";

    terminal_mapping[29].identified_token=COMMA;   /*mapping COMMA */
    terminal_mapping[29].name="COMMA";

    terminal_mapping[30].identified_token=FOR;   /*mapping FOR */
    terminal_mapping[30].name="FOR";

    terminal_mapping[31].identified_token=SQBO;   /*mapping SQBO */
    terminal_mapping[31].name="SQBO";

    terminal_mapping[32].identified_token=TRUE;   /*mapping TRUE */
    terminal_mapping[32].name="TRUE";

    terminal_mapping[33].identified_token=EQ;   /*mapping EQ */
    terminal_mapping[33].name="EQ";

    terminal_mapping[34].identified_token=SWITCH;   /*mapping SWITCH */
    terminal_mapping[34].name="SWITCH";

    terminal_mapping[35].identified_token=REAL;   /*mapping REAL */
    terminal_mapping[35].name="REAL";

    terminal_mapping[36].identified_token=RANGEOP;   /*mapping OR */
    terminal_mapping[36].name="RANGEOP";

    terminal_mapping[37].identified_token=ARRAY;   /*mapping ARRAY */
    terminal_mapping[37].name="ARRAY";

    terminal_mapping[38].identified_token=BC;   /*mapping BC */
    terminal_mapping[38].name="BC";

    terminal_mapping[39].identified_token=WHILE;   /*mapping WHILE */
    terminal_mapping[39].name="WHILE";

    terminal_mapping[40].identified_token=NUM;   /*mapping NUM */
    terminal_mapping[40].name="NUM";

    terminal_mapping[41].identified_token=DECLARE;   /*mapping DECLARE */
    terminal_mapping[41].name="DECLARE";

    terminal_mapping[42].identified_token=LE;   /*mapping LE */
    terminal_mapping[42].name="LE";

    terminal_mapping[43].identified_token=COLON;   /*mapping COLON */
    terminal_mapping[43].name="COLON";

    terminal_mapping[44].identified_token=IN;   /*mapping IN*/
    terminal_mapping[44].name="IN";

    terminal_mapping[45].identified_token=DIV;   /*mapping DIV */
    terminal_mapping[45].name="DIV";

    terminal_mapping[46].identified_token=DRIVERDEF;   /*mapping DRIVERDEF */
    terminal_mapping[46].name="DRIVERDEF";

    terminal_mapping[47].identified_token= WITH;   /*mapping  WITH */
    terminal_mapping[47].name="WITH";

    terminal_mapping[48].identified_token=BO;   /*mapping BO */
    terminal_mapping[48].name="BO";

    terminal_mapping[49].identified_token=GET_VALUE;   /*mapping GET_VALUE */
    terminal_mapping[49].name="GET_VALUE";

    terminal_mapping[50].identified_token=END;   /*mapping END */
    terminal_mapping[50].name="END";

    terminal_mapping[51].identified_token=ASSIGNOP;   /*mapping ASSIGNOP */
    terminal_mapping[51].name="ASSIGNOP";

    terminal_mapping[52].identified_token=PLUS;   /*mapping PLUS */
    terminal_mapping[52].name="PLUS";

    terminal_mapping[53].identified_token=MINUS;   /*mapping MINUS */
    terminal_mapping[53].name="MINUS";

    terminal_mapping[54].identified_token=DEF;   /*mapping DEF */
    terminal_mapping[54].name="DEF";

}

/*the following function first takes in a particular tokenised string and then converts it into its enum equivalent.
In case this is not possible, we will return the value null*/
 Tkn return_identified_token(char *input_string){
    int p=0;
    for( p=0; p<55; p++){
        if(stricmp(input_string,terminal_mapping[p].name)==0){
            return terminal_mapping[p].identified_token;
        }
    }
    return NULL;
 }
