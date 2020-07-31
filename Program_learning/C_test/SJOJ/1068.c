#include<stdio.h>
int main()
{
    int f[20]={3,7};
    int i,C,n;
	scanf("%d",&C);
    for(i=2;i<20;i++)
    	f[i]=2*f[i-1]+f[i-2];
    while(C--)
    {
        scanf("%d",&n);
        printf("%d\n",f[n-1]);
    }
    return 0;
}
