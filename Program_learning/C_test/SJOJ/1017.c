#include<stdio.h>
int main()
{
	int N,i,k,t;
	scanf("%d",&N);
	for(i=1;i<N;i++)
	{
		t=0;
		for(k=1;k<i;k++)
			if(i%k==0)	t+=k;
		if(t==i)
		{
			printf("%d its factors are ",i);
			for(k=1;k<i;k++)
				if(i%k==0)	printf("%d ",k);
			putchar('\n');
		}	
	}
	return 0;
} 
