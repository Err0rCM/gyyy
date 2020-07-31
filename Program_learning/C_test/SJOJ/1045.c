#include <stdio.h>
#include<string.h>
int main()
{
    int a[10],i,max=0,min=0,t;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++)
    {
        if(a[i]<a[min])    min=i;
        if(a[i]>a[max])    max=i;
    }
    t=a[0];
    a[0]=a[min];
    a[min]=t;
    t=a[9];
    a[9]=a[max];
    a[max]=t;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
