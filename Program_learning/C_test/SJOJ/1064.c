#include<stdio.h>
int main()
{
	int a[10],i,j=0,ji,o=0,ou;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{
		if(a[i]%2==0)
		{
			o++;
			ou=i;
		}	
		else
		{	
			j++;
			ji=i;
		}	
	}	
	if(o>j)

		printf("%d",ji);

	if(o>j)

		printf("%d",ou);

	return 0;
}
