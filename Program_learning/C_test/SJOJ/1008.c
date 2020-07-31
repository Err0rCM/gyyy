#include<stdio.h>
int main()
{
	int g;
	scanf("%d",&g);
	switch(g/10)
	{
		case 10:case 9:printf("A\n");break;
		case 8:printf("B\n");break;
		case 7:printf("C\n");break;
		case 6:printf("D\n");break;
		default:printf("E\n");break;
	}
	return 0;
}
