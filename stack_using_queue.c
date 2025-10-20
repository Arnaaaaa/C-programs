#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue
{
    int data[MAX];
    int front,rear;
} Queue;
void initQueue(Queue* q) 
{
    q->front=-1;
    q->rear=-1;
}
int isQueueEmpty(Queue* q) 
{
    return (q->front == -1);
}
void enqueue(Queue* q, int val) 
{
    if (q->rear == MAX - 1) 
    return;
    if (q->front == -1) 
    q->front = 0;
    q->data[++q->rear] = val;
}
int dequeue(Queue* q) 
{
    if (isQueueEmpty(q)) 
    return -1;
    int val = q->data[q->front];
    if (q->front == q->rear) 
    {
        initQueue(q);
    }
    else 
        q->front++;
    return val;
}
typedef struct Stack
{
    Queue q1, q2;
} Stack;
void initStack(Stack* s) 
{
    initQueue(&s->q1);
    initQueue(&s->q2);
}
void push(Stack* s, int val) 
{
    enqueue(&s->q2, val);
    while (!isQueueEmpty(&s->q1)) 
    {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}
int pop(Stack* s) 
{
    if (isQueueEmpty(&s->q1)) 
        return -1;
    return dequeue(&s->q1);
}
int top(Stack* s) 
{
    if (isQueueEmpty(&s->q1)) 
        return -1;
    return s->q1.data[s->q1.front];
}
void print(Stack* s)
{
    printf("The stack: \n");
    if (isQueueEmpty(&s->q1)) 
    {
        printf("Stack is empty\n");
        return;
    }
    
    // Print elements from front to rear
    for (int i = s->q1.front; i <= s->q1.rear; i++)
    {
        printf("%d ", s->q1.data[i]);
    }
    printf("\n");
}
int main() 
{
    int d=0;
    Stack s;
    initStack(&s);
    while(1)
    {
        printf("\nEnter 1 to perform push, 2 to perform pop, 3 to find the top value, 4 to print the stack and 0 to exit the program:\n");
        int ch=0;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("Enter the number to be pushed:\n");
                scanf("%d",&d);
                push(&s,d);
                break;
            case 2: 
                d=pop(&s);
                if (d == -1)
                    printf("Stack is empty!\n");
                else
                    printf("Popped element: %d\n",d);
                break;
            case 3:
                d=top(&s);
                if (d == -1)
                    printf("Stack is empty!\n");
                else
                    printf("Top element: %d\n",d);
                break;
            case 4: 
                print(&s);
                break;
            case 0: 
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("ERROR. Try again\n");
        }
    }
    return 0;
}
