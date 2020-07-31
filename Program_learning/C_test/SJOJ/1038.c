#include<stdio.h>
#include<math.h>
#define S (a+b+c)/2
#define area sqrt(S*(S-a)*(S-b)*(S-c))
int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%.3lf",area);
	return 0;
}
