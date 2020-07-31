#include<stdio.h>
#include<math.h>
int main()
{
	double a,x0,x1;
	scanf("%lf",&a);
	x0=a/2;
	x1=(x0+a/x0)/2;
	do
	{
		x0=x1;
		x1=(x0+a/x0)/2;
	}while(fabs(x0-x1)>1.0e-5);
	printf("%.3lf",x1);
	return 0;
} 
