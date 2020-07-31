#include<stdio.h>
int main()
{
	double a,h,m,t;
	scanf("%lf",&a);
	//a=a*5*((double)12/11);
	m=(a-(int)a)*60;
	h=a*5;
	if(h>=m)
		t=h-m;
	else
	{
		t=60-m;
		m=0;
		h=h+t/12;
		t+=h-m;
	}
	t=t*(12.0/11);
	printf("%.3lf\n",t/60);
	return 0;
}
