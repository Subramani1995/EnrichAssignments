to find the longest sub-string and its length

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],substrings[100][100]={'*'};
    int x,final_length[100]={0},k=0,y=0,z;
    int a[150]={0};
    scanf("%s",str);
    int len=strlen(str);
    int i,j=0,l,f;
    for(i=65;i<=122;i++)
    {
        a[i]=i;
    }
    for(l=0;l<len;l++)
    {
        for(i=0;i<len;i++)
        {
            for(z=l;z<=i;z++)
            {
                substrings[k][j]=str[z];
                x=substrings[k][j];
                a[x]=a[x]-x;
                if(a[x]<0)
                {
                    break;
                }
                y++;
                j++;
            }
            j=0;
            final_length[k]=y;        
            y=0;
            k++;
            for(f=65;f<=122;f++)
            {
            a[f]=f;
            }
        }
    }
    int max=final_length[0],position;
    for(i=0;i<k;i++)
    {
        if(final_length[i]>max)
        {
            max=final_length[i];
            position=i;
        }
    }
    printf("length of the longest substring is %d\n",max);
    printf("longest sub string is ");
    for(j=0;substrings[position][j]!='\0';j++)
    {
        printf("%c",substrings[position][j]);
    }         
    return 0;
}
