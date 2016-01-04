# EnrichAssignments
//To print the number triangle

#include<stdio.h>
#include<conio.h>
int main()
{
int order,i,j,num=1;
scanf("%d",&order);
for(i=1;i<=order;i++)
{
    for(j=1;j<=i;j++)
    {
        printf("%d ",num);
        num++;
    }
    printf("\n");
}
return 0;
}

