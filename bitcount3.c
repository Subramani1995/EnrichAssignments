to perform bitcount without using arithmetic/shift operations

#include<stdio.h>
#include<math.h>
int main()
{
    int num,i,bitcount=1,j=0;
    scanf("%d",&num);
    for(i=0;(pow(2,i))<=num;i++)
    {
    }
    i=(num==0)?1:i;
    printf("No of bits required is: %d",i);
    return 0;
