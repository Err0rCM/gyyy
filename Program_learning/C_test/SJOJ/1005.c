#include <stdio.h>

int main()
{
	float celsius,fahr;
	scanf("%f",&fahr);
	celsius=5*(fahr-32)/9;
	printf("c=%.2f",celsius);
	return 0;
}
