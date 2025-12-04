#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{   char op[2], arg1[10],arg2[10],res[10]; 
    FILE *f1 = fopen("input.txt","r");
    FILE *f2 = fopen("output.txt","w");


    while(!feof(f1))
    {
        fscanf(f1,"%s%s%s%s",op,arg1,arg2,res);
        if(strcmp(op,"+")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nADD R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }
        if(strcmp(op,"-")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nSUB R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }
        if(strcmp(op,"*")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nMUL R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }
        if(strcmp(op,"/")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nDIV R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }
        if(strcmp(op,"=")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nMOV %s,R0",res);
        }

    }
    fclose(f1);
    fclose(f2);
    getchar();
    printf("/n");
}