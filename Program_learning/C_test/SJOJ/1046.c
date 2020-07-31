#include <stdio.h>
#include <stdlib.h>
void change(int n,int a[],int m)
{
	int b[n],i,t=0;
	for(i=m;i<n;i++)
		b[t++]=a[i];
	for(i=0;i<m;i++)
		b[t++]=a[i];
}
int main()
{
	int n,m,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++);
		scanf("%d",&a[i]);
	scanf("%d",&m);
	change(n,a,m);
	for(i=0;i<n;i++);
		printf("%d ",a[i]);
    return 0;
}
