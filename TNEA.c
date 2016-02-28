// csv file operations on given student details


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//declaring global structure
struct student
{
    char name[20];
    int math,phy,che,rollno,lang1,lang2,total;
    float cut_off;
}s[15],copy[15],temp[15];
//s is used to store actual student details
//copy stores only the details of passed students(eligible for TNEA rank)
//temp is just a temporary structure variable used in swapping loop
int main()
{
    int i,pass_count=0,j,k=0;
    FILE *fp;
    fp=fopen("C:/Users/Elcot/Desktop/marks.csv","r");
    //opening the csv file containing student details
    if(fp==NULL)    //checking the existance of file
    {
        printf("No such file found");
    }
    else
    {
        for(i=0;i<15;i++)
        {
            //getting details from csv
            fscanf(fp,"%d,%[^,],%d,%d,%d,%d,%d\n",&s[i].rollno,s[i].name,&s[i].math,&s[i].phy,&s[i].che,&s[i].lang1,&s[i].lang2);
        }
    }
    fclose(fp);
    for(i=0;i<15;i++)
    {
        //calculating total,cut_off of passed students
        if((s[i].lang1>=70)&&(s[i].lang2>=70)&&(s[i].math>=70)&&(s[i].phy>=70)&&(s[i].che>=70))
        {
            strcpy(copy[pass_count].name,s[i].name);
            copy[pass_count].total=s[i].math+s[i].phy+s[i].che+s[i].lang1+s[i].lang2;
            copy[pass_count].cut_off=((float)(s[i].math/2)+((float)(s[i].phy+s[i].che)/4));
            pass_count++;
        }
    }
    for(i=0;i<pass_count;i++)
    {
        for(j=i+1;j<pass_count;j++)
        {
            //sorting depending on cut_off(first priority),total(2nd priority),lang1 mark(3rd priority)
            if((copy[j].cut_off>copy[i].cut_off)||((copy[j].cut_off==copy[i].cut_off)&&(copy[j].total>copy[i].total))||((copy[j].cut_off==copy[i].cut_off)&&(copy[j].total==copy[i].total)&&(copy[j].lang1>copy[i].lang1)))
            {
                temp[k]=copy[i];
                copy[i]=copy[j];
                copy[j]=temp[k];
                k++;
            }
        }
    }
    fp=fopen("C:/Users/Elcot/Desktop/ranklist.csv","w");
    //storing the details into csv file as well as displaying in the console
    for(i=0;i<pass_count;i++)
    {
        printf("%s %f rank:%d\n",copy[i].name,copy[i].cut_off,i+1);
        fprintf(fp,"%s %f rank:%d\n",copy[i].name,copy[i].cut_off,i+1);
    }
    fclose(fp);
    return 0;
}

	
