/*Implementation of doubly linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* llink;
    struct node* rlink;
};
struct node* root=NULL;

int main()
{
    printf("********************Doubly Linked List****************************\n\n");
    printf("Choose what you want to do\n");
    printf("Enter 1: To add/append a node\n");
    printf("Enter 2: To insert node at beginning\n");
    printf("Enter 3: To display/traverse all data\n");
    printf("Enter 4: To find length\n");
    printf("Enter 5: To delete a node\n");
    printf("Enter 6: To insert node after specified node\n");
    printf("Enter 7: To exit\n");

    while(1)
    {
        int n;
        printf("Enter your choice: ");
        scanf("%d",&n);

        switch(n)
        {
        case 1: Append();
            break;
        case 2: NodeAtBegin();
            break;
        case 3: Display();
            break;
        case 4: {int len = Length();
                printf("Length = %d\n",len);
            break;}
        case 5: Delete();
            break;
        case 6: NodeAfter();
            break;
        case 7: exit(0);
        default: printf("Invalid choice\nEnter again\n");
            break;
        }
    }
    return 0;
}


void Append()
{
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter node data: ");
    scanf("%d",&ptr->data);
    ptr->llink=NULL;
    ptr->rlink=NULL;
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        struct node* x=root;
        while(x->rlink!=NULL)
        {
            x=x->rlink;
        }
        x->rlink=ptr;
        ptr->llink=x;
    }
    printf("Node Added\n");
}


void NodeAtBegin()
{
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter node data: ");
    scanf("%d",&ptr->data);
    ptr->llink=NULL;
    ptr->rlink=NULL;
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        ptr->rlink=root;
        root->llink=ptr;
        root=ptr;
    }
    printf("Node Added\n");
}


void Display()
{
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node* ptr=root;
        printf("Elements: ");
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr=ptr->rlink;
        }
        printf("\n");
    }
}


void Delete()
{
    if(root == NULL)
        printf("List is empty\n");
    else if(Length()==1)
    {
        struct node* ptr=root;
        root=NULL;
        free(ptr);
        printf("Node deleted\n");
    }
    else
    {
        int f,i=1,len=Length();
        printf("Enter node you want to delete: ");
        scanf("%d",f);
        if(f>len)
        {
            printf("Invalid location\n");
            printf("List contain only %d nodes\n",len);
        }
        else{
                struct node* ptr=root,*x;
                while(i<f)
                {
                    ptr=ptr->rlink;
                    i++;
                }
                if(ptr->rlink==NULL)
                {
                  x=ptr->llink;
                  x->rlink=NULL;
                  ptr->llink=NULL;
                  free(ptr);
                }
                else
                {
                    x=ptr->llink;
                    x->rlink=ptr->rlink;
                    ptr->rlink->llink=x;
                    ptr->llink=NULL;
                    ptr->rlink=NULL;
                    free(ptr);
                }
                printf("Node deleted\n");
           }
    }
}


void NodeAfter()
{
    struct node* temp, *p;
    int loc,len,i=1;
    printf("Enter location to add: ");
    scanf("%d",&loc);
    len=Length();
    if(loc>len)
    {
        printf("Invalid location\n");
        printf("List contain only %d nodes\n",len);
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d",&temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        p=root;
        while(i<loc)
        {
            p=p->rlink;
            i++;
        }
        temp->rlink=p->rlink;
        p->rlink->llink=temp;
        temp->llink=p;
        p->rlink=temp;
        printf("Node Added\n");
    }
}


int Length(int x)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        struct node* ptr=root;
        int count=0;
        while(ptr!=NULL)
        {
            ptr=ptr->rlink;
            count++;
        }
        return count;
    }
}

