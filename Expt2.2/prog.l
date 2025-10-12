%{
#include<stdio.h>
int l=0,c=0,w=0;
%}

%%
[a-zA-Z0-9] {c++;}
[\n] {l++; c++;}
[\t] {w++; c++;}
. {c++;}

%%

int main()
{
    FILE *file = fopen("file.txt","r");
    if(file==NULL)
    {
        printf("Error opening file");
        return 1;
    }
    yyin=file;
    yylex();
    printf("%d %d %d",l,c,w);
    fclose(file);
    return 0;
}

int yywrap()
{
    return 1;
}