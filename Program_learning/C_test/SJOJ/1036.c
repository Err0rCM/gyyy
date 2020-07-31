#include<stdio.h>
#define swap(a,b) {t=a;a=b;b=t;}
int main()
{
	int a,b,t;
	scanf("%d%d",&a,&b);
	swap(a,b);
	printf("%d %d",a,b);
	return 0;
 } 
