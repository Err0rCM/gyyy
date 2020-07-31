#include<stdio.h>
int main()
{
	int i,n;
	long long sn=0,t=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t*=i;
		sn+=t;
	}
	printf("%lld",sn);
	return 0;
}
