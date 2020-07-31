#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[10000]={0};
	int n=10;
	gets(a);
	if(strlen(a)>4)
		sscanf(a,"head -%d",&n);
	while(n>0&&gets(a)!=NULL)
	{
		printf("%s\n",a);
		n--;
	}
	return 0;
} 
