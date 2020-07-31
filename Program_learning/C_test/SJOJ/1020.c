#include<stdio.h>
int main()
{
	int N,i,s=1;
	scanf("%d",&N);
	for(i=1;i<N;i++)
		s=(s+1)*2;
	printf("%d",s);
	return 0;
}
