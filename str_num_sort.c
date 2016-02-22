//program to sort the numbers (input is given as 2D String)
#include<stdio.h>
#include<string.h>
#include<math.h>
void str_to_num(char [],int [],int);
int main()
{
    char *str[]={"1234","10000","323","0","12"};
    int num_array[20]={0};
    int n=5,k=0;
    int i,j,temp;
    for(i=0;i<n;i++)   
    {
        str_to_num(str[i],num_array,k);
        k++;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num_array[j]<num_array[i])
            {
                temp=num_array[i];
                num_array[i]=num_array[j];
                num_array[j]=temp;
            }
        }
    }
    printf("sorted array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",num_array[i]);
    }
    return 0;
}
void str_to_num(char str[],int num_array[],int k)
{
    int digit_array[20]={0},number=0;
    int i,j,digit_length=0;
    for(i=0;str[i]!=0;i++)
    {
        digit_length++;
    }
    i=0;
    while(digit_length--)
    {
        digit_array[i]=str[i]-48;
        number=number+(digit_array[i]*(pow(10,digit_length)));
        i++;
    }
    num_array[k]=number;   
}
