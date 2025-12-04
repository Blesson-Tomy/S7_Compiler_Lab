%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char* msgs);
int yylex();
%}

%token ID NL DIGIT
%left '-''+'
%left '*''/'

%%
stmt: exp NL {printf("Value=%d\n",$1);exit(0);}

exp:exp '+' exp {$$=$1+$3;}
| exp '-' exp {$$=$1-$3;}
| exp '*' exp {$$=$1*$3;}
| exp '/' exp {if($3==0)
{
    printf("Division by 0");

}
else
{
    $$=$1/$3;
}}
| DIGIT {$$=$1;}

%%

int main()
{
    printf("Enter the expression");
    yyparse();
    return 0;
}

int yyerror(char* msgs)
{
    printf("Invalid");
    return 1;
}