#include <stdio.h>
#include <string.h>

int cal(char *s)
{
    int i,j,k;
    for(i=1;i<=strlen(s)/2;i++)
    {
        if((strlen(s)%i)!=0) continue;
        for(j=0;j<i;j++)
        {
            for(k=j+i;k<strlen(s)&&s[k]==s[j];k+=i);
            if(k<strlen(s)) break;
        }
        if(j==i) break;
    }
	return strlen(s)/i;
}

int main()
{
    char s[100];
    while(strcmp(gets(s),".")!=0)
		printf("%d\n",cal(s));
    return 0;
}
