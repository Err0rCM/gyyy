#include<stdio.h>
int main()
{
	int a=2,i,n,t=0,sn=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t=t*10+a;
		sn+=t;
	}
	printf("%d",sn);
	return 0;
}
