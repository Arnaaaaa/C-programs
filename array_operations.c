#include <stdio.h>
int main() 
{
    int a[100];
    int n=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the values in the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ch=1;
    int p=0;
    int v=0;
    while(ch!=0)
    {
        printf("Enter 1 to create an array of size n and populate it with elements, 2 to insert an element at a specified position in the array, 3 to delete an element from a specified position in the array, 4 to search for an element in the array and return its index, 5 to find the maximum and minimum elements in the array, 6 to display the array and 0 to exit the program: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: n=0;
           printf("Enter the number of elements in the array: ");
           scanf("%d",&n);
           printf("Enter the values in the array: ");
           for(int i=0;i<n;i++)
           {
               scanf("%d",&a[i]);
           }
           break;
           case 2: printf("Enter the value of the number to be inserted: ");
           v=0;
           scanf("%d",&v);
           printf("Enter the position where the element has to be inserted: ");
           p=0;
           scanf("%d",&p);
           for(int i=n-1;i>=p;i--)
           {
               a[i+1]=a[i];
           }
           a[p]=v;
           n++;
           break;
           case 3: printf("Enter the position from where the element is to be deleted: ");
           p=0;
           scanf("%d",&p);
           for(int i=p;i<n;i++)
           {
               a[i]=a[i+1];
           }
           n--;
           break;
           case 4: printf("Enter the element to be searched: ");
           v=0;
           p=0;
           scanf("%d",&v);
           for(int i=0;i<n;i++)
           if(a[i]==v)
           {
               p=i;
               break;
           }
           printf("%d found in %d position of the array\n",v,(p+1));
           break;
           case 5: int max=a[0];
           int min=a[0];
           for(int i=0;i<n;i++)
           {
               if(a[i]>max)
               max=a[i];
               if(a[i]<min)
               min=a[i];
           }
           printf("The maximum element is %d and the minimum element is %d\n",max,min);
           break;
           case 6: printf("The array: \n");
           for(int i=0;i<n;i++)
           {
               printf("%d ",a[i]);
           }
           printf("\n")
           break;
           case 0: break;
           default: printf("ERROR. Try again\n");
        }
    }
    return 0;
}