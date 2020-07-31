#include<stdio.h>
int main()
{
	int a,a1,a2,a3,a4;
	scanf("%d",&a);
	a1=a/1000;
	a2=a/100%10;
	a3=a/10%10;
	a4=a%10;
	printf("%d %d %d %d",a1,a2,a3,a4);
	return 0;
}
