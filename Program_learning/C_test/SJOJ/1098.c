#include<stdio.h>
int main()
{
	long i,f1=1,f2=1,t;
	scanf("%d",&i);
	if(i<3)	printf("1");
	else 
	{
		i-=2;
		while(i--)
		{
			t=(f1+f2)%10007;
			f1=f2%10007;
			f2=t;
		}
		printf("%d",t);
	}
	return 0;
 } 
