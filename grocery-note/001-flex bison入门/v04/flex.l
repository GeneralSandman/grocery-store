%{
#include<stdio.h>

enum IdentiferType {
  INT = 1,
  DOUBLE = 2,
};


enum IdentiferType identifer_type;
char buffer[20];

int int_value = 0;
double double_value =0;

%}

ALPHA [a-zA-Z]
IDENTIFER {ALPHA}+[a-zA-Z0-9_]*
TYPE_KEY "int"|"double"
DOUBLE_T [0-9]+\.[0-9]+
INT_T ([1-9]+[0-9]*)|[0]


%%

{TYPE_KEY} {
  if(!strcmp("int", yytext)) {
    identifer_type = INT;
  } else if(!strcmp("double", yytext)) {
    identifer_type = DOUBLE;
  }
}

{IDENTIFER} {
  strcpy(buffer, yytext);
}

{INT_T} {
  sscanf(yytext, "%d" ,&int_value);
}

{DOUBLE_T} {
  sscanf(yytext, "%lf" ,&double_value);
}

; {
  if(identifer_type == INT) {
    printf("<%s, int, %d>", buffer, int_value);
  } else if (identifer_type == DOUBLE) {
    printf("<%s, double, %lf>", buffer, double_value);
  }
}

\n { 
  printf("\n");
  memset(buffer, 0, sizeof(buffer));
  identifer_type = 0;
}

. 


%%
int main(int argc, char **argv)
{
  if (argc>1)
  {
    FILE *file;
    file=fopen(argv[1],"r");
    if(file) {
      yyin=file;
    }
  }
  yylex();
  yywrap();
}
int yywrap()
{
	return 1;
}