#include <stdio.h>
typedef struct employee
{
    int eno;
    char name[20];
    int sal;
}emp;
int main()
{
    emp e;
    FILE *fp;
    int n,i,s=(2*sizeof(int)+20),minusone=-1,ch,flag,index,indexcopy,id;
    printf("Enter the no. of records: ");
    scanf("%d",&n);
    fp=fopen("emp.txt","w+");
    for(i=0;i<n;i++)
    {
        fwrite(&minusone,sizeof(int),1,fp);
        fseek(fp,s-sizeof(int),SEEK_CUR);
    }
    while(1)
    {
        printf("<Menu>:-\n1 :Add record\n2 :Display records\n3 :Terminate\n");
        scanf("%d",&ch);
        flag=0;
        switch(ch)
        {
            case 1: printf("Enter the record : ");
                    scanf("%d %s %d",&e.eno,e.name,&e.sal);
                    index=indexcopy=(e.eno%n);
                    fseek(fp,s*index,SEEK_SET);
                    fread(&id,sizeof(int),1,fp);
                    while(id!=-1)
                    {
                        index++;
                        fseek(fp,s*index,SEEK_SET);
                        flag=1;
                        if(index==n)
                        {
                            index=0;
                            fseek(fp,s*index,SEEK_SET);
                        }    
                        if(index==indexcopy)
                        {
                            printf("File Full\n");
                            break;
                        }
                        fread(&id,sizeof(int),1,fp);
                    }
                    if(!((index==indexcopy)&&flag))
                    {
                        fseek(fp,s*index,SEEK_SET);
                        fwrite(&e,sizeof(emp),1,fp);
                    }
                    break;
            case 2: printf("Records are:-\n");
                    for(index=0;index<n;index++)
                    {
                        fseek(fp,s*index,SEEK_SET);
                        fread(&e.eno,sizeof(int),1,fp);
                        printf("%d\t",e.eno);
                        if(e.eno!=-1)
                        {
                            fread(e.name,20,1,fp);
                            fread(&e.sal,sizeof(int),1,fp);
                            printf("%s\t%d\n",e.name,e.sal); 
                        }
                        else
                            printf("\n");
                    }
                    break;
            case 3: fclose(fp);
                    return 0;
            default: printf("Enter a number between 1-3\n");
                     break;
        }
        printf("------------------------------------------------------\n");
    }
}