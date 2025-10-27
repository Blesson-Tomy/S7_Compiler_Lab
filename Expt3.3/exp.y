%{
#include <stdio.h>
#include <stdlib.h>   
int yylex(void);
int yyerror(char *msg);
%}

%token DIGIT NL
%left '+' '-'
%left '*' '/'

%%
stmt: exp NL{printf("Value = %d\n",$1); exit(0);}

exp: exp '+' exp {$$=$1+$3;}
| exp '-' exp {$$=$1-$3;}
| exp '*' exp {$$=$1*$3;}
| exp '/' exp {
    if($3==0)
    {
        printf("Error");
        exit(1);
    }
    $$=$1/$3;}
| DIGIT {$$=$1;};
%%



int main()
{
    printf("Enter expression");
    yyparse();
    return 0;
}

