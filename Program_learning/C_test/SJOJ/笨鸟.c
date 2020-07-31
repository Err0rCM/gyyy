#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T,n,i,s,j;
    scanf("%d",&T);
    while(T--)
    {
        s=0,j=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            s=(s+j)%10000;//s进行累加 
            j=(j+2)%10000;//j为上一次的速度+2 
        }
        printf("%d\n",s);
    }
    return 0;
}
