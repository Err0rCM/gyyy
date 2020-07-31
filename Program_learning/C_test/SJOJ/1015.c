#include<stdio.h>
int main()
{
	int a,b,c,s1=0,s2=0,i;
	double s3=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=a;i++)
		s1+=i;
	for(i=1;i<=b;i++)
		s2+=i*i;
	for(i=1;i<=c;i++)
		s3+=1.0/i;
	printf("%.2lf",s1+s2+s3);
	return 0;
}
