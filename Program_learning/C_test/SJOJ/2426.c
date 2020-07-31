#include<stdio.h>
int main()
{
	char s[1000],m;
	int i,j,t=1,mt=0;
	gets(s);
	for(i=1;s[i-1];i++)
	{
		if(s[i]==s[i-1])
			t++;
		else if(t>mt)
		{
			m=s[i-1];
			mt=t;
			t=1;
		}
			else	t=1;
	}
	printf("%c %d",m,mt);
	return 0;
} 
