% {
    #include <stdio.h>
    int vow=0, cons=0;
    %
}
%%

[AEIOUaeiou] {vow++}
[a-z A-Z] {cons++}
[/t/n] {/* ignore whitespace*/}
[.] {/* ignore any other characters*/}

%%

int main()
{
    printf("Enter the String");
    yylex();
    printf("The total number of vowels: %d. \n",vow);
    printf("The total number of consonants: %d. \n",cons);
    return 0;
}