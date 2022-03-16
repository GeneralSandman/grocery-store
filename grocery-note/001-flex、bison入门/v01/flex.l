%{
#include<stdio.h>
int word_nums = 0;
int int_nums = 0;
int double_nums = 0;
int line_nums = 0;

%}

%%

[a-zA-Z]+ { word_nums++; }
([1-9]+[0-9]*)|[0] { int_nums++; }
[0-9]+\.[0-9]+ { double_nums++; }
\n { 
  line_nums++; 
  printf("[INFO]word_nums:%d,int_nums:%d,double_nums:%d,line_nums:%d\n", word_nums, int_nums, double_nums, line_nums);
  }
.

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