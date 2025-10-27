#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int q1_data[MAX], q1_front = -1, q1_rear = -1;
int q2_data[MAX], q2_front = -1, q2_rear = -1;
void initQueue(int *front, int *rear) 
{
    *front = -1;
    *rear = -1;
}
int isQueueEmpty(int front) 
{
    return front == -1;
}
void enqueue(int data[], int *front, int *rear, int val) 
{
    if (*rear == MAX - 1) 
    return;
    if (*front == -1) 
    *front = 0;
    data[++(*rear)] = val;
}
int dequeue(int data[], int *front, int *rear) 
{
    if (*front == -1) 
    return -1;
    int val = data[*front];
    if (*front == *rear) 
    {
        *front = -1;
        *rear = -1;
    } 
    else 
    {
        (*front)++;
    }
    return val;
}
void initStack() 
{
    initQueue(&q1_front, &q1_rear);
    initQueue(&q2_front, &q2_rear);
}
void push(int val) 
{
    enqueue(q2_data, &q2_front, &q2_rear, val);
    while (!isQueueEmpty(q1_front)) 
    {
        enqueue(q2_data, &q2_front, &q2_rear, dequeue(q1_data, &q1_front, &q1_rear));
    }
    int temp[MAX], tempFront = q1_front, tempRear = q1_rear;
    for (int i = 0; i < MAX; i++) 
    temp[i] = q1_data[i];
    for (int i = 0; i < MAX; i++) 
    q1_data[i] = q2_data[i];
    q1_front = q2_front; 
    q1_rear = q2_rear;
    for (int i = 0; i < MAX; i++) 
    q2_data[i] = temp[i];
    q2_front = tempFront; 
    q2_rear = tempRear;
}
int pop() 
{
    if (isQueueEmpty(q1_front)) 
    return -1;
    return dequeue(q1_data, &q1_front, &q1_rear);
}
int top() 
{
    if (isQueueEmpty(q1_front)) 
    return -1;
    return q1_data[q1_front];
}
void print() 
{
    printf("The stack: ");
    if (isQueueEmpty(q1_front)) 
    {
        printf("Empty stack\n");
        return;
    }
    for (int i = q1_front; i <= q1_rear; i++) 
    {
        printf("%d ", q1_data[i]);
    }
    printf("\n");
}
int main()
{
    initStack();
    while(1)
    {
        int ch=0;
        int d=0;
        printf("Enter 1 to perform push, 2 to perform pop, 3 to see the top element, 4 to print the whole stack and 0 to exit the program: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number to be pushed: ");
            scanf("%d",&d);
            push(d);
            break;
            case 2:d=pop();
            printf("%d popped\n",d);
            break;
            case 3: d=top();
            printf("%d top element\n",d);
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
