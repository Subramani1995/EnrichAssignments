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
    num++;
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
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken for execution of my code is %f",time_taken);
    printf("\nno of iterations is %d",count);
    return 0;
}
