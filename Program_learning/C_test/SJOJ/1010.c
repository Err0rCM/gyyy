#include<stdio.h>
int profit(int l)
{
	if(l<=100000)return l*0.1;
	if(100000>l&&l<=200000)return 10000+(l-100000)*0.075;
	if(l>200000&&l<=400000)return 17500+(l-200000)*0.05;
	if(l>400000&&l<=600000)return 27500+(l-400000)*0.03;
	if(l>600000&&l<=1000000)return 33500+(l-600000)*0.015;
	if(l>1000000)return 37500+(l-1000000)*0.01;
}
int main()
{
	int l;
	scanf("%d",&l);
	printf("%d",profit(l));
	return 0;
}
