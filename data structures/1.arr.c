#include <stdio.h>
#define SIZE 100
void read_arr(int n,int a[]);
void ins_ele(int *n,int a[]);
void del_ele(int *n,int a[]);
void trav_arr(int n,int a[]);
int main()
{
    int n,a[SIZE],ch;
    printf("Enter the no. of array elements:");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    read_arr(n,a);
    for(;;)
    {
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to terminate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:ins_ele(&n,a);
                    break;
            case 2:del_ele(&n,a);
                    break;
            case 3:trav_arr(n,a);
                    break;
            case 4:return 0;
            default:printf("Enter a number between 1-4!!\n");
                    break;
        }
    }
    return 0;
}
void read_arr(int n,int a[])
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    return;
}
void ins_ele(int *n,int a[])
{
    int i,pos,new;
    printf("Enter the position for insertion:");
    scanf("%d",&pos);
    if((pos>0)&&(pos<=(*n)+1))
    {
        printf("Enter the new element:");
        scanf("%d",&new);
        for(i=(*n);i>pos-1;i--)
            a[i]=a[i-1];
        a[i]=new;
        (*n)++;
    }
    else
        printf("Insertion not possible\n");
    return;
}
void del_ele(int *n,int a[])
{
    int i,pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos>0&&pos<=(*n))
    {
        printf("The deleted element is %d\n",a[pos-1]);
        for(i=pos;i<(*n)-1;i++)
            a[i]=a[i+1];
        (*n)=(*n)-1;
    }
    else
        printf("Deletion not possible\n");
    return;
}
void trav_arr(int n,int a[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}