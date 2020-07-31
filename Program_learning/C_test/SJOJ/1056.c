#include<stdio.h>
#include<math.h>
int cal(int n,int a[])
{
	int i,max1=0,max2,min1=0,min2,t;
	for(i=0;i<n;i++)
		if(a[max1]<a[i])
			max1=i;
	for(i=0;i<n;i++)
		if(a[min1]>a[i])	
			min1=i;
	max2=min1;
	min2=max1;
	for(i=0;i<n-1;i++)
	{	if(i==max1)	continue;
		if(a[max2]<a[i]&&a[i]<=a[max1])	max2=i;
	}
		
	for(i=0;i<n-1;i++)
	{
		if(i==min1)	continue;
		if(a[min2]>a[i]&&a[i]>=a[min1])	min2=i;
	}
	return abs(a[max2]-a[min2]);
}

int main()
{
	int n,Case,i;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",cal(n,a));
	}
	return 0;
}
