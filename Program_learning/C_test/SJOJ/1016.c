#include<stdio.h>
int main()
{
	int i,t,a;
	for(i=100;i<1000;i++)
	{
		a=i;
		t=0;
		while(a)
		{
			t+=(a%10)*(a%10)*(a%10);
			a/=10;
		}
		if(t==i) printf("%d\n",i);
	}
	return 0;
}
