#include<stdio.h>
int main()
{
    int n,i,j,k=0,max=0;
    scanf("%d",&n);
    int a[n];
	int b[n][2];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==b[j][0])
                break;
        }
        if(j==n)
        {
            b[k][0]=a[i];
            b[k++][1]++;
        }
        else b[j][1]++;
    }
	for(i=0;i<k;i++)
		if(b[max][1]<b[i][1]&&i>max)
			max=i;
	printf("%d",b[max][0]);
	return 0;
}
