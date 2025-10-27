%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *msg);
%}

%token ID INVALID NL


%%
stmt: exp NL {printf("Valid identifier\n");};
exp: ID;
%%

int yyerror(char *msg)
{
    printf("Invalid");
    return 1;
}

int main()
{
    printf("Enter the exp");
    yyparse();
    return 0;
}