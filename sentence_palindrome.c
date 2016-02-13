to remove palindromes in the given sentence

#include <stdio.h>



int main(int argc, const char * argv[]) {

    // insert code here...

    char str[100],temp[100],new[100],pali[100];

    gets(str);

    int i,len=0,j=0,l,k=0,m=0,flag=0;

    for(i=0;str[i]!='\0';i++)

    {

        len++;

    }

    for(i=0;i<=len;i++)

    {

        if((str[i]!=32)&&(str[i]!='\0'))

        {

            temp[j]=str[i];

            j++;

        }

        else

        {

            temp[j]='\0';

            for(l=j-1;l>=0;l--)

            {

                pali[l]=temp[m];

                m++;

            }

            for(l=0;l<j;l++)

            {

                if(temp[l]==pali[l])

                {

                    flag=1;

                }

                else{

                    flag=2;

                    break;

                }

            }

            if(flag==2)

            {

                for(l=0;l<j;l++)

                {

                    new[k]=temp[l];

                    k++;

                }

                new[k]=' ';

                k++;

               

            }

            

            j=0;

            m=0;

        }

    }

    printf("%s",new);

   

    return 0;

}

