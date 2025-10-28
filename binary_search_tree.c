#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    int data;
    struct Node* right;
    struct Node* left;
} Node;
Node* createNode(int val) 
{
    struct Node* nw = (struct Node*)malloc(sizeof(struct Node));
    nw->data = val;
    nw->right = NULL;
    nw->left = NULL;
    return nw;
}
Node* insert(struct Node* root, int val) 
{
    if (root == NULL) 
    {
        return createNode(val);
    } 
    else if (val < root->data) 
    {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) 
    {
        root->right = insert(root->right, val);
    }
    return root;
}
struct Node* maximum(struct Node* root) 
{
    if (root->right != NULL)
        return maximum(root->right);
    return root;
}
struct Node* minimum(struct Node* root) 
{
    if (root->left != NULL)
        return minimum(root->left);
    return root;
}
struct Node* search(struct Node* root, int val) 
{
    if (root == NULL)
        return NULL;
    else if (root->data == val)
        return root;
    else if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
struct Node* deletion(struct Node* node, int data) 
{
    if (node == NULL) 
    {
        printf("Value not found in the tree\n");
        return node;
    }
    if (data < node->data)
        node->left = deletion(node->left, data);
    else if (data > node->data)
        node->right = deletion(node->right, data);
    else 
    {
        if (node->left == NULL && node->right == NULL) 
        {
            free(node);
            return NULL;
        } 
        else if (node->left == NULL) 
        {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } 
        else if (node->right == NULL) 
        {
            struct Node* temp = node->left;
            free(node);
            return temp;
        } 
        else 
        {
            struct Node* temp = minimum(node->right);
            node->data = temp->data;
            node->right = deletion(node->right, temp->data);
        }
    }
    return node;
}

void inorder(struct Node* root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() 
{
    int d = 0;
    int ch = 0;
    struct Node* root = NULL;
    struct Node* temp = NULL;

    while (1) {
        printf("Enter 1 to insert a node in the binary tree, 2 to delete a node from the binary tree, 3 to find the maximum number in the binary tree, 4 to find the minimum number in the binary tree, 5 to search for a number in the binary tree, 6 to display the inordertraversal, 7 to display the preorder traversal, 8 to display the post order traversal and 0 to exit the program:\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &d);
                root = insert(root, d);
                break;
            case 2:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("Enter the number to be deleted: ");
                    scanf("%d", &d);
                    root = deletion(root, d);
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    temp = maximum(root);
                    printf("Maximum value: %d\n", temp->data);
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    temp = minimum(root);
                    printf("Minimum value: %d\n", temp->data);
                }
                break;
            case 5:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("Enter the number to be searched: ");
                    scanf("%d", &d);
                    temp = search(root, d);
                    if (temp == NULL)
                        printf("Number not found\n");
                    else
                        printf("Number %d found\n", temp->data);
                }
                break;
            case 6:
                printf("\nThe inorder traversal is: \n");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("\nThe preorder traversal is:\n");
                preorder(root);
                printf("\n");
                break;
            case 8:
                printf("\nThe postorder traversal is:\n");
                postorder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("ERROR. Wrong Input. Try again\n");
        }
    }
    return 0;
}
