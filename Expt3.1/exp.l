%{
#include<stdio.h>
#include "exp.tab.h"

%}

%%
[0-9]+ {return DIGIT;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
\n {return NL;}
. {return yytext[0];}
%%
