#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[10],s[100][500];
    int head,i=0,j;
    gets(a);
    if(strlen(a)==4) head=10;
    else sscanf(a,"head -%d",&head);
    gets(s[i]);
    while(strcmp(s[i],"")!=0)   gets(s[++i]);
    if(head<i)
        for(j=0;j<head;j++)
            puts(s[j]);
    else
        for(j=0;j<=i;j++)
            puts(s[j]);
    return 0;
}
