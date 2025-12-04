%{
#include<stdio.h>
int num,ch,words,op;
%}

%%

if|else|hello {
    printf("%s is Keywords\n",yytext);
    num++;
}

[0-9]+ {
    printf("Number");
    num++;
}
[a-zA-Z][_a-zzA-Z0-9]* {printf("%s Word\n",yytext);
    words++;

}
"="|"<"|">"|"-" {printf("%s Operator\n",yytext);
    op++;

}
[\n\t] {}
. {}

%%

int main()
{
    yylex();
    printf("%d %d",words,op);
    return 0;
}

int yywrap()
{
    return 1;
}