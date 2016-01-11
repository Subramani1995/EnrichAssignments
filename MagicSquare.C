# EnrichAssignments
to print the magic square for given n

#include<stdio.h>
int main()
{
    int i,j,n,a[100][100]={0},k=1,sqr,centre;
    scanf("%d",&n);
    sqr=n*n;
    centre=(n/2)+1;
    a[1][centre]=k;
    i=1;j=centre;
    k++;
    while(k<=sqr)
    {
            if((i==1)&&(j==n))
            {
                i=i+1;
                a[i][j]=k++;
                continue;
            }
            else if(i==1)
            {
                i=n+1;
            }
            else if(j==n)
            {
                j=0;
            }
            if(a[i-1][j+1]==0)
            {
                a[i-1][j+1]=k++;
                i--;
                j++;
            }
            else
            {
                i=i+1;
                a[i][j]=k++;
            }
    }
    printf("MAGIC SQUARE : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           printf("%d ",a[i][j]);
        }
       printf("\n");
    }
   return 0;
}

