#include<stdio.h>
int main()
{
	int N,fz=2,fm=1,t,i;
	double a;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		a+=(double)fz/fm;
		t=fz;
		fz+=fm;
		fm=t;
	}
	printf("%.2lf",a);
	return 0;
 } 
