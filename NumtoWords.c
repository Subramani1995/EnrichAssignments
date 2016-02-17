#include<stdio.h>
#include<math.h>
int main()
{
    char *ones[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char *tens[]=
        {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninty"};
    int n1;
    scanf("%d",&n1);
    int n=n1,a[20],i=2,j;
    //determining last 2 digits of the number
    a[0]=n%100;
    n=n/100;
    //storing other digits in an array
    while(n!=0)
    {
        a[i]=n%10;
        n=n/10;
        i++;
    }
    //printing equivalent values depending on their position
    for(j=i-1;j>=0;j--)
    {
        if(j==0)
        {
            //check for numbers like 10,20,30..
             if(a[0]%10==0)
             {
                 printf("%s ",tens[(a[0]/10)-1]);
             }
            //check for numbers like 11,12,13..19
             else if((a[0]<20)&&(a[0]!=10))
             {
                 printf("%s ",ones[a[j]-1]);
             }
             else if(a[0]>20)
             {
                printf("%s ",tens[(a[0]/10)-1]);
                printf("%s ",ones[(a[0]%10)-1]);
             }
         }
         else if(j==2)
         {
             //check for numbers like 100,200,300...
            if(a[0]==0) 
            {
                printf("%s hundred",ones[a[j]-1]);
                break;
            }
            else if(a[j]!=0)
            printf("%s hundred and ",ones[a[j]-1]);
         }
         else if(j==3)
         {
             //check for numbers like 1000,2000,3000...
            if((a[0]==0) && (a[2]==0))
            {
                printf("%s thousand",ones[a[j]-1]);
                break;
            }
            else if(a[j]!=0)
            printf("%s thousand and ",ones[a[j]-1]);
         }
         else if(j==4)
         {
             if((a[0]==0) && (a[2]==0)&&(a[3]==0))
            {
                printf("%s thousand",tens[a[j]-1]);
                break;
            }
            else if(a[j]!=0)
            printf("%s thousand and ",tens[(a[j]/10)-1]);
            j--; 
         }
         else if(j==5)
         {
             printf("%s lakh and ",ones[(a[j]-1)]);
         }  
    }  
    return 0;
}
