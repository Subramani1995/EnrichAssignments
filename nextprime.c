//to find next prime number

#include<stdio.h>
int main()
{
    int num,k=1,prime[1000],i,j,flag=0,count=0;
    prime[0]=2;
    scanf("%d",&num);
    if((num==0)||(num==1))
    {
        printf("Next prime number is 2");
    }
    else
    {
    for(i=3;i<(num);i=i+2)
    {
        for(j=0;j<k;j++)
        {
            count++;
            if(i%prime[j]==0)
            {
                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            prime[k]=i;
            k++;
        }
    }
    int check=0,value,l;
    value=(num%2==0)?1:0;
    for(i=num+value;;i=i+2)
    {
        for(l=0;l<k;l++)
        {
            count++;
            if(i%prime[l]==0)
            {
                check=1;
                break;
            }
            else
            {
                check=0;
            }           
        }
        if(check==0)
        {
            printf("Next prime number is %d",i);
            break;
        }
    }
    }
    printf("\nno of iterations is %d",count);
    return 0;
}
