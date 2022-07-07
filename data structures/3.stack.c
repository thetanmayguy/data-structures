#include <stdio.h>
int fullstack(int n,int top)
{
    if(top==(n-1))
        return 1;
    return 0;
}
int emptystack(int top)
{
    if(top==-1)
        return 1;
    return 0;
}
void pal()
{
    char st[20],c[20];
    int top=-1,i;
    printf("Enter the text : ");
    scanf("%s",c);
    for(i=0;c[i]!='\0';i++)
        st[++top]=c[i];
    for(i=0;c[i]!='\0';i++)
        if(st[top--]!=c[i])
        {
            printf("The text entered is not a palindrome\n");
            return;
        }
    printf("The text entered is a palindrome\n");
}
void push(int ele,int *top,int st[])
{
    st[++(*top)]=ele;
}
int pop(int *top,int st[])
{
    return (st[(*top)--]);
}
void display(int t,int st[])
{
    for(;t>=0;t--)
        printf("%d ",st[t]);
    printf("\n");
}
int main()
{
    int n,top=-1,st[10],ch,ele;
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    for(;;)
    {
        printf("Menu:-\n1: Push an element\n2: Pop an element\n3: Display\n4: Terminate\n5: Palindrome\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(fullstack(n,top))
                    {
                        printf("Stack is full\n");
                        break;
                    }
                    printf("Enter the element to be pushed : ");
                    scanf("%d",&ele);
                    push(ele,&top,st);
                    break;
            case 2: if(emptystack(top))
                    {
                        printf("Stack is empty\n");
                        break;
                    }
                    printf("The deleted element is %d\n",pop(&top,st));
                    break;
            case 3: if(emptystack(top))
                    {
                        printf("Stack is empty\n");
                        break;
                    }
                    display(top,st);
                    break;
            case 4:return 0;
            case 5:pal();
                    break;
        }
        printf("---------------------------------------\n");
    }
}