// learnt babylonian method from wikipedia. This code converges for any value of 'n' within 5 steps

#include<stdio.h>
#include<math.h>
float seed_value(float );
int main()
{
    int count=0;
    float n;
    scanf("%f",&n);
    double x[10];
    x[0]=seed_value(n);
    printf("Initial value of iteration is %f\n",x[0]);
    int i,j;
    for(i=1;i<10;i++)
    {
        count++;
        x[i]=(float)((0.5)*((x[i-1])+(n/x[i-1])));        
        if(x[i]-x[i-1]==0)
        {
            printf("Square root of the given number is %.3f\nno of steps taken for convergence:%d ",x[i],count);
            break;
        }   
    }
    return 0;
}
float seed_value(float num)
{
    int k=1,bitcount=0;
    float value;
    int number=(int)num;
     while(k!=0)
        {
        k=number>>1;
        number=k;
        bitcount++;
        }
    value=(float)((bitcount-1)/2);
    value=pow(2,value);
    return value;
}
