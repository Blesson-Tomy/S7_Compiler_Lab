#include <stdio.h>
#include <stdlib.h>
#define MAXS 500

int main()
{
    int num=0, nooftrans=0;
    int closure[MAXS][MAXS];

    FILE *fp=fopen("input.txt","r");
    if(!fp)
    {
        printf("Error");
    }

    fscanf(fp,"%d",&num);
    fscanf(fp,"%d",&nooftrans);

    for(int i=0;i<num;i++)
    {
        closure[i][i]=1;
    }

    int from,to;
    char symbol;

    for(int i=0;i<nooftrans;i++)
    {
        if(fscanf(fp,"%d%d%c",&from,&to,&symbol)!=3)
        {
            printf("Error");
        }

        else
        {
            if(symbol=='e')
            {
                closure[from][to]=1;
            }
        }
    }

    fclose(fp);

    for(int k=0;k<num;k++)
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(closure[i][k] && closure[k][j])
                {
                    closure[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<num;i++)
    {
        printf("Epsilon Closure(%d)->{",i);
        for(int j=0;j<num;j++)
        {
            if(closure[i][j])
            {
                printf("q%d ,",j);
            }
        }
        printf("\n");
    }


return 0;
}

