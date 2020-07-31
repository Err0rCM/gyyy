#include<stdio.h>
int main()
{
	double cash,rate,profit;
	int i;
	scanf("%lf %lf",&cash,&rate);
	profit=cash*rate/100*.8;
	printf("%.2lf",profit+cash);
	return 0;
}
