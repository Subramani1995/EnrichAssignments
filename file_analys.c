//to read paragraphs from ascii file and process it for no of words,letters, etc...


/* My ascii file


Dhoni is my favourite batsman.He is my favourite finisher in the world.
dhoni is my favourite wicket-keeper

Dhoni is the best captain.

Everything in cricket is "DHONI" to me!!!

Dear Dhoni,
I wanted to see you winning 3 world cups, wanted to say, "Proud
 to be a Dhoni fan" again in front of haters. But 
should'nt I say now? I will definitely say. Your 3 ICC trophies
 are not less than those 4 ICC trophies of Ponting because you didn't
 have that team who ruled 12 years in world cricket. You are a Legend, 
Champion, Inspiration and a true leader who stands in front to take
 the bullets of defeats and stands at the back when team wins.

You are still my hero, I'm luck to be your fan!!

-Dhoni Devotee
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void word_calc(char *,int);
void letter_calc(char *,int);
struct para
{
    char word[15];
    char para_start[15];
    int count,start_count;
}w[1000],copy[1000],temp[1000];
int main()
{
    FILE *fp;
    int k=0;
    char str[1000];
    char a;
    fp=fopen("dhoni.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening file");
    }
    else
    {
            while(!feof(fp))
            {
                //getting input from file and storing it in a string
                fscanf(fp,"%c",&a);
                str[k]=a;
                k++;
            }
            str[k-1]='\0';
    }
    letter_calc(str,k);
    word_calc(str,k);
    fclose(fp);
    return 0;
}
void letter_calc(char str[],int len)
{
    int i=0,w_c=0,let_c=0,lin_c=0,sp_c=0,j=0;
    int a[122]={0};
    int x,k;
    for(i=0;i<len;i++)
    {
        if(((str[i]>=65)&&(str[i]<=90))||((str[i]>=97)&&(str[i]<=122)))
        {
            // counting letters - both upper and lower case
            let_c++;
            //if a letter is present incrment its position in array
            a[str[i]]++;
        }
        else if(!((str[i]>=48)&&(str[i]<=57))&&(str[i]!='\n')&&(str[i]!=' ')&&(str[i]!='\0'))
        {
            //counting for special symbols
            sp_c++;
        }
    }

    printf("letters not used are \n");
    for(i=65;i<=122;i++)
    {
        if((a[i]==0))
        {
            if(!((i>90)&&(i<97)))
            {
                //Not used letters - found from values of array (values that r not incremented)
                printf("%c ",i);
            }
        }
    }
    printf("\n");
    int temp;
    char t1,arr[122];
    for(i=65;i<=122;i++)
    {
        arr[i]=i;
    }
    for(i=65;i<=122;i++)
    {
        for(j=i+1;j<=122;j++)
        {
            if(a[j]<a[i])
            {
                //sorting array depending on number of occurances of letters
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                t1=arr[i];
                arr[i]=arr[j];
                arr[j]=t1;
            }
        }
    }
    printf("letter count is %d \n\n",let_c);
    printf("special symbol count is %d\n\n",sp_c);
    printf("Top 3 letters used are :\n%c %c %c\n",arr[121],arr[120],arr[119]);
}
void word_calc(char str[],int len)
{
    int max,max_start;
    int i,j=0,k=1,ref,x=0,y=1,b;
    for(i=0;i<len;i++)
    {
        if((str[i]>='A')&&(str[i]<='Z'))
        {
            //consider that words are not case sensitive
            str[i]=str[i]+32;
        }
    }
    for(i=0;str[i]!=0;i++)
    {
        if((str[i]=='\n')&&(str[i-1]=='\n'))
        {
            //to identify the first word of paragraph
            ref=i+1;
            for(b=ref;str[b]!=' ';b++)
            {
                w[y].para_start[x]=str[b];
                x++;
            }
            w[y].para_start[x]='\0';
            x=0;
            y++;
        }
         else if((str[i]!=' ')&&(str[i]!='\n')&&(str[i]!='\t')&&(str[i]!='\0'))
        {
            //to break the para into words and store it in structure
            w[k].word[j]=str[i];
            j++;
        }
        else
        {
            w[k].word[j]='\0';
            j=0;
            k++;
        }
    }
    strcpy(w[0].para_start,w[1].word);
    printf("\n number of words in file %d\n",k);
    for(i=1;i<=k;i++)
    {
        //taking a copy of the words and initializing count of each word to 1
        strcpy(copy[i].word,w[i].word);
        w[i].count=1;
    }
    for(i=0;i<y;i++)
    {
        //initialize para_starting word count to 1
        w[i].start_count=1;
    }

    for(i=0;i<y;i++)
    {
        for(j=i+1;j<y;j++)
        {
            if(w[i].para_start[0]!='\0')
            {
                //if the para starting word is repeated increment the count of that word
                if(strcmp(w[j].para_start,w[i].para_start)==0)
                {
                    w[i].start_count++;
                    //erase the 2,3...th copy of same word
                    w[j].para_start[0]='\0';
                }
            }
        }
    }
    int m,n;
    max_start=w[0].start_count;
    m=0;
    for(i=0;i<y;i++)
    {
        // to find the maximum start_count  and print corresponding word
        if(w[i].start_count>max_start)
        {
            m=i;
        }
    }
    printf("\n%s[%d] is the frequently used word to start a para\n",w[m].para_start,w[m].start_count);;
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            if((w[i].word[0]!='\0')&&(w[i].word[0]!='\n'))
            {
                //similar process of start_count is carried for all the words
                if(strcmp(w[j].word,w[i].word)==0)
                {
                    w[i].count++;
                    w[j].word[0]='\0';
                }
            }
        }
    }
    printf("\nwords that are used only once \n");
    for(i=1;i<=k;i++)
    {
        if(w[i].count==1)
        {
            //if the word count is not disturbed, it means that word is used only once
            printf("%s ",w[i].word);
        }
    }
    printf("\nTOP 3 WORDS ARE \n");
    int max1,max2,max3,tempp,array[100],tem;
    max1=w[1].count;
    n=1;
    for(i=1;i<=k;i++)
    {
        array[i]=i;
    }
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            if(w[j].count>w[i].count)
            {
                // to sort the array depending on the number of occurance of the word using count variable
                tem=w[i].count;
                w[i].count=w[j].count;
                w[j].count=tem;
                tempp=array[i];
                array[i]=array[j];
                array[j]=tempp;
            }
        }
    }
    for(i=1;i<=3;i++)
    {
        printf("%s[%d]  \n",copy[array[i]].word,w[i].count);
    }
}
