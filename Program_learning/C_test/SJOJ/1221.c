#include<stdio.h>
#include<string.h>
int main()
{
	int a1,s1;
	char a[100],s[100],s2[10],s3[10],s4[10],a2[10],a3[10],a4[10];
	gets(s);
	sscanf(s,"%d %s %s %s",&s1,s2,s3,s4);
	if(strcmp(s2,"red")==0)
		s1+=100;
	if(strcmp(s3,"heavy")==0)
		s1+=200;
	while(gets(a))
	{
		sscanf(a,"%d %s %s %s",&a1,a2,a3,a4);
		if(strcmp(a2,"red")==0)
			a1+=100;
		if(strcmp(a3,"heavy")==0)
			a1+=200;
		if((s1=s1-a1)<0)
		{
			s1=-s1+500;
			strcpy(s4,a4);
		}
		else	s1+=500;
	}
	puts(s4);
	return 0;
}
