#include<stdio.h>
int main()
{
	int a1,a2,ad,n,d;
	int a;
	scanf("%d %d %d",&a1,&a2,&n);
	d=a2-a1;
	ad=a1+(n-1)*d;
	a=(a1+ad)*n/2.0;
	printf("%d",a);
	return 0;
 } 
