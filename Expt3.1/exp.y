%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
void yyerror(char* msg);
int yylex();
%}

%token NL ID DIGIT
%left '-''+'
%left '*''/'


%%
stmt: exp NL {printf("Valid Expression"); exit(0);}
exp: exp '+' exp | exp '-' exp | exp '*' exp | exp '/' exp |'(' exp ')' | ID | DIGIT;
%%

void yyerror(char* msg)
{
    printf("Invalid String");
}

int main()
{   
    printf("Enter the expression: ");
    yyparse();
    return 0;
}





