#include<stdio.h>
#include<string.h>
int main()
{
	int i;
    char a[50];
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='a'&&a[i]<'z'||a[i]>='A'&&a[i]<'Z')
      {
          a[i]=a[i]+1;
      }
       else if(a[i]=='z'||a[i]=='Z')
       {
            a[i]+=1;
       }     
       else
           a[i]=a[i];
     } 
    puts(a);
    return 0;
 } 
