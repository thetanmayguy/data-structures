#include <stdio.h>
void pat_search(char pat[],char txt[])
{
	int i,j,m=0,n=0,ctr=0;
	for(m=0;pat[m]!='\0';m++);
	for(n=0;txt[n]!='\0';n++);
	if(m>n)
	{
	    printf("Pattern string is longer than Main string\n");
	    return;
	}
	for (i=0;i<=n-m;i++) 
	{
		for (j=0;j<m; j++)
			if (txt[i+j]!=pat[j])
				break;
		if (j==m)
		{
			printf("Pattern found at index %d \n", i);
			ctr++;
		}
	}
	if(ctr==0)
	    printf("Pattern string is not found in Main string\n");
	else
	    printf("Total occurences of pattern in main string= %d\n",ctr);
}
int main()
{
  char txt[20], pat[10];
  printf("Enter the text:");
  scanf("%[^\n]s",txt);
  getchar();
  printf("Enter the pattern to be searched:");
  scanf("%[^\n]s",pat);
  getchar();
  pat_search(pat,txt);
  return 0;
}