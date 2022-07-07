#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
    int data;
    struct bst *llink;
    struct bst *rlink;
}tnode;
tnode *get_node()
{
    tnode* temp=(tnode*)malloc(sizeof(tnode));
    if(temp==NULL)
        printf("No memory\n");
    return temp;
}
tnode *insert(int ele,tnode* root)
{
    tnode* pres=NULL,*prev=NULL;
    tnode *new=get_node();
    new->data=ele;
    new->llink=new->rlink=NULL;
    if(root==NULL)
        return new;
    pres=root;
    while(pres!=NULL)
    {
        prev=pres;
        if(new->data<pres->data)
            pres=pres->llink;
        else if(new->data>pres->data)
            pres=pres->rlink;
        else
        {
            printf("Duplicates not allowed in BST\n");
            free(new);
            return root;
        }
    }
    if(new->data<prev->data)
        prev->llink=new;
    else
        prev->rlink=new;
    return root;
}
void inorder(tnode *root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}
void preorder(tnode *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(tnode *root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->data);
    }
}
int search(int key,tnode* root)
{
    tnode* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)
            return 1;
        else if(temp->data>key)
            temp=temp->llink;
        else
            temp=temp->rlink;
    }
    return 0;
}
int main()
{
    tnode* root=NULL;
    int ch,ele;
    for(;;)
    {
        printf("------------------------------------------------\n");
        printf("Menu:-\n1: Insert an element to BST\n2: Obtain Inorder traversal\n3: Obtain Preorder traversal\n4: Obtain Postorder traversal\n");
        printf("5: Search for an element\n6: Terminate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to be inserted:");
                    scanf("%d",&ele);
                    root=insert(ele,root);
                    break;
            case 2:printf("Inorder traversal: <");
                    inorder(root);
                    printf(">\n");
                    break;
            case 3:printf("Preorder traversal: <");
                    preorder(root);
                    printf(">\n");
                    break;
            case 4:printf("Postorder traversal: <");
                    postorder(root);
                    printf(">\n");
                    break;
            case 5:printf("Enter the element to be searched:");
                    scanf("%d",&ele);
                    if(search(ele,root))
                        printf("The key element is found\n");
                    else
                        printf("The key element is not found\n");
                    break;
            case 6:return 0;
            default:printf("Enter a number between 1 and 6\n");
                    break;
        }
    }
    return 0;
}