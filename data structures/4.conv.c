#include <stdio.h>
#define size 30
typedef enum{lparen,rparen,plus,minus,mul,di,mod,po,eos,operand} precedance;
void infix_postfix(char infix[]);
precedance get_token(char *sym,int *n,char infix[]);
void push(precedance token,int *top,int stack[]);
void print_token(precedance t);
precedance pop(int *t,int stack[]);
int main()
{
    char infix[size];
    printf("Enter a valid infix expression:");
    scanf("%s",infix);
    printf("Converted expression is: ");
    infix_postfix(infix);
    printf("\n");
    return 0;
}
void infix_postfix(char infix[])
{
    int isp[]={0,4,1,1,2,2,2,3,0};
    int icp[]={10,4,1,1,2,2,2,3,0};
    int stack[size],top=0,n=0;
    stack[top]=eos;
    char symbol;
    precedance token;
    for(token=get_token(&symbol,&n,infix);token!=eos;token=get_token(&symbol,&n,infix))
    {
        if(token==operand)
            printf("%c",symbol);
        else if(token==rparen)
        {
            while(stack[top]!=lparen)
                print_token(pop(&top,stack));
            pop(&top,stack);
        }
        else
        {
            while(isp[stack[top]]>=icp[token])
                print_token(pop(&top,stack));
            push(token,&top,stack);
        }
    }
    while((token=pop(&top,stack))!=eos)
        print_token(token);
}
precedance get_token(char *sym,int *n,char infix[])
{
    (*sym)=infix[(*n)++];
    switch((*sym))
    {
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '*':return mul;
        case '/':return di;
        case '%':return mod;
        case '^':return po;
        case '\0':return eos;
        default:return operand;
    }
}
void push(precedance token,int *top,int stack[])
{
    stack[++(*top)]=token;
}
void print_token(precedance t)
{
    switch(t)
    {
        case plus:printf("+");
                    break;
        case minus:printf("-");
                    break;
        case mul:printf("*");
                    break;
        case di:printf("/");
                    break;
        case po:printf("^");
                    break;
        case mod:printf("%%");
                    break;
    }
}
precedance pop(int *t,int stack[])
{
    return (stack[(*t)--]);
}