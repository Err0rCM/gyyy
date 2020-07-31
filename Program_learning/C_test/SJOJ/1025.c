#include <stdio.h>
int main()
{
    int a[10],i,n;
    for(i=0;i<9;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    i=8;
    while(i>=0 && a[i]>n)
    {
        a[i+1]=a[i];
        i--;
    }
    i++;
    a[i]=n;
    for(i=0;i<9;i++)
        printf("%d\n", a[i]);
        printf("%d",a[9]);
    return 0;
}
