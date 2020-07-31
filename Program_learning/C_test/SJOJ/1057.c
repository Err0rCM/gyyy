#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,j;
	char s[101];
	while(gets(s))
	{
		i=0,n=0;
		while(s[i+11]!='\0')
		{
			char a[20]="\0";
			for(j=0;j<12;j++)
				a[j]=s[i+j];
			if(strcmp(a,"AcmersLoveAc")==0)
				n++;
			i++;
		}
		printf("%d\n",n);
	}
	return 0;
}
