%{
#include<stdio.h>
#include "y.tab.h"
%}

%%
[0-9]+ {return DIGIT;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
\n {return NL;}
. {return yytext[0];}

int yywrap()
{
    return 1;
}
%%
