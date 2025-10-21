#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Stack
{
    int data[MAX];
    int top;
}Stack;
void initStack(Stack* s) 
{
    s->top = -1;
}
int isStackEmpty(Stack* s) 
{
    return (s->top == -1);
}
void push(Stack* s, int val) 
{
    if (s->top == MAX - 1) 
    return;
    s->data[++s->top] = val;
}
int pop(Stack* s) 
{
    if (isStackEmpty(s)) 
    return -1;
    return s->data[s->top--];
}
typedef struct Queue
{
    Stack s1, s2;
} Queue;
void initQueue(Queue* q) 
{
    initStack(&q->s1);
    initStack(&q->s2);
}
void enqueue(Queue* q, int val) 
{
    push(&q->s1, val);
}
int dequeue(Queue* q) 
{
    if (isStackEmpty(&q->s2)) 
    {
        while (!(isStackEmpty(&q->s1)))
        {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}
int front(Queue* q) 
{
    if (isStackEmpty(&q->s2)) 
    {
        while (!isStackEmpty(&q->s1)) 
        {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (isStackEmpty(&q->s2)) 
        return -1;
    return q->s2.data[q->s2.top];
}
void print(Queue* q)
{
    if (isStackEmpty(&q->s1) && isStackEmpty(&q->s2))
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = q->s2.top; i >= 0; i--)
    {
        printf("%d ", q->s2.data[i]);
    }
    for (int i = 0; i <= q->s1.top; i++)
    {
        printf("%d ", q->s1.data[i]);
    }
    printf("\n");
}
int main()
{
    Queue q;
    initQueue(&q);
    int ch,d;
    while (1)
    {
        printf("Enter 1 to perform enqueue, 2 to perfrom dequeue, 3 to display the front element, 4 to print the queue and 0 to exit the program: \n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &d);
                enqueue(&q, d);
                break;
                
            case 2:
                d=dequeue(&q);
                if (d== -1)
                    printf("Queue is empty\n");
                else
                    printf("Dequeued element: %d\n", d);
                break;
                
            case 3:
                d=front(&q);
                if (d==-1)
                    printf("Queue is empty\n");
                else
                    printf("Front element: %d\n",d);
                break;
            case 4:
                print(&q);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("ERROR.Try again\n");
        }
    }
    return 0;
}
