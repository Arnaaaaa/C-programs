#include <stdio.h>
#include <stdlib.h>
void initQueue(int *front, int *rear) 
{
    *front = -1;
    *rear = -1;
}
void enqueue(int a[], int *front, int *rear, int val,int n) 
{
    if (*rear == n - 1) 
    return;
    if (*front == -1) 
    *front = 0;
    a[++(*rear)] = val;
}
int dequeue(int a[], int *front, int *rear) 
{
    if (*front == -1) 
    return -1;
    int val = a[*front];
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
void reverse(int a[], int *front, int *rear,int n) 
{
    int stack[n], top = -1;
    while (*front != -1) 
    {
        stack[++top] = dequeue(a, front, rear);
    }
    while (top != -1) 
    {
        enqueue(a, front, rear, stack[top--],n);
    }
}
void print(int a[], int front, int rear) 
{
    printf("Queue: ");
    if (front == -1) 
    {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    printf("Enter the number of elements of the queue: ");
    int n=0;
    scanf("%d",&n);
    int a[n], front = -1, rear = -1;
    initQueue(&front, &rear);
    printf("Enter the values in the queue: \n");
    for(int i=0;i<n;i++)
    {
        int temp=0;
        scanf("%d",&temp);
        enqueue(a,&front,&rear,temp,n);
    }
    printf("The original queue:\n");
    print(a,front,rear);
    printf("The reversed queue:\n");
    reverse(a,&front,&rear,n);
    print(a,front,rear);
    return 0;
}
