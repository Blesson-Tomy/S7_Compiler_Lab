%{
#include "exp.tab.h"
%}

%%
[0-9]+ {
    yylval=atoi(yytext);
    return DIGIT;
}
[\n] {return NL;}
[+\-*/] {return yytext[0];}
. {printf("Invalid");}
%%

int yywrap()
{
    return 1;
}