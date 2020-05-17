#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int queue[CAPACITY];
int front=0,rear=0;

int main()
{
    printf("************Queue implementation***************\n\n");
    printf("Choose what you want to do\n");
    printf("Enter 1: To insert\n");
    printf("Enter 2: To delete\n");
    printf("Enter 3: To display\n");
    printf("Enter 4: To quit\n");
    while(1)
    {
        int n;
        printf("Enter a no: ");
        scanf("%d",&n);

        switch(n)
        {
        case 1:  insert();
            break;
        case 2:  del();
            break;
        case 3:  display();
            break;
        case 4: exit(0);
        default:  printf("Invalid input");
            break;
        }
    }
    return 0;
}


void insert()
{
    if(rear==CAPACITY)
        printf("Queue is full\n");
    else
    {
        int x;
        printf("Enter data: ");
        scanf("%d",&x);
        queue[rear] = x ;
        rear++;
    }
}


void del()
{
   if (front==rear)
   {
         printf("Queue is empty\n");
   }
   else
   {
       for(int i=0 ; i<rear ; i++)
       {
           queue[i]=queue[i+1];
       }
       rear--;
       printf("Element deleted\n");
   }
}


void display()
{
    if(front == rear )
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i=0 ; i<rear ; i++)
        {
            printf("%d  ",queue[i]);
        }
        printf("\n");
    }
}
