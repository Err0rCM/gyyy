#include<stdio.h>
#include<string.h>
int main()
{
	char a[10],b[10];
	scanf("%s",a);
	scanf("%s",b);
	strcat(a,b);
	puts(a);
} 
