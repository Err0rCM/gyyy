#include<stdio.h>
#include <stdlib.h>
int main()
{
	int T,x=0,n,i,s,v,t;
	int f[100];
	scanf("%d",&T);
	for(n=0;n<T;n++)
	{
		v=1;
		s=0;
		scanf("%d",&t);
		for(i=0;i<t;i++)
		{
			s+=v;
			v+=2;
		}
		f[n]=s%10000;
	}
	for(n=0;n<T;n++)
		printf("%d\n",f[n]);
	return 0;
}

