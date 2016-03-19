#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j,no_of_candi,k=1,votes[10]={0};
	char parties[5][10];
	char c,en;
	scanf("%d",&no_of_candi);
	for(i=0;i<no_of_candi;i++)
	{
		scanf("%s",parties[i]);
	}
	printf("PARTIES COMPETING ARE::\n");
	for(i=0;i<no_of_candi;i++)
	{
		printf("%d %s \n",i+1,parties[i]);
	}
	printf("START CASTING UR VOTES\n");
	do
	{
		printf("enter the code number of party");
		scanf("%d",&k);
		printf("do u want to continue voting press 'y' for yes any other key for exit");
		scanf("%c%c",&en,&c);	
		votes[k-1]++;
	}while(c=='y');
	int max,max_vote=votes[0];
	for(i=0;i<no_of_candi;i++)
	{
		printf(" %s party got %d votes\n",parties[i],votes[i]);
		if(votes[i]>max_vote)
		{
			max_vote=votes[i];
			max=i;
		}
	}
	printf("***WINNER IS %s ***\n",parties[max]);

	return 0;
}
