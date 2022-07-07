#include <stdio.h>
#include <stdlib.h>
typedef struct dll
{
    int ssn;
    char name[10];
    char dept[10];
    char des[10];
    float sal;
    long int ph;
    struct dll *llink;
    struct dll *rlink;
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
    printf("Enter the details : ");
    scanf("%d %s %s %s %f %ld",&new->ssn,new->name,new->dept,new->des,&new->sal,&new->ph);
    printf("1\n");
    new->llink=NULL;
    printf("2\n");
    new->rlink=first;
    printf("3\n");
    return new;
}
node *insr(node *first)
{
    node *new=get_node(),*temp=first;
    printf("Enter the details : ");
    scanf("%d %s %s %s %f %ld",&new->ssn,new->name,new->dept,new->des,&new->sal,&new->ph);
    new->rlink=new->llink=NULL;
    if(first==NULL)
        return new;
    while(temp->rlink!=NULL)
        temp=temp->rlink;
    temp->rlink=new;
    new->llink=temp;
    return first;
}
node *delf(node *first)
{
    node *temp=first;
    printf("The deleted entry is: %d %s %s %s %f %ld\n",temp->ssn,temp->name,temp->dept,temp->des,temp->sal,temp->ph);
    first=first->rlink;
    first->llink=NULL;
    free(temp);
    return first;
}
node *delr(node *first)
{
    node *prev=NULL,*pres=first;
    if(first->rlink==NULL)
    {
        printf("The deleted entry is: %d %s %s %s %f %ld\n",first->ssn,first->name,first->dept,first->des,first->sal,first->ph);
        free(first);
        return NULL;
    }
    while(pres->rlink!=NULL)
    {
        prev=pres;
        pres=pres->rlink;
    }
    printf("The deleted entry is: %d %s %s %s %f %ld\n",pres->ssn,pres->name,pres->dept,pres->des,pres->sal,pres->ph);
    prev->rlink=NULL;
    free(pres);
    return first;
}
void display(node *first)
{
    node *temp=NULL;
    int n=0;
    for(temp=first;temp!=NULL;temp=temp->rlink,n++);
    printf("The no. of nodes in the list is: %d\n",n);
    printf("ssn\tname\tdept\tdes\tsal\tphno\n");
    for(temp=first;temp!=NULL;temp=temp->rlink)
        printf("%d\t%s\t%s\t%s\t%.2f\t%ld\n",temp->ssn,temp->name,temp->dept,temp->des,temp->sal,temp->ph);
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
                    printf("1\n");
                    break;
            case 2: first=insr(first);
                    break;
            case 3: if(first==NULL)
                    {
                        printf("The list is empty\n");
                        break;
                    }
                    first=delf(first);
                    break;
            case 4: if(first==NULL)
                    {
                        printf("The list is empty\n");
                        break;
                    }
                    first=delr(first);
                    break;
            case 5: if(first==NULL)
                    {
                        printf("The list is empty\n");
                        break;
                    }
                    display(first);
                    break;
            case 6:return 0;
            default: printf("Enter a number between 1 and 6\n");
                     break;
        }
        printf("-------------------------------------\n");
    }
}