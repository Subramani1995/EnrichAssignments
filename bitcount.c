# EnrichAssignments
to find bit count


#include<stdio.h>
int main()
{
    int num,i,bitcount=0;
    scanf("%d",&num);
    while(num!=0)
    {
        i=num%2;
        bitcount++;
        num=num/2;
    }
    printf("No of bits required is: %d",bitcount);
    return 0;
}
