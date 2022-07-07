#include<stdio.h>
void match(char str[],char pat[],char rep[],char new[],int *m,int *n)
{
    int i=0,j=0,k,l,flag=0;
    while(str[i]!='\0')
    {
        for(j=0,k=i,l=0;(str[k]==pat[j])&&(pat[j]!='\0');k++,j++);
        if(pat[j]=='\0')
        {
            flag=1;
            *m=1;
            while(rep[l]!='\0')
			{
				new[*n]=rep[l];
				l++;
				(*n)++;
			}
        }
        else
            flag=0;
        if(flag==1)
            i=k;
        else
            new[(*n)++]=str[i++];
    }
}
int main()
{
    char str[100],pat[20],rep[20],new[100];
	int m=0,n=0;
	printf("Enter the string: ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter the pattern to be replaced: ");
	scanf("%[^\n]s",pat);
	getchar();
	printf("Enter the replacing string: ");
	scanf("%[^\n]s", rep);
	getchar();
	match(str,pat,rep,new,&m,&n);
	if(m==0)
	{
	    printf("Pattern not found\n");
	    return 0;
	}
	new[n]='\0';
	printf("The new string is: ");
	printf("%s\n",new);
	return 0;
}