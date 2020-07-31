#include<stdio.h>
int main()
{
	int a,ch=0,n=0,e=0,b=0;
	do
	{
		a=getchar();
		if(a>='0'&&a<='9')
			n++;
			else if(a>='a'&&a<='z'||a>='A'&&a<='Z')
				ch++;
				else if(a==' ') b++;
					else e++;
	}while(a!='\n');
	printf("%d %d %d %d",ch,n,b,e-1);
	return 0;
}
