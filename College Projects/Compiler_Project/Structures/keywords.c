/*
{ AND,        "AND"        },
    { ARRAY,      "array"      },
    { BOOLEAN,    "boolean"    },
    { BREAK,      "break"      },
    { CASE,       "case"       },
    { DECLARE,    "declare"    },
    { DEFAULT,    "default"    },
    { DRIVER,     "driver"     },
    { END,        "end"        },
    { FALSE,      "false"      },
    { FOR,        "for"        },
    { GET_VALUE,  "get_value"  },
    { IN,         "in"         },
    { INPUT,      "input"      },
    { INTEGER,    "integer"    },
    { MODULE,     "module"     },
    { PARAMETERS, "parameters" },
    { PRINT,      "print"      },
    { PROGRAM,    "program"    },
    { RETURNS,    "returns"    },
    { START,      "start"      },
    { SWITCH,     "switch"     },
    { TAKES,      "takes"      },
    { TRUE,       "true"       },
    { USE,        "use"        },
    { WHILE,      "while"      },
};
*/
typedef struct{
    Tkn identified_token;
    char *name;
}keyword_mapping;

mapping *keyword_mapping=(keyword_mapping*)malloc(30*sizeof(keyword_mapping));

keyword_mapping[0].identified_token=OR;   /*keyword mapping OR */
keyword_mapping[0].name="OR";

keyword_mapping[1].identified_token=OF;   /*keyword mapping OF */
keyword_mapping[1].name="of";

keyword_mapping[2].identified_token=FALSE;   /*keyword mapping FALSE */
keyword_mapping[2].name="false";

keyword_mapping[3].identified_token=WITH;   /*keyword mapping with */
keyword_mapping[3].name="with";

keyword_mapping[4].identified_token=REAL;   /*keyword mapping real */
keyword_mapping[4].name="real";

keyword_mapping[5].identified_token=GET_VALUE;   /*keyword mapping OR */
keyword_mapping[5].name="get_value";

keyword_mapping[6].identified_token=INTEGER;   /*keyword mapping OR */
keyword_mapping[6].name="integer";

keyword_mapping[7].identified_token=BOOLEAN;   /*keyword mapping OR */
keyword_mapping[7].name="boolean";

keyword_mapping[8].identified_token=DECLARE;   /*keyword mapping OR */
keyword_mapping[8].name="declare";

keyword_mapping[9].identified_token=TRUE;   /*keyword mapping OR */
keyword_mapping[9].name="true";

keyword_mapping[10].identified_token=CASE;   /*keyword mapping OR */
keyword_mapping[10].name="case";

keyword_mapping[11].identified_token=START;   /*keyword mapping OR */
keyword_mapping[11].name="start";

keyword_mapping[12].identified_token=INPUT;   /*keyword mapping OR */
keyword_mapping[12].name="input";

keyword_mapping[13].identified_token=TAKES;   /*keyword mapping OR */
keyword_mapping[13].name="takes";

keyword_mapping[14].identified_token=BREAK;   /*keyword mapping OR */
keyword_mapping[14].name="break";

keyword_mapping[15].identified_token=PRINT;   /*keyword mapping OR */
keyword_mapping[15].name="print";

keyword_mapping[16].identified_token=USE;   /*keyword mapping OR */
keyword_mapping[16].name="use";

keyword_mapping[17].identified_token=ARRAY;   /*keyword mapping OR */
keyword_mapping[17].name="array";

keyword_mapping[18].identified_token=WHILE;   /*keyword mapping OR */
keyword_mapping[18].name="while";

keyword_mapping[19].identified_token=DRIVER;   /*keyword mapping OR */
keyword_mapping[19].name="driver";

keyword_mapping[20].identified_token=PARAMETERS;   /*keyword mapping OR */
keyword_mapping[20].name="parameters";

keyword_mapping[21].identified_token=SWITCH;   /*keyword mapping OR */
keyword_mapping[21].name="switch";

keyword_mapping[22].identified_token=DEFAULT;   /*keyword mapping OR */
keyword_mapping[22].name="default";

keyword_mapping[23].identified_token=MODULE;   /*keyword mapping OR */
keyword_mapping[23].name="module";

keyword_mapping[24].identified_token=PROGRAM;   /*keyword mapping OR */
keyword_mapping[24].name="program";

keyword_mapping[25].identified_token=END;   /*keyword mapping OR */
keyword_mapping[25].name="end";

keyword_mapping[26].identified_token=IN;   /*keyword mapping OR */
keyword_mapping[26].name="in";

keyword_mapping[27].identified_token=FOR;   /*keyword mapping OR */
keyword_mapping[27].name="for";

keyword_mapping[28].identified_token=RETURNS;   /*keyword mapping OR */
keyword_mapping[28].name="returns";

keyword_mapping[29].identified_token=AND;   /*keyword mapping OR */
keyword_mapping[29].name="AND";

Tkn* key_from_str(char* string){
    int p=0;
    for(p=0;p<30;p++){
        if(strcmp(string,keyword_mapping[p].name)==0){
            return &(keyword_mapping[p].identified_token);
        }
    }
    return NULL;
}
