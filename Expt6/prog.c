#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(char* stk, int* i, char* ip)
{ char acb[]="REDUCE TO E";
    if(*i>=2 && stk[*i-2]=='i' && stk[*i-1]=='d')
    {   
        stk[*i-2]='E';
        stk[*i-1]='\0';
        (*i)--;
        printf("\n$%s\t%s$\t %s",stk,ip,acb);
        return 1;
    }
    if(*i>=3 && stk[*i-3]=='E' && stk[*i-2]=='+' && stk[*i-1]=='E')
    {
        stk[*i-3]='E';
        stk[*i-2]='\0';
        (*i)--;
        (*i)--;
        printf("\n$%s \t %s$ \t%s",stk,ip,acb);
        return 1;
    }
    if(*i>=3 && stk[*i-3]=='E' && stk[*i-2]=='*' && stk[*i-1]=='E')
    {
        stk[*i-3]='E';
        stk[*i-2]='\0';
        (*i)--;
        (*i)--;
        printf("\n$%s\t%s$\t%s",stk,ip,acb);
        return 1;
    }

    if(*i>=3 && stk[*i-3]=='(' && stk[*i-2]=='E' && stk[*i-1]==')')
    {
        stk[*i-3]='E';
        stk[*i-2]='\0';
        (*i)--;
        (*i)--;
        printf("\n$%s\t%s$\t%s",stk,ip,acb);
        return 1;
    }
    return 0;
}

int main()
{   int i=0;
    char ip[15], stk[15], ac[15];
    printf("Enter the expression: ");
    scanf("%s", ip);
    int len=strlen(ip);
    strcpy(ac,"SHIFT->");

    printf("STACK\t INPUT\t ACTION");

    for(int j=0;j<len;j++)
    {
        if(ip[j]=='i' && j+1<len && ip[j+1]=='d')
        {
            stk[i]=ip[j];
            stk[i+1]=ip[j+1];
            stk[i+2]='\0';
            ip[j]=' ';
            ip[j+1]=' ';
            i++;
            i++;
            j++;
            printf("\n$%s\t%s$\t %sid",stk,ip,ac);
        }
        else{
            stk[i]=ip[j];
            ip[j]=' ';
            stk[i+1]='\0';
            i++;
            printf("\n$%s\t%s$\t %ssymbol",stk,ip,ac);

        }

        while(check(stk,&i,ip));
        
    }

    if(strcmp(stk,"E")==0)
    {
        printf("Successful");
    }
    else{
        printf("Invalid String");
    }
    return 0;
}