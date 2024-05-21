#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};
struct bstnode *create(int val)
{
    struct bstnode *temp;
    temp=(struct bstnode*)malloc(sizeof(struct bstnode));
    if(temp==NULL)
    {
        printf("Memory not allocated!...\n");
        return 0;
    }
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int preorder(struct bstnode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        printf("%d->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return 1;
}
int postorder(struct bstnode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
    }
    return 1;
}
int inorder(struct bstnode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
    }
    return 1;
}
struct bstnode *insert(struct bstnode *root,int val)
{
    if(root==NULL)
    {
        return create(val);
    }
    else if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}
int bstisEmpty(struct bstnode *root)
{
    if(&(root->data)==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getcount(struct bstnode *root)
{
    int c=1;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        c+=getcount(root->left);
        c+=getcount(root->right);
        return c;
    }
}
int main()
{
   struct bstnode *root=NULL;
   int val;
   int c1,c2,c3,c4,c5,c6,c7;
   int choice;
   while(1)
   {
   printf("--------MENU---------\n");
   printf("Enter 1 to create tree.\n");
   printf("Enter 2 to insert value.\n");
   printf("Enter 3 to print in INORDER.\n");
   printf("Enter 4 to print in PREORDER.\n");
   printf("Enter 5 to print in POSTORDER.\n");
   printf("Enter 6 to count no.of nodes in tree.\n");
   printf("Enter 7 to check whether tree is empty or not.\n");
   printf("Enter 8 to exit...\n\n");
   printf("Enter your choice: \n");
   scanf("%d",&choice);
   switch(choice)
   {
        case 1:printf("Enter a value: ");
            scanf("%d",&c1);
            create(c1);
            break;
        case 2:printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 3:
            c3=inorder(root);
            if(c3)
            {
                printf("The inorder traversal is: \n");
            }
            else
            {
                printf("Tree is empty...\n");
            }
            break;
        case 4:printf("The preorder is: \n");
            c4=preorder(root);
            break;
        case 5:printf("The postorder is: \n");
            c5=postorder(root);
            break;
        case 6:c6=getcount(root);
            printf("The no.of nodes in tree: %d\n",c6);
            break;
        case 7:c7=bstisEmpty(root);
            if(c7)
            {
                printf("Tree is empty...\n");
            }
            else
            {
                printf("Tree is not empty...\n");
            }
            break;
        case 8:exit(0);
            break;
        default:printf("Invalid input...Please enter valid input...\n");
   }
   }
}
