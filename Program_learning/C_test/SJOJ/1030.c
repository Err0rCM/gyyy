#include<stdio.h>
int main()
{
	int a[3][3],i,j,b[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[j][i]=a[i][j];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",b[i][j]);
			putchar('\n');
	}	
	return 0;
}
