#include<stdio.h>
struct knap
{
	float weight;
	float money;
	float val;

}k[5],temp;
int main()
{
	int n=5,i,j;
	float max_weight;
	scanf("%f",&max_weight);
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&k[i].weight,&k[i].money);
		k[i].val=(k[i].money/k[i].weight);
		//printf("%f %f %f \n",k[i].weight,k[i].money,k[i].val);
	}
	//float temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(k[j].val<k[i].val)
			{
				temp=k[i];
				k[i]=k[j];
				k[j]=temp;

			}
		}
	}
	float sum_w=0,sum_m=0;
	while(max_weight>0)
	{
		printf("%f %f %f \n",k[i].val,k[i].weight,k[i].money);
//		sum_w=sum_w+k[i].weight;
		max_weight=max_weight-k[i].weight;
		sum_m=sum_m+k[i].money;
		i--;
	}
	printf("max value is %f",sum_m);		
	return 0;
}
