# EnrichAssignments
To calculate the determinant of the square matrix using GE method
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],test[100];
	int i,j,a[26]={0};
	scanf("%s",str);
	scanf("%s",test);
	for(i=0;test[i]!='\0';i++)
	{
		for(j=0;str[j]!='\0';j++)
		{
			if(str[j]==test[i])
			{
				a[i]=a[i]+1;
			}
		}
	}
	for(i=0;test[i]!='\0';i++)
	{
		printf("%c occured %d times\n",test[i],a[i]);
	}
	return 0;
}
