%{
#include "y.tab.h"
%}

%%
[0-9]+ { yylval = atoi(yytext); return DIGIT;}
[\n] {return NL;}
[\t] {}
. {printf("Invalid");}
[+/-*] {return yytext[0];}
%%

int yywrap()
{
    return 1;
}