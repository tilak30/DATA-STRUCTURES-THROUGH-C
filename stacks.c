/*Stack implementation using static array*/
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 6

int stack[CAPACITY],top=-1;
void push(int x);
int pop(void);
void display(void);
void peek(void);
int isFull(void);
int isEmpty(void);
int main()
{
    printf("********************Welcome to stacks world!!!******************\n\n\n");
    printf("Please choose any one option from the following:\n\n");
    printf("Enter 1 : To add/push a element on to stack\n");
    printf("Enter 2 : To remove/pop a element from stack\n");
    printf("Enter 3 : To traverse/display all the elements\n");
    printf("Enter 4 : To find peek element\n");
    printf("Enter 5 : To quit\n");
    while(1){
    int n;
    printf("Your choice : ");
    scanf("%d",&n);      printf("\n");
    switch(n)
    {
    case 1: {
              int x;
              printf("No. to add onto stack: ");
              scanf("%d",&x);
              push(x);
        break;
    }
    case 2: {
              int p = pop();
              if (p==0)
                printf("Stack underflow\n\n");
              else
                printf("Popped element: %d\n\n",p);
        break;
    }
    case 3:   display();
        break;
    case 4:   peek();
        break;
    case 5: exit(0);
    default: printf("Invalid input\n\n");

    }
}
    return 0;
}


void push(int x)
{
    if (isFull()==0){
        printf("Stack Overflow\n\n");
    }
    else{
            top++;
        stack[top]=x;
        printf("Pushed element: %d\n\n",stack[top]);
    }
}


int pop()
{
    if(isEmpty()==0)
        return 0;
    else{
        return stack[top-- ];
    }
}



void display()
{
    if(isEmpty()==0){
        printf("Stack is empty\n\n");
    }
    else{
            int ptr=top;
           printf("Elements: \n");
        while(ptr>=0){
            printf("%d  ",stack[ptr]);
            ptr--;
        }
        printf("\n\n");
    }
}



void peek()
{
    if (isEmpty()==0)
        printf("Stack is Empty\n\n");
    else
        printf("Peek element = %d\n\n",stack[top]);
}


int isFull()
{
    if (top==CAPACITY-1)
        return 0;
    else
        return 1;
}


int isEmpty()
{
    if (top==-1)
        return 0;
    else
        return 1;
}
