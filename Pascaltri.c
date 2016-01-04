# EnrichAssignments
// To print the pascal number triangle

#include<stdio.h>
#include<conio.h>
int main()
{
    int order,i,j,arr[10][10]={0};
    scanf("%d",&order);
    arr[0][0]=1;
    for(i=1;i<=order;i++)
    {
        for(j=1;j<=i;j++)
        {
           arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

