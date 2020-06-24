/* BINARY SEARCH TREE IMPLEMENTATION*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void add_node();
struct node* Delete(struct node *root, int x);
struct node* find_minimum(struct node *root);
void in_order(struct node* temp);
void pre_order(struct node* temp);
void post_order(struct node* temp);

int main()
{
    printf("*****************Welcome!!! To Binary Search Tree Implementation****************\n\n");
    printf("Choose one option you want to perform: \n");
    printf("Enter 1: To add a node\n");
    printf("Enter 2: To delete a node\n");
    printf("Enter 3: For in-order display/traversal\n");
    printf("Enter 4: For pre-order display/traversal\n");
    printf("Enter 5: For postorder display/traversal\n");
    printf("Enter 6: To exit\n");

    while(1){
        printf("Enter your choice: "); int n; scanf("%d",&n);

        switch(n){
            case 1: add_node();
                break;
            case 2: {
                    printf("Enter data to delete\n");
                    int d;
                    scanf("%d",&d);;
                    root=Delete(root,d);
                break;}
            case 3: in_order(root);
                break;
            case 4: pre_order(root);
                break;
            case 5: post_order(root);
                break;
            case 6: exit(0);
                break;
            default: printf("Enter a valid choice");
                break;
        }
    }
}

void add_node()
{
    printf("Enter data to enter: ");
    int d;
    scanf("%d",&d);
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->left=temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* current=root,*p;
        while(current){
            p=current;
            if(p->data>d){
                current=current->right;
            }
            else{
                current=current->left;
            }
        }
        if(p->data>d){
            p->right=temp;
        }
        else{
            p->left=temp;
        }
    }
}

struct node* Delete(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = Delete(root->right, x);
    else if(x<root->data)
        root->left = Delete(root->left, x);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum(root->left); // left most element will be minimum
    return root;
}

void in_order(struct node* temp)
{
    if(temp){
        in_order(temp->left);
        printf("%d ",temp->data);
        in_order(temp->right);
    }
}

void pre_order(struct node* temp)
{
    if(temp){
        printf("%d ",temp->data);
        in_order(temp->left);
        in_order(temp->right);
    }
}

void post_order(struct node* temp)
{
    if(temp){
        in_order(temp->left);
        in_order(temp->right);
        printf("%d ",temp->data);
    }
}




