#include<stdio.h>
int main (void)
{
    int n,i;
    char a[1000];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(a);
        if(a[0]!=' ')
        {
            if(a[0]>='a'&& a[0]<='z')
                  a[0]=a[0]-32;
            printf("%c",a[0]);
        }
        for(i=1;a[i]!='\0';i++)
        {
            if(a[i-1]==' '&& a[i]!=' ')
            {
               if(a[i]>='a'&& a[i]<='z')
                  a[i]=a[i]-32;
               printf("%c",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
