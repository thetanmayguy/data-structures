#include <stdio.h>
#include <stdlib.h>
typedef struct n
{
    char usn[13];
    char name[10];
    char branch[10];
    int sem;
    long int ph;
    struct n *link;
}node;
node *get_node()
{
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
        printf("No memory\n");
    return temp;
}
node *insf(node *first)
{
    node *new=get_node();
    printf("Enter the details: ");
    scanf("%s %s %s %d %ld",new->usn,new->name,new->branch,&new->sem,&new->ph);
    new->link=first;
    return new;
}
node *insr(node *first)
{
    node *new=get_node(),*temp=NULL;
    printf("Enter the details: ");
    scanf("%s %s %s %d %ld",new->usn,new->name,new->branch,&new->sem,&new->ph);
    new->link=NULL;
    if(first==NULL)
        return new;
    for(temp=first;temp->link!=NULL;temp=temp->link);
    temp->link=new;
    return first;
}
node *delf(node *first)
{
    node *temp=first;
    first=first->link;
    printf("The deleted entry is : %s %s %s %d %ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->ph);
    free(temp);
    return first;
}
node *delr(node *first)
{
    node *prev=NULL,*pres=first;
    if(first->link==NULL)
    {
        printf("The deleted entry is : %s %s %s %d %ld\n",first->usn,first->name,first->branch,first->sem,first->ph);
        free(first);
        return NULL;
    }
    while(pres->link!=NULL)
    {
        prev=pres;
        pres=pres->link;
    }
    printf("The deleted entry is : %s %s %s %d %ld\n",pres->usn,pres->name,pres->branch,pres->sem,pres->ph);
    prev->link=NULL;
    free(pres);
    return first;
}
void display(node *first)
{
    node *temp=NULL;
    int n=0;
    for(temp=first;temp!=NULL;temp=temp->link,n++);
    printf("There are %d nodes in the list\n",n);
    printf("usn\t\tname\tbranch\tsem\tph.no.\n");
    for(temp=first;temp!=NULL;temp=temp->link)
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->ph);
}
int main()
{
    node *first=NULL;
    int ch;
    for(;;)
    {
        printf("Menu:-\n1: Insert front\n2: Insert rear\n3: Delete front\n4: Delete rear\n5: Display\n6: Terminate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first=insf(first);
                    break;
            case 2: first=insr(first);
                    break;
            case 3: if(first==NULL)
                    {
                        printf("List is empty\n");
                        break;
                    }
                    first=delf(first);
                    break;
            case 4: if(first==NULL)
                    {
                        printf("List is empty\n");
                        break;
                    }
                    first=delr(first);
                    break;
            case 5: if(first==NULL)
                    {
                        printf("List is empty\n");
                        break;
                    }
                    display(first);
                    break;
            case 6: return 0;
            default: printf("Enter a number between 1 and 6\n");
                    break;
        }
        printf("------------------------------------\n");
    }
}