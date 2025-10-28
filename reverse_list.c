#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(Node** head, int data) 
{
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void deleteAtPosition(Node** head, int pos) 
{
    if (*head == NULL) return;
    Node* temp = *head;
    if (pos == 0) 
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp!=NULL&&i<pos-1;i++) 
    temp=temp->next;
    if (temp == NULL || temp->next == NULL) 
    return;
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
Node* reverseIterative(Node* head) 
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node* reverseRecursive(Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
void display(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    Node* head = NULL;
    while (1) 
    {
        int ch = 0, d = 0;
        printf("Enter 1 to insert at beginning, 2 to insert at end, 3 to delete by position, 4 reverse the list using iterative approach, 5 to reverse the list using a recursive approach, 6 to display the list and 0 to exit: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &d);
                insertAtBeginning(&head, d);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &d);
                insertAtEnd(&head, d);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &d);
                deleteAtPosition(&head, d);
                break;
            case 4:head=reverseIterative(head);
                break;
            case 5:head=reverseRecursive(head);
                break;
            case 6:
                printf("Linked List: ");
                display(head);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
