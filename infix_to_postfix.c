#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int precedence(char op) 
{
    if (op == '+' || op == '-') 
    return 1;
    if (op == '*' || op == '/') 
    return 2;
    if (op == '^') 
    return 3;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) 
{
    char stack[MAX];
    int top = -1, k = 0;
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= '0' && infix[i] <= '9')) 
            postfix[k++] = infix[i];
        else if (infix[i] == '(') 
            stack[++top] = infix[i];
        else if (infix[i] == ')') 
        {
            while (top != -1 && stack[top] != '(') 
                postfix[k++] = stack[top--];
            if (top != -1) 
                top--;
        } 
        else 
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) 
            postfix[k++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    while (top != -1) 
    postfix[k++] = stack[top--];
    postfix[k] = '\0';
}
void printStack11(char stack[], int top) 
{
    printf("Operator Stack: ");
    if (top == -1) 
    {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i <= top; i++) 
    printf("%c ", stack[i]);
    printf("\n");
}
int main()
{
    char infix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s",&infix);
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("Infix: %s -> Postfix: %s\n", infix, postfix);
    return 0;
}
