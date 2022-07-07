#include <stdio.h>
#define size 6
void ins(char c,int *r,int *ctr,char cq[])
{
    (*r)=((*r)+1)%size;
    cq[*r]=c;
    (*ctr)++;
}
char del(int *f,int *ctr,char cq[])
{
    char d=cq[*f];
    (*f)=((*f)+1)%size;
    (*ctr)--;
    return d;
}
void display(int f,int ctr,char cq[])
{
    int i;
    for(i=0;i<ctr;i++)
    {
        printf("%c ",cq[f]);
        f=(f+1)%size;
    }
    printf("\n");
}
int main()
{
    char cq[size],c;
    int ch,ctr=0,f=0,r=-1;
    for(;;)
    {
        printf("Menu:-\n1: Insert\n2: Delete\n3: Display\n4: Terminate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(ctr==size)
                    {
                        printf("Queue is full\n");
                        break;
                    }
                    printf("Enter the element to be inserted : ");
                    scanf(" %c",&c);
                    ins(c,&r,&ctr,cq);
                    break;
            case 2: if(ctr==0)
                    {
                        printf("Queue is empty\n");
                        break;
                    }
                    printf("The deleted element is : %c\n",del(&f,&ctr,cq));
                    break;
            case 3: if(ctr==0)
                    {
                        printf("Queue is empty\n");
                        break;
                    }
                    display(f,ctr,cq);
                    break;
            case 4: return 0;
            default: printf("Enter a number between 1 and 4\n");
                     break;
        }
        printf("---------------------------------------\n");
    }
}