#include <stdio.h>
#include <math.h>
#include <ctype.h>
int eval(char s[]);
void push(int ele,int *top,int st[]);
int pop(int *top,int st[]);
int comp(int a,int b,char c);
void toh(int n,char s,char t,char d)
{
    if(n==0)
        return;
    toh(n-1,s,d,t);
    printf("Move disc %d from %c to %c\n",n,s,d);
    toh(n-1,t,s,d);
}
int main()
{
    char postfix[15];
    int n;
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    printf("The evaluation result is %d\n",eval(postfix));
    printf("Enter the no. of discs : ");
    scanf("%d",&n);
    toh(n,'a','b','c');
    return 0;
}
int eval(char s[])
{
    int i=0,top=-1,st[10],tok,res,a,b;
    char sym;
    while(s[i]!='\0')
    {
        sym=s[i];
        if(isdigit(sym))
        {
            tok=sym-'0';
            push(tok,&top,st);
        }
        else
        {
            b=pop(&top,st);
            a=pop(&top,st);
            res=comp(a,b,sym);
            push(res,&top,st);
        }
        i++;
    }
    return (pop(&top,st));
}
void push(int ele,int *top,int st[])
{
    st[++(*top)]=ele;
}
int pop(int *top,int st[])
{
    return (st[(*top)--]);
}
int comp(int a,int b,char c)
{
    switch(c)
    {
        case '+':return (a+b);
        case '-':return (a-b);
        case '*':return (a*b);
        case '/':return (a/b);
        case '%':return (a%b);
        case '^':return (pow(a,b));
    }
}