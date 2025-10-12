%{
    #include <stdio.h>
    #include <string.h>
    char s[100];
%}

%%
abc {printf("ABC");}
. {printf("%s",yytext);}
%%

int main()
{   
    printf("Enter the String:");
    yylex();
    
    return 0;
}

int yywrap()
{
    return 1;
}