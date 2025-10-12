%{
#include<stdio.h>
int num=0;
int i=0,k=0,n=0,o=0;
%}

%%
if|else|for|while|int|char {
    printf("%s is a keyword",yytext);
    num++;
    k++;
}

[0-9]+ {
    printf("%s is a number",yytext);
    num++;
    n++;
}
[_a-zA-Z][_a-zA-Z0-9]* {
    printf("%s is a identifier",yytext);
    num++;
    i++;
}
"+"|"-"|"*"|"/"|"<"|">" {
    printf("%s is a operator",yytext);
    num++;
    o++;
}

[ \t\n] {}

. {}

%%
int main()
{
    yylex();
    printf("%d %d %d %d", k,i,o,n);
    return 0;
}

int yywrap(){
    return 1;
}