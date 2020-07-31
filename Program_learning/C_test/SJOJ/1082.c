#include<stdio.h>
int main()
{
	int n,k,i,j=0,flag=-1;
	scanf("%d %d",&n,&k);
	int a[n+1];
	for(i=0;i<n+1;i++)
		a[i]=0;
	for(i=1;i<=k;i++)
	{
		j=1;
		while(j<n+1)
		{
			if(j%i==0)
				a[j++]++;
			else	j++;
		}
	}
	for(i=1;i<n+1;i++)
		if(a[i]%2==1)
			if(flag)
			{
				printf("%d",i);
				flag++;
			}
			else	printf(" %d",i);
	return 0;
} 
