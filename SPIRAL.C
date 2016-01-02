/* # EnrichAssignments
to print the matrix elements in spiral order */


#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10][10],i,j,m,n,k,x,y,l,count;
    scanf("%d%d",&m,&n);
    count=m*n;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
printf(" The given matrix is:\n");
     for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("SPIRAL ELEMENTS ARE \n");

    if((m==1)||(n==1))
    {
            for(i=1;i<=m;i++)
            {
                for(j=1;j<=n;j++)
                {
                    printf("%d ",a[i][j]);
                }
                printf("\n");
            }
    }
    else
    {
        x=1;
        i=1;
        y=1;
        while(count--)
        {
            for(j=y;j<=n;j++)
            {
                printf("%d ",a[i][j]);
            }
            j--;
            for(i=(x+1);i<=m;i++)
            {
                printf("%d ",a[i][j]);
            }
            i--;
            for(j=(n-1);j>=x;j--)
            {
            if(i!=x)
                printf("%d ",a[i][j]);
            }
            j=y;
            for(i=(m-1);i>x;i--)
            {
                printf("%d ",a[i][j]);
            }
            i++;
            x++;
            y++;
            m--;
            n--;
            if((x>m)||(y>n)||(m<=0)||(n<=0))
            {
                break;
            }
        }
    }
return 0;
}

