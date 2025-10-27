#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int isBalanced(char* str) 
{
    char stack[MAX];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') 
        {
            stack[++top] = str[i];
        } 
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') 
        {
            if (top == -1) 
            return 0;
            char last = stack[top--];
            if ((str[i] == ')' && last != '(') ||(str[i] == '}' && last != '{') ||(str[i] == ']' && last != '[')) 
            {
                return 0;
            }
        }
    }
    return top == -1;
}
int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%s",&str);
    printf("%s is %s\n", str, isBalanced(str) ? "balanced" : "not balanced");
    return 0;
}
