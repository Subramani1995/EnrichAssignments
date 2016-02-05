#include<stdio.h>
#include<math.h>
int main()
    {
    int prime[1000],i,k=0,j,flag,n=1000;
    
    for(i=2;i<=1000;i++)
        {
        prime[i]=i;
    }
    for(i=2;i<sqrt(n);i++)
        {
        if(prime[i]!=0)
            {
        for(j=(i*i);j<n;j=((i*i)+k*i))
            {
         prime[j]=0;   
            k++;
        }
        }
        k=0;
    }
    for(i=2;i<1000;i++)
        {
        if(prime[i]!=0)
            printf("%d ",prime[i]);
    }
}
