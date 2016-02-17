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
        while(n!=0)
        {
            n=n/10;
            count++;
        }
        int c=count;
        val=count;
        n=n1;
        for(i=count;i>0;i--)
        {
            b[i]=n%10;
            a[i]=n%10;
            n=n/10;
        }
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
                if(j<(c/2))
                {
                    a[val]=a[j];
                    val--;
                }
                else
                {
                      if(count%2!=0)
                        {
                             if(b[j-1]<=b[j+1])
                             {
                                if(a[j]==9)
                                {
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

