# EnrichAssignments

Bit count using shift operator

#include<stdio.h>
int main()
{
    int num,i,bitcount=0,k=1;
    scanf("%d",&num);
    while(k!=0)
        {
        k=num>>1;
        num=k;
        bitcount++;
        }
    printf("No of bits required is: %d",bitcount);
    return 0;
}
