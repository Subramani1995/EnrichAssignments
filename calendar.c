//to process various tasks on given date

#include<stdio.h>
#include<string.h>
#include<math.h>
char *month_list[]={"Decmber","January","February","March","April","May","June","July","August","September","October","November","December"};
char *day_list[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int day_per_month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct format
{
    char str[12];
    int given[12];
    int year,month,date;
    int leap,day_index,new_date;
}f,reference,new;
int find_yr(struct format);
int find_mnth(struct format);
int find_day(struct format);
void before_Ndays(struct format, struct format ,int);
int georgian(struct format );
int find_in_between(struct format);
int check_leap(int);
int find_day_index(struct format);
int find_day_name(struct format);
int main()
{
    scanf("%s",f.str);
    int i;
    for(i=0;i<12;i++)
    {
        if(f.str[i]!='0')
        {
            f.given[i]=f.str[i]-'0';
        }
    }
    //to convert string input to integers
    f.year=(((f.given[0])*1000)+((f.given[1])*100)+((f.given[2])*10)+((f.given[3])*1));
    f.month=(((f.given[5])*10)+((f.given[6])));
    f.date=(((f.given[8]*10))+f.given[9]);
    //date validation
    if((f.year<0)||(f.month>12)||(f.month<0)||(f.date>31)||(strlen(str)!=11))
    {
        printf("Date is not valid");
    }
    else
    {
    int yr_no,month_no,day_no,index,new_date,georgian,in_between;  
    //calling various functions
    yr_no=find_yr(f);
    month_no=find_mnth(f);
    day_no=find_day(f);
    f.leap=check_leap(f.year);
    index=find_day_index(f);
    before_Ndays(f,new,index);
    georgian=find_day_name(f);
    in_between=find_in_between(f);
    //printing the results
    printf("Current year is: %d\n ",yr_no);
    printf("Previous year is: %d\n",yr_no-1);
    printf("Month in number is: %d\n",month_no);
    printf("Month name is: %s\n",month_list[month_no]);
    printf("Previous month name is:%s\n",month_list[month_no-1]);
    printf("Date of the day is :%d\n",day_no);
    printf("Index of the day is: %d\n",index);
    printf("Day for the given date is: %s\n",day_list[georgian]);
    printf("In between day count is %d\n",in_between);
    }
    return 0;    
}
int find_yr(struct format f)
{
    return (f.year);
}
int find_mnth(struct format f)
{
    return (f.month);
}
int find_day(struct format f)
{
    return (f.date);
}
int check_leap(int yearcheck)
{
    //check for leap year
    f.leap=0;
    if(yearcheck%100==0)
    {
        if((yearcheck%400)==0)
        {
            f.leap=1;
        }
    }
    else if(yearcheck%4==0)
    {
        f.leap=1;
    }
    return (f.leap);
}
int find_day_index(struct format f)
{
    int i;
    if(f.month==1)
    {
        return f.date;
    }
    else
    {
        for(i=1;i<f.month;i++)
        {
            //counting the day index
            f.day_index=f.day_index+day_per_month[i];
        }
        if((f.leap==1)&&(f.month>2))
        {      
            //increment by 1 if leap year
            f.day_index++;    
        }        
        return f.day_index+f.date;
    }
}
int find_day_name(struct format f)
{
    int h,q,K,J,temp_month=f.month,temp_year=f.year,m;
    q=f.date;
    if(f.month==1||(f.month==2))
    {
        temp_month=f.month+12;
        temp_year=f.year-1;
    }
    //finding the day using zeller's congurence method(wikipedia reference)
    m=13*(temp_month+1)/5;
    K=temp_year%100;
    J=temp_year/100;
    h=((q+m+K+(K/4)+(J/4)+(5*J))%7);
    return h;
}
void before_Ndays(struct format f,struct format new,int index)
{
    new=f;
    int N,value;
    scanf("%d",&N);
    //calculating the date difference b/w given N and original date
    while(N--)
    {
        new.date--;
    }
    value=new.date;
    if (value<31)
    {
        value=1;
    }
    //processing the difference value to check year, month changes
    if(value>365)
    {
        new.year=new.year-(new.year/365);
    }
    if(new.date<day_per_month[new.month])
    {
        new.date=day_per_month[new.month-1]+new.date;
        new.month=new.month-(value)%(day_per_month[new.month]);
    }
     printf("Date before N days is : %d-%d-%d\n",new.year,new.month,new.date);    
}
int find_in_between(struct format f)
{
    //getting a reference date
    scanf("%d-%d-%d",&reference.year,&reference.month,&reference.date);
    int ibdays=0,i;
    int le,yeardays=0;
    if(f.year==reference.year)
    {
        //counting no of days by using their index values
        ibdays=((find_day_index(reference))-(find_day_index(f)));
    }
    else if(f.year-reference.year==1)
    {
        ibdays=((365-find_day_index(f))+(find_day_index(reference)));
    }
    else
    {
        //if the dates are from different years, code to consider that
        for(i=reference.year;i<(f.year);i++)
        {
            le=check_leap(i);
            if(le==1)
            {
                yeardays=yeardays+366;
            }
            else
            {
                yeardays=yeardays+365;
            }
            
        }
        ibdays=((365-find_day_index(f))+(find_day_index(reference)));
        ibdays=ibdays+yeardays;
    }
    if(ibdays<0)
    {
        ibdays=ibdays*(-1);
    }
    return ibdays;
}
