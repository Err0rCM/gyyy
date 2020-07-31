#include<stdio.h>
#define PI 3.1416
int main()
{
	float r,h,C1,Sa,Sb,Va,Vb;
	scanf("%f %f",&r,&h);
	C1=2*PI*r;
	Sa=PI*r*r;
	Sb=4*PI*r*r;
	Va=4.0/3*PI*r*r*r;
	Vb=Sa*h;
	printf("C1=%.1f\nSa=%.1f\nSb=%.1f\nVa=%.1f\nVb=%.1f",C1,Sa,Sb,Va,Vb);
	return 0;
}
