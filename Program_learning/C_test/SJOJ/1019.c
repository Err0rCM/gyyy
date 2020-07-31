#include<stdio.h>
int main()
{
	double M,s,a;
	int N,i;
	scanf("%lf %d",&M,&N);
	a=M;
	for(i=1;i<=N;i++)
		M/=2;
	while(N--)
	{
		s+=a;
		a/=2;
		s+=a;
	}
	printf("%.2lf %.2lf",M,s-a);
	return 0;
}
