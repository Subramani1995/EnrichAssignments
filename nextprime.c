#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end;
    double time_taken;
    start=clock();
    int num,k=1,prime[1000],i,j,flag=0,count=0;
    prime[0]=2;
    scanf("%d",&num);
    if((num==0)||(num==1))
    {
        printf("Next prime number is 2");
    }
    else
    {
    for(i=3;;i=i+2)
    {
        for(j=0;j<k;j++)
        {
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
        if((flag==0))
        {
            prime[k]=i;
            k++;
            if(i>num)
            {
                printf("Next prime number is %d",i);
                break;
            }
        }
    }
    }    
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken for execution of my code is %f sec",time_taken);
    return 0;
}
