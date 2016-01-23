# EnrichAssignments
To encode the given information (compress)

#include<stdio.h>
#include<string.h>
int main()
{
	char s[100],str[100],conversion[100];
	int i=0,j=1,count=1,k=0,len=0,conv,check,x,y,l;
	scanf("%s",s);
	len=strlen(s);
	i=0;
	while(s[j]!='\0')
	{
		while(s[j]==s[i])
		{
			count++;
			i++;
			j++;
		}
		if(count>2)
		{
		   	str[k]=s[i];
		   	// THIS PART IS TO CHECK WHETHER THE COUNT GOES GREATER THAN TEN IF YES, CONVERT IT INTO CHAR
			check=count;
			y=0;
			while(check!=0)
			{
		                x=check%10;
                		conversion[y]=x+'0';
                		y++;
                		check/=10;
			}
			conversion[y]='\0';
			for(l=y-1;l>=0;l--)
			{
			    str[k+1]=conversion[l];
			    k++;
			}
			k=k+1;
        	}

		else
		{
		    while(count--)
			{
			    str[k]=s[i];
				k++;
            		}
		}
		j++;
		if((s[j]==0))
		{
	            str[k]=s[j-1];
        	    str[k+1]='\0';
            	    break;
		}
		i++;
		count=1;
	}
        printf("%s",str);
	return 0;
}




	
	
