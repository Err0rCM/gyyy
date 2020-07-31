#include<stdio.h>
int main()
{
	int i,n,j;
	scanf("%d",&n);
	for(i=0;i<n*3;i++)
	{
		for(j=0;j<n;j++)
			printf(" /|\\");
		putchar('\n');
	}
	return 0;
} 
