# EnrichAssignments
To Determine the transpose of the given matrix without using swapping or additional matrix


#include<stdio.h>
#include<conio.h>
void printArray(int,int,int[10][10]);
int main()
{
    int i,j,temp,row,column,x;
    printf("\n enter row size and column size\n");
    scanf("%d%d",&row,&column);
    int a[10][10]={0};
    printf("\n enter elements \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n The given matrix is \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<=column;i++)
    {
        for(j=i+1;j<=row;j++)
        {
            x=a[i][j];
            a[i][j]=a[i][j]+a[j][i]-a[i][j];
            a[j][i]=a[j][i]+x-a[j][i];
        }
    }
    printArray(row,column,a);
    return 0;
}
void printArray(int row,int column,int a[10][10])
{
    int i,j;
    printf("\n transpose \n");
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
