%{
    #include<stdio.h>
    int num=0;
    int i=0, k=0, o=0, n=0;
%}

%%
if|else|then|for|while|char {
    printf("%s is a Keyword",yytext);
    num++;
    k++;
}

[0-9]+ {
    printf("%s is a number.",yytext);
    num++;
    n++;
}

"+"|"*"|"/"|"-"|"<"|">" {
    printf("%s is a operator.",yytext);
    num++;
    o++;
}
[_a-zA-Z][_a-zA-Z0-9]*
{
    printf("%s is a identifier",yytext);
    num++;
    i++;
}


"\t"|"\n" {exit(0);}
%%

int main()
{
    printf("Enter the input text: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

