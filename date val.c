
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int check_year(int);
int check_month(int);
int check_date(int,int,int);

int main(int argc, const char * argv[]) {
    // insert code here...
    char c[]="28-02-2016";
    int k=0,i,a[10],x,y,z;
    for(i=0;c[i]!=0;i++)
    {
        if(c[i]=='-')
        {
            continue;
        }
        else
        
        {
            a[k]=atoi(&c[i]);
            k++;
        }
    }
        int date,month,year;
        date=a[0];
        month=a[2];
        year=a[4];
        x=check_year(year);
        y=check_month(month);
        z=check_date(x,month,date);
        if((z==0)||(y==0))
        {
            printf("not valid\n");
        }
        else{
            printf("valid\n");
        }
    
    return 0;
}
int check_year(int yr)
{
    int f=0;
    printf("%d ",yr);
    if(yr%100==0)
    {
        if((yr%400)==0)
        {
            f=1;
        }
    }
    else if(yr%4==0)
    {
        f=1;
    }
    return f;
}
int check_month(int mn)
{
    printf("%d ",mn);
    if((mn>12)||(mn<0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
int check_date(int x,int month,int date)
{
    int flag=1;
    printf("%d ",date);
    if(date>31)
    {
        flag=0;
    }
    else if((x==1)&&(month==2)&&(date>29))
    {
        flag=0;
    }
    else if((x==0)&&(month==2)&&(date>28))
    {
        flag=0;
    }
    else if((month==4)||(month==6)||(month==9)||(month==11))
    {
        if(date>30)
        {
            flag=0;
        }
    }
    return flag;
}
