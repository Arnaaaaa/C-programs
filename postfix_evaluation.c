#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int evaluate(char* postfix) 
{
    int stack[MAX], top = -1;
    char *token = strtok(postfix, " ");
    while (token != NULL) 
    {
        if (isdigit(token[0]))
        {  
            stack[++top] = atoi(token);
        } 
        else 
        { 
            int val2 = stack[top--];
            int val1 = stack[top--];
            switch (token[0]) 
            {
                case '+': 
                stack[++top] = val1 + val2; 
                break;
                case '-': 
                stack[++top] = val1 - val2; 
                break;
                case '*': 
                stack[++top] = val1 * val2; 
                break;
                case '/': 
                if (val2 == 0) 
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                stack[++top] = val1 / val2; 
                break;
                default:
                printf("Error: Invalid operator '%c'\n", token[0]);
                exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}
int main() 
{
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = 0;
    printf("Result: %d\n", evaluate(postfix));
    return 0;
}
