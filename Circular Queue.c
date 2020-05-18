#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int cqueue[SIZE];
int front = -1, rear = -1;

int main()
{
    printf("****************Implementation of circular queue************************\n\n");
    printf("Choose operation\n");
    printf("Enter 1: To insert\n");
    printf("Enter 2: To delete\n");
    printf("Enter 3: To display\n");

    while(1)
    {
        int n;
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:insert();
            break;
        case 2:del();
            break;
        case 3: display();
            break;
        case 4: exit(0);
        default: printf("Invalid choice\nTry again\n");
            break;
        }
    }

    return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}


void insert() {
    int element;
    printf("Enter element: ");
    scanf("%d",&element);
  if (isFull())
    printf("\n Queue is full!! \n");
  else if(front == -1 && rear==-1){
                front=rear=0;
                cqueue[rear]=element;
            printf("\n Inserted -> %d\n", element);
         }
  else if(rear==SIZE-1)
  {
      rear=0;
      cqueue[rear]=element;
  }
  else
  {
      rear++;
      cqueue[rear]=element;
  }
}

void del() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  }
  else if(front == rear)
  {
      element=cqueue[front];
      front=rear=-1;
      printf("\n Deleted element -> %d \n", element);
  }
  else if(front==SIZE-1)
  {
      element=cqueue[front];
      front=0;
      printf("\n Deleted element -> %d \n", element);
  }
  else{
    element=cqueue[front];
    front++;
    printf("\n Deleted element -> %d \n", element);
  }

}


void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
   printf("Queue is empty\n");
}
else if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cqueue[front_pos]);
front_pos++;
}
else
{
while(front_pos <= SIZE-1)
{
printf("%d ",cqueue[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d ",cqueue[front_pos]);
front_pos++;
}
}
printf("\n");
}


