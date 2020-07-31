#include <stdio.h>
int main()
{
    int x,a,b,c,d,e,f,y;
	int a1,b1,c1,d1,f1;
	int i;
	scanf("%d",&x);
    int j=0;
	for(i=x;i!=0;j++)
	{
		i/=10;
	}
	printf("%d\n",j);
		

	a=(x%10)*10000;
	b=((x/10)%10)*1000;
	c=((x/100)%10)*100;
	d=((x/1000)%10)*10;
	f=x/10000;

	a1=(x%10);
	b1=((x/10)%10);
	c1=((x/100)%10);
	d1=((x/1000)%10);
	f1=x/10000;
	y=a+b+c+d+f;

		if(j==1)
			{
				printf("%d\n",y/10000);
				printf("%d\n",y/10000);
			}

		if(j==2)
			{	printf("%d %d\n",b1,a1);
				printf("%d\n",y/1000);
			}

		if(j==3)
			{	printf("%d %d %d\n",c1,b1,a1);
				printf("%d\n",y/100);
			}
			
		if(j==4)
			{	printf("%d %d %d %d\n",d1,c1,b1,a1);
				printf("%d\n",y/10);
			}
			
		if(j==5)
			{	printf("%d %d %d %d %d\n",f1,d1,c1,b1,a1);
				printf("%d\n",y);
			}
    return 0;
}
