%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE double
void yyerror(char* msgs);
int yylex();
%}

%token ID NL DIGIT

%%
stmt: exp NL {printf("Valid Expression");};
exp: ID;
%%

void yyerror(char* msgs)
{
    printf("Error");
}
int main()
{
    yyparse();
}