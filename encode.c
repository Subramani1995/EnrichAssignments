# EnrichAssignments
To calculate the determinant of the square matrix using GE method


#include<stdio.h>
#include<string.h>
int main()
{
	char s[100],str[100];
	int i=0,j=1,count=1,k=0,len=0;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		len++;
	}
	i=0;
	while(s[j]!='\0')
	{
		while(s[j]==s[i])
		{
		//	printf("%c",s[j]);
			count++;
			i++;
			j++;
		}
		if(count>2)
		{
			str[k]=s[i];
			printf("%c",str[k]);
			str[k+1]=count;
			printf("%c",str[k+1]);
			k++;
		}
		else
		{
			while(count--)
			{
				str[k]=s[i];
				printf("%c",str[k]);
				k++;
			}
		}
		j++;
		i++;
		count=1;
		}
	
	printf("%s",str);
	return 0;
}

	
	
