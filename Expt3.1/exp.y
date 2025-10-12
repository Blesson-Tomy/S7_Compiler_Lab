%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char *msg);
int yylex();
%}
%token DIGIT ID NL
%left '-' '+'
%left '*' '/'

%%
stmt: exp NL {printf("Valid"); exit(0);};

exp: exp '+' exp
| exp '-' exp
| exp '*' exp
| exp '/' exp
| '(' exp ')'
| ID
| DIGIT
%%

int yyerror(char *msg)
{
    printf("Invalid");
    return 1;
}

int main()
{
    printf("Enter exp");
    yyparse();
    return 0;
}