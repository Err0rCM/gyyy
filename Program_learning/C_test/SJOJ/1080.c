#include<stdio.h>
int main()
{
	char s[100];
	int n;
	gets(s);
	scanf("%d",&n);
	while(n--)
		printf("%s",s);
	return 0;
}
