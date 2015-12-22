# GaussJordan
To calculate diagonal matrix using Gauss Jordan method

#include<stdio.h>
#include<conio.h>
int main()
{
float a[100][100];
int i,j,k,x,y,n_size,z;
float pro=1;
float b[100][100];
printf("\n enter the size of matrix\n");
scanf("%d",&n_size);
printf("\n enter elements of matrix\n");
for(i=1;i<=n_size;i++)
    {
    for(j=1;j<=n_size;j++)
        {
        scanf("%f",&a[i][j]);
        }
    }
k=1;
x=2;
y=1;
for(k=1;k<n_size;k++)
    {
    for(i=x;i<=n_size;)
        {
            for(j=1;j<=n_size;j++)
                {
                    b[i][j]=a[i][j];
                    b[k][j]=a[k][j]*(b[i][k]/a[k][k]);
                }

            for(j=1;j<=n_size;j++)
                {
                    a[i][j]=b[i][j]-b[k][j];
                }
i++;
if(i>n_size)
{
    x++;
    i=x;
    k++;
    y++;
}
if(k==n_size)
{
    break;
}
}
}
printf("    UPPER TRIANGULAR MATRIX USING GAUSS ELIMINATION     \n");
for(i=1;i<=n_size;i++)
    {
        for(j=1;j<=n_size;j++)
            {
                printf("%f ",a[i][j]);
                if(i==j)
                {
                    pro=pro*a[i][j];
                }
            }
            printf("\n");
    }
    printf("\ndeterminant is %f\n",pro);




z=n_size;
k=n_size;
y=n_size;
x=1;
for(;k>1;)
{
    for(i=x;i<=n_size;)
    {
        for(j=1;j<=n_size;j++)
        {
            b[k][j]=a[k][j];
            b[i][j]=a[i][j]*(a[k][k]/a[i][k]);
        }
        for(j=1;j<=n_size;j++)
        {
            a[i][j]=b[i][j]-b[k][j];
        }

    i++;
    if(i==z)
    {
        i=1;
        z=n_size-1;
        k--;
        y--;
    }
    if(k==1)
    {
        break;
    }
    }
    break;
}
printf("\n    DIAGONAL MATRIX USING GAUSS JORDAN ELIMINATION     \n");
pro=1;
for(i=1;i<=n_size;i++)
    {
        for(j=1;j<=n_size;j++)
            {
                printf("%f ",a[i][j]);
                if(i==j)
                {
                    pro=pro*a[i][j];
                }
            }
            printf("\n");
    }


    return 0;
    getch();
}

