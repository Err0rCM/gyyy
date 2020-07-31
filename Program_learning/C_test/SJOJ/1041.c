#include<stdio.h>
#define Max(a,b,c) (a>b?a:b)>(b>c?b:c)?(a>b?a:b):(b>c?b:c)
double MAX(double a,double b,double c)
{
	double max=a;
	if(max<b)max=b;
	if(max<c)max=c;
	return max;
}

int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%.3lf\n%.3lf",MAX(a,b,c),Max(a,b,c));
	return 0;
}
