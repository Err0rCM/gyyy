#include<stdio.h>
void main()
{
	int i,k,N;
	scanf("%d",&N);
	for(i=2;i<=N;i++)
	{
		for(k=2;k<i;k++)
			if(i%k==0)
				break;
		if(k>=i)
			printf("%d\n",i);
	}
 } 
