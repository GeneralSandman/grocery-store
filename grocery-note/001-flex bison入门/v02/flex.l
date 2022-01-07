%{
#include<stdio.h>


%}

%%

[a-zA-Z]+ { printf("IDENTIFER "); }
([1-9]+[0-9]*)|[0] { printf("INT_T "); }
[0-9]+\.[0-9]+ { printf("DOUBLE_T "); }
"+" { printf("ADD "); }
"-" { printf("SUB "); }
"*" { printf("MUL "); }
"/" { printf("DIV "); }
"(" { printf("LPA "); }
")" { printf("RPA "); }
\n {
  printf("\n");
}
. {
  printf("invalid input");
}

%%
int main(int argc, char **argv)
{
  yylex();
  yywrap();
}
int yywrap()
{
	return 1;
}