#include <stdio.h>
#include <string.h>

struct list
{
    int s_no;
    char name[20],copy[20];
    int arr[10],count;
}s[30];
//name consists original names
//copy consists the truncated names(according to conditions)
int main() {
    int n,x,k=0,i,j,c=0,start,stop;
    printf("enter number of students");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        start=0;
        stop=0;
        printf("enter name\n");
        scanf("%d %[^\n]s",&s[i].s_no,s[i].name);
        for(j=0;s[i].name[j]!='\0';j++)
        {
            if(s[i].name[j]=='.')
            {
          //    start is used to store the index of next variable to DOT
                start=j+1;
            }
            if(s[i].name[j]==' ')
            {
            //  stop is used to store the last variable's index before SPACE
                stop=j;
            }
        }
        if((start==0)&&(stop==0))
        {
            // if the name has no constraints
            c++;
            strcpy(s[i].copy,s[i].name);
        }
        else if(start!=0)
        {
            for(x=start;s[i].name[x]!='\0';x++)
            {
                // store the name in copy, after Dot
                s[i].copy[k]=s[i].name[x];
                k++;
            }
            s[i].copy[k]='\0';
        }
        else if(stop!=0)
        {
            k=0;
            for(x=0;x<stop;x++)
            {
                // store the name in copy upto space
                s[i].copy[k]=s[i].name[x];
                k++;
            }
            s[i].copy[k]='\0';
        }
        k=0;
    }
    for(i=0;i<n;i++)
    {
        k=0;
        s[i].arr[k]=i+1;
        k=1;
        for(j=i+1;j<n;j++)
        {
            if(s[j].copy[0]!='\0')
            {
                if(strcmp(s[i].copy,s[j].copy)==0)
                {
                    // check if both names are equal if equal incrment the count, and store the address of them in arr
                    s[i].arr[k++]=j+1;
                    s[i].count++;
                    s[j].copy[0]='\0';
                }
            }
        }
        //adding null to the startin char of duplicates, so that need not check again
        if(s[i].copy[0]!='\0')
        {
        
            // print the name and its no of occurance
            printf("%s,%d,",s[i].copy,s[i].count+1);
            printf("[");
            for(j=0;j<=s[i].count;j++)
            {
                //print the index of all copies where it occured
                printf("%d, ",s[i].arr[j]);
            }
            printf("]\n");
            s[i].copy[0]='\0';
        }
    }
    return 0;
}

