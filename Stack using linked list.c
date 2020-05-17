#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;

int main()
{
    printf("**********Welcome to stack using linked list*************\n\n");
    printf("Choose a option from these\n");
    printf("Enter 1 : To push/insert a element\n");
    printf("Enter 2 : To pop/remove a element\n");
    printf("Enter 3 : To traverse through elements\n");

    while(1)
    {
        int n;
        printf("Your choice: ");
        scanf("%d",&n);

        switch(n)
        {
        case 1: {int x;
                printf("Enter data to be pushed: ");
                scanf("%d",&x);
                push(x);
            break;}
        case 2: { pop();
            break;}
        case 3: traverse();
            break;
        case 4:  exit(0);
        default: printf("Invalid input\n");
            break;
        }
    }
    return 0;
}

void push (int x)
{
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->link=top;
    top=ptr;
    printf("Element pushed\n");
}



void pop()
{
    if (top == NULL)
    {
        printf("No elements\n");
    }
    else
    {
        struct node* ptr=top;
        printf("Popped element: %d\n",ptr->data);
        top=top->link;
        ptr->link=NULL;
        free(ptr);
    }
}


void traverse()
{
    struct node* ptr;
    if (top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        ptr=top;
        printf("Elements in stack: ");
        while(ptr!=NULL)
        {
           printf("%d  ",ptr->data);
           ptr=ptr->link;
        }
        printf("\n");
    }
}
