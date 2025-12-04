#include <stdio.h>
#include <string.h>

char optype[100];
char oppos[100];
char expr[100];
int opcount=0;
char temp='Z';

void readop()
{
    char pres[] = "/*+-";
    for(int i=0;i<4;i++)
    {
        for(int j=0;expr[j]!='\0';j++)
        {
            if(pres[i]==expr[j])
            {
                optype[opcount]=pres[i];
                oppos[opcount]=j;
                opcount++;
            }
        }
    }

}

char left(int pos)
{
for(int i=pos-1;i>=0;i--)
{
    if(expr[i]!='$')
    {
        char res=expr[i];
        expr[i]='$';
        return res;
    }
}
return '?';
}

char right(int pos)
{
for(int i=pos+1;expr[i]!='\0';i++)
{
    if(expr[i]!='$')
    {
        char res=expr[i];
        expr[i]='$';
        return res;
    }
}
return '?';
}

void generatecode()
{
    printf("\nThree Address Code:\n");
    printf("-------------------\n");

    for(int i=0;i<opcount;i++)
    {
        char l = left(oppos[i]);
        char r = right(oppos[i]);

        printf("%c = %c %c %c\n",temp,l,optype[i],r);
        expr[oppos[i]]=temp;
        temp--;
    }
    
}

int main()
{
    printf("Enter the expression:");
    scanf("%s",expr);

    readop();
    generatecode();
}