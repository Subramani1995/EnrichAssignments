# EnrichAssignments
// To print the Odd - Even number triangle

#include<stdio.h>
#include<conio.h>
int main()
{
    int order,i,j,odd=1,even=2;
    scanf("%d",&order);
    for(i=1;i<=order;i=i+2)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",odd);
            odd=odd+2;
        }
        printf("\n");
        for(j=1;j<=(i+1);j++)
        {
            printf("%d ",even);
            even=even+2;
        }
        printf("\n");
    }
    return 0;
}

