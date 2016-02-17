// To find the next palindrome


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n1,i=0,count=0,a[20]={0},j,x,val,max,flag=0,b[10]={0},k,n,ans=0;
    scanf("%d",&n1);
    if((n1==9)||(n1==99)||(n1==999)||(n1==9999))
    {
        printf("%d",n1+2);
    }
    else
    {
        n=n1;
     // to find length of the number
        while(n!=0)
        {
            n=n/10;
            count++;
        }
        int c=count;
        val=count;
        n=n1;
        // To store the number in array
        for(i=count;i>0;i--)
        {
            b[i]=n%10;
            a[i]=n%10;
            n=n/10;
        }
        //for test cases 1-9
        if(count==1)
        {
            a[1]=a[1]+1;
        }
        else
        {
            if(count%2!=0)
            {
                c++;
            }
            for(j=1;j<=count;j++)
            {      
                //copying the first number=last number unless centre of no is reached
                if(j<(c/2))
                {
                    a[val]=a[j];
                    val--;
                }
                else
                {
                    //if the number is odd then middle digit has to increased by 1 depending on the adjacent values
                      if(count%2!=0)
                        {
                             if(b[j-1]<=b[j+1])
                             {
                                if(a[j]==9)
                                {
                                    //if the number is 9 then incrementing it will make it 10, to avoid this again incrementing all
                                    //numbers except mid one by 1 and make mid num as zero instead of 10
                                    for(k=1;k<j;k++)
                                    { 
                                        a[k]=a[k]+1;
                                        if(a[k]==10)
                                        a[k]=0;
                                    }  
                                    a[j]=0;
                                    for(k=j+1;k<=count;k++)
                                    {
                                        a[k]=a[k]+1;
                                        if(a[k]==10)
                                        {
                                            a[k]=0;
                                        }
                                    }
                                }
                                else
                                {
                                    a[j]=a[j]+1;
                                }
                            }
                        }
                        else
                        {
                        // if it is even, middile 2 digits have to be changed 
                        // again if any one of them is 9, same procedure  is followed
                        if((a[j]==9)&&(j!=1))
                        {
                          for(k=1;k<j;k++)
                           {
                                 a[k]=a[k]+1;
                                 if(a[k]==10)
                                 {
                                     a[k]=0;    
                                 }
                            }  
                            a[j]=0;
                            a[j+1]=a[j];
                            for(k=j+2;k<=count;k++)
                            {
                               a[k]=a[k]+1;
                               if(a[k]==10)
                                {
                                    a[k]=0;
                                }
                            }
                     }
                     //logic for conversion of middle two digits. it depends on adjacent values
                    if(b[j]>=b[j+1])
                    {
                        a[j+1]=a[j];
                    }
                    else 
                    {
                        a[j]=a[j]+1;
                        a[j+1]=a[j];
                    }
              }
              break;
            }
        }
    }
    //converting the array of elements again into a number
    int sum=0,g=count-1;
    for(i=1;i<=count;i++)
        {
            sum=sum+(a[i]*(pow(10,g)));
            g--;
        }
    
        printf("%d",sum);
    }
        return 0;
}

