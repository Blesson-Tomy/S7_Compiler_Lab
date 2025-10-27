#include <stdio.h>
#include <string.h>
#include <ctype.h>

int iskey(char buffer[])
{
    char keywords[10][10] = {"while","goto","for","int","main","if","switch","double","else","include"};
    int flag=0;
    for(int i=0;i<10;i++)
    {
        if(strcmp(buffer,keywords[i])==0)
        {
            printf("%s is a keyword",buffer);
            flag=1;
            break;
        }
    }
    return flag;
}

int main()
{ char operators[]="+-*/%=";
char spop[]="(){}[]";
char buffer[15];

FILE* fp = fopen("input.c","r");
if(fp==NULL)
{
    printf("File error");
}
char c;
int j=0;
while((c=fgetc(fp))!=EOF)
{
    for(int i=0;i<6;i++)
    {
    if(c==operators[i])
    {
        printf("%c is an operator\n",c);
    }
}
    for(int j=0;j<6;j++)
    {
    if(c==spop[j])
    {
        printf("%c is a special operator\n",c);
    }
    }

    if(isalnum(c))
    {   
        buffer[j++]=c;
    }
    else if((c==' '|| c=='\n') && j!=0 )
    {
        buffer[j]='\0';
        j=0;
        if(iskey(buffer)==0)
        {
            printf("%s is an Identifier.\n",buffer);
        }
    }
    
}


fclose(fp);
}