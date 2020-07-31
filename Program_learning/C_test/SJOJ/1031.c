#include<stdio.h>
#include<string.h>
int main()
{
	char s[30],k;
	gets(s);
	for(k=strlen(s)-1;k>=0;k--)
		printf("%c",s[k]);	
	return 0;	
}
