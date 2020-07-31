#include<stdio.h>
int main()
{
	int i,j;
	float a;
	scanf("%f",&a);
	for(i=0;i<3;i++)
		{
			for(j=0;j<=i;j++)
				printf("%6.2f ",a);
			putchar('\n');
		}
	return 0;
}
