#include<stdio.h>
int main()
{
	int nCase,n,d1,d2,d3,m1,m2,m3;
	scanf("%d",&nCase);
	while(nCase--)
	{
		n=0;
		scanf("%d %d",&d1,&m1);
		scanf("%d %d",&d2,&m2);
		scanf("%d %d",&d3,&m3);
		while(++n)
		{
			if(n%d1==m1&&n%d2==m2&&n%d3==m3)
				break;
		}
		printf("%d\n",n);
	}
	return 0;
}
