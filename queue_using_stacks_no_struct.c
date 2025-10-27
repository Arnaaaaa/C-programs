#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int s1_data[MAX], s1_top = -1;
int s2_data[MAX], s2_top = -1;
void initStack(int *top) 
{
    *top = -1;
}
int isStackEmpty(int top) 
{
    return top == -1;
}
void pushStack(int data[], int *top, int val) 
{
    if (*top == MAX - 1) 
    return;
    data[++(*top)] = val;
}
int popStack(int data[], int *top) 
{
    if (*top == -1) 
    return -1;
    return data[(*top)--];
}
void initQueue() 
{
    initStack(&s1_top);
    initStack(&s2_top);
}
void enqueue(int val) 
{
    pushStack(s1_data, &s1_top, val);
}
int dequeue() 
{
    if (isStackEmpty(s2_top)) 
    {
        while (!isStackEmpty(s1_top)) 
        {
            pushStack(s2_data, &s2_top, popStack(s1_data, &s1_top));
        }
    }
    return popStack(s2_data, &s2_top);
}
int front() 
{
    if (isStackEmpty(s2_top)) 
    {
        while (!isStackEmpty(s1_top)) 
        {
            pushStack(s2_data, &s2_top, popStack(s1_data, &s1_top));
        }
    }
    if (isStackEmpty(s2_top)) 
    return -1;
    return s2_data[s2_top];
}
void print() 
{
    printf("The queue: ");
    if (isStackEmpty(s2_top) && isStackEmpty(s1_top)) 
    {
        printf("Empty queue \n");
        return;
    }
    while (!isStackEmpty(s1_top)) 
    {
        pushStack(s2_data, &s2_top, popStack(s1_data, &s1_top));
    }
    for (int i = s2_top; i >= 0; i--) 
    {
        printf("%d ", s2_data[i]);
    }
    printf("\n");
}
int main()
{
    initQueue();
    while(1)
    {
        int ch=0;
        int d=0;
        printf("Enter 1 to perform enqueue, 2 to perform dequeue, 3 to see the front element, 4 to print the whole queue and 0 to exit the program: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number to be inserted: ");
            scanf("%d",&d);
            enqueue(d);
            break;
            case 2:d=dequeue();
            printf("%d dequeued\n",d);
            break;
            case 3: d=front();
            printf("%d front element\n",d);
            break;
            case 4:print();
            break;
            case 0: printf("Exiting...");
            exit(0);
            break;
            default: printf("ERROR. Wrong Input. Try again\n");
        }
    }
    return 0;
}
