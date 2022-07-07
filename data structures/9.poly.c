#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct pol
{
    float cf;
    int x,y,z;
    struct pol *link;
}poly;
poly* get_node()
{
    poly *temp=(poly*)malloc(sizeof(poly));
    if(temp==NULL)
        printf("No memory\n");
    return temp;
}
void read_poly(int n,poly *h)
{
    poly *temp=h,*new=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        new=get_node();
        scanf("%f %d %d %d",&new->cf,&new->x,&new->y,&new->z);
        temp->link=new;
        temp=temp->link;
    }
    temp->link=h;
}
void print_poly(poly *h)
{
    poly *temp=h->link;
    while(temp!=h)
    {
        printf(" +%.2fx^(%d)y^(%d)z^(%d)",temp->cf,temp->x,temp->y,temp->z);
        temp=temp->link;
    }
    printf("\n");
}
int comp(poly *t1,poly *t2)
{
    if((t1->x==t2->x)&&(t1->y==t2->y)&&(t1->z==t2->z))
        return 1;
    return 2;
}
void attach(int cf,poly *temp,poly **tres)
{
    poly *new=get_node();
    new->cf=cf;
    new->x=temp->x;
    new->y=temp->y;
    new->z=temp->z;
    (*tres)->link=new;
    (*tres)=new;
}
poly *delete(poly *h,poly *t)
{
    poly *temp=h;
    while((temp->link)!=t)
        temp=temp->link;
    temp->link=t->link;
    free(t);
    return h;
}
poly *add_poly(poly *h1,poly *h2)
{
    poly *temp1=h1->link,*temp2=NULL,*res=get_node(),*tempres=res;
    float sum;
    while(temp1!=h1)
    {
        temp2=h2->link;
        while(temp2!=h2)
        {
            switch(comp(temp1,temp2))
            {
                case 1: sum=(temp1->cf)+(temp2->cf);
                        attach(sum,temp1,&tempres);
                        h2=delete(h2,temp2);
                        temp2=h2->link;
                        temp1=temp1->link;
                        break;
                case 2: temp2=temp2->link;
                        break;
            }
        }
        if(temp1!=h1)
        {
            attach(temp1->cf,temp1,&tempres);
            temp1=temp1->link;
        }
    }
    temp2=h2->link;
    while(temp2!=h2)
    {
        attach(temp2->cf,temp2,&tempres);
        temp2=temp2->link;
    }
    tempres->link=res;
    return res;
}
void eval(poly *h)
{
    poly *temp=h->link;
    float sum=0;
    int x,y,z;
    printf("Enter x,y,z values : ");
    scanf("%d %d %d",&x,&y,&z);
    while(temp!=h)
    {
        sum+=(temp->cf)*pow(x,temp->x)*pow(y,temp->y)*pow(z,temp->z);
        temp=temp->link;
    }
    printf("The evaluation result is: %.2f",sum);
}
int main()
{
    int n1,n2;
    poly *h1=get_node(),*h2=get_node(),*h3=get_node();
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;
    printf("Enter no. of terms in 1st and 2nd polynomials: ");
    scanf("%d %d",&n1,&n2);
    printf("Enter the terms of 1st polynomial: ");
    read_poly(n1,h1);
    printf("Enter the terms of 2nd polynomial: ");
    read_poly(n2,h2);
    h3=add_poly(h1,h2);
    printf("The result of polynomial addition is: ");
    print_poly(h3);
    eval(h3);
    return 0;
}