#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[20],k=0;
	int i=0;
	gets(a);
/*	for(i=0;i<strlen(a);i++);
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
			b[k++]=a[i];
			*/
		while(a[i]!='\0')
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		{
			b[k]=a[i];
			k++;
		}
		i++;
	} 
	puts(b);
}
