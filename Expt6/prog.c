#include <stdio.h>
#include <string.h>

char input[20];
char stack[20];
int top = -1;
int i = 0;

void check() {
    // Check for possible reductions
    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
        stack[top-2] = 'E';
        top -= 2;
        printf("\tReduce by E → E+E\n");
    }
    else if (top >= 2 && stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E') {
        stack[top-2] = 'E';
        top -= 2;
        printf("\tReduce by E → E*E\n");
    }
    else if (top >= 2 && stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(') {
        stack[top-2] = 'E';
        top -= 2;
        printf("\tReduce by E → (E)\n");
    }
    else if (top >= 1 && stack[top] == 'd' && stack[top-1] == 'i') {
        stack[top-1] = 'E';
        top--;
        printf("\tReduce by E → id\n");
    }
}

int main() {
    printf("Enter an expression (use 'id' for identifiers): ");
    scanf("%s", input);
    
    printf("\nStack\t\tInput\t\tAction\n");
    printf("--------------------------------------------------\n");

    while (i < strlen(input)) {
        // Shift
        stack[++top] = input[i];
        input[i] = ' ';
        i++;
        
        printf("%s\t\t%s\t\tShift\n", stack, input);
        check();
    }

    // Just call check() once at the end (loop not needed)
    check();

    if (stack[0] == 'E' && top == 0)
        printf("\nInput accepted: successfully parsed!\n");
    else
        printf("\nInput not accepted: parsing failed.\n");

    return 0;
}