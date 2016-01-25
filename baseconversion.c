//To convert the given number into requested base


#include<stdio.h>
void convert(int ,int );
int main()
{
    int num,base;
    printf("enter num:\n");
    scanf("%d",&num);
    printf("\nenter base:\n");
    scanf("%d",&base);
    convert(num,base);
    return 0;
}
void convert(int num,int base)
{
    int i=0,j,value;
    char ans[100];
    while(num!=0)
    {
        value=num%base;
        if(value<10)
        {
            ans[i]=value+'0';
        }
        else
        {
            ans[i]=value+55;
        }
        i++;
        num=num/base;
    }
    printf("Converted number is :\n");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",ans[j]);
    }
}
