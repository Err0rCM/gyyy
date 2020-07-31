#include<stdio.h>
int main()
{
	int L,R,i;
	scanf("%d%d",&L,&R);
	for(;L<=R;L++)
	{
		for(i=2;i<L;i++)
			if(L%i==0)
				break;
		if(i>=L)
			printf("%d\n",i);
	}
	return 0;
}
