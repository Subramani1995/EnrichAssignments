//to calculate avg,max from CSV file


#include<stdio.h>
#include<stdlib.h>
struct stud
{
    int mark[100],serial_no;
    char name[100];
}s[10];
int main()
{
    char title[10][100];
    int i=0,j=0,k=0;
    FILE *fp;
    fp=fopen("C:/Users/Elcot/Desktop/student.csv","r");
    if(fp==NULL)
    {
        printf("no such file");
        exit(0);
    }
    else
    {
         for(i=0;i<7;i++)
         {
            while((title[i][k]=fgetc(fp))!=',')
            {
                k++;
            }
            title[i][k]='\0';
            k=0;
         }
         for(i=0;i<9;i++)
         {
            fscanf(fp,"%d,",&s[i].serial_no);
            while((s[i].name[k]=fgetc(fp))!=',')
            {
                k++;
            }
            s[i].name[k]='\0';
            k=0;
            for(j=0;j<5;j++)
            {
                fscanf(fp,"%d,",&s[i].mark[j]);
            }
        }
    }
    fclose(fp);
    
    //File is closed and values are retrieved.. Calculations goes from here....
    
    //average calculations
    
    int sum=0;
    float avg;
    for(j=0;j<5;j++)
    {
        for(i=0;i<9;i++)
        {
            sum=sum+s[i].mark[j];
        }
        avg=(float)sum/9;
        printf("average of subject %d is %f\n",j+1,avg);
        sum=0;
    }
    
    //topper search
    
    int max,value=0;
    for(j=0;j<5;j++)
    {
        max=s[0].mark[j];
        for(i=0;i<9;i++)
        {
            if(s[i].mark[j]>max)
            {
                max=s[i].mark[j];
                value=i;
            }
        }
        printf("top score in subject %d is %d\n",j+1,max);
        printf("topper of subject %d is: \n",j+1);
        for(i=0;s[value].name[i]!='\0';i++)
        {
            printf("%c",s[value].name[i]);
        }
        printf("\n");
    }
    return 0;
}
