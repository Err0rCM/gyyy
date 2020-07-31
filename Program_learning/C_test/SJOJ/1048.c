#include<stdio.h>
int main()
{
char a[50],b[50];
int n,m,i;
scanf("%d",&n);
gets(a);getchar();
scanf("%d",&m);
for(i=m-1;i<=n;i++) *(b+i-m+1)=*(a+i);
printf("%s\n",b);
return 0;
} 
