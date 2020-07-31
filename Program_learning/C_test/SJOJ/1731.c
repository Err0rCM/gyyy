#include<stdio.h>
#include<string.h>
int main()
{
	char N[10];
	int i,k,t,c=0,a;
	gets(N);
	while(strcmp(N,"")!=0)
	{
		sscanf(N,"%d",&a);
		for(i=1;i<=a;i++)
		{
			t=0;
			for(k=1;k<i;k++)
				if(i%k==0)	t+=k;
			if(t==i)
			{
				c++;
				if(c==1)
					printf("%d",i);
				else printf(" %d",i);
			}	
		}
		gets(N);
	}
	return 0;
}
