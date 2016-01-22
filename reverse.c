# EnrichAssignments
to reverse the given number


#include<stdio.h>
int main()
{
    int num,term,rev=0,initial;
    printf("enter number\n");
    scanf("%d",&num);
    for(initial=10;((initial<=num)&&(num%initial==0));initial=initial*10)
    {
        printf("0");
    }
    while(num!=0)
    {
        term=num%10;
        rev=rev*10+term;
        num=num/10;
    }
    printf("%d",rev);
    return 0;
}


