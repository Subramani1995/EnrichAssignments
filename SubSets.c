# EnrichAssignments
to determine the subsets of the given array

#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,ans,a[1000][1000]={0},c[100],k=1,y,n,m,x;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&c[i]);
    }
    n=pow(2,m);
    y=n;
    x=1;
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            if((i%y==0)||(i<y))
            {
                x=i;
            }
            else
            {
                x=i%y;
            }

            if(x<=(y/2))
            {
            a[i][j]=0;
            }
            else
            {
            a[i][j]=1;
            }
        }
         y=y/2;
    }
    printf("SUBSET ARRAYS ARE: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            ans=a[i][j]*c[j];
            if(ans!=0)
            {
            printf("%d, ",ans);
            }
        }
        printf("\n");
    }
    return 0;
}

