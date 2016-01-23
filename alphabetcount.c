# EnrichAssignments

#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i,j=0,a[100]={0};
	scanf("%s",s);
	for(i=s[j];s[j]!='\0';j++)
	{
		i=s[j];
		a[i]=a[i]+1;
	}
	for(i=65;i<=90;i++)
	{
		printf("%c occured %d times\n",i,a[i]);
	}
	return 0;
}
