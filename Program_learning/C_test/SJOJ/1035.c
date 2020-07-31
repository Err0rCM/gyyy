#include<stdio.h>
#include<string.h>
int num=0,ch=0,b=0,ex=0;
void total(char s[])
{
	int i=0;
	char a;
	for(i=0;i<strlen(s);i++)
	{
		a=s[i];
		if(a>='0'&&a<='9')
			num++;
		else if(a>='a'&&a<='z'||a>='A'&&a<='Z')
			ch++;
			else if(a==' ')
				b++;
				else ex++;
	}
}
int main()
{
	char s[100];
	gets(s);
	total(s);
	printf("%d %d %d %d",ch,num,b,ex);
	return 0;
}
