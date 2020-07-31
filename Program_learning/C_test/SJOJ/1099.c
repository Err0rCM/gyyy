#include<stdio.h>
void put(int i,int flag)
{
    if(flag==0)
        printf("%d",i);
    else printf(" %d",i);
}

int judgement1(int i)
{
	int p;
	while(i!=0)
    {
    	p=i%10;
    	if(p==8)	return 1;
    	i/=10;
    }
    return 0;
} 

int judgement2(int i)
{
	int s=0;
	while(i!=0)
	{
		s+=i%10;
		i/=10;
	}
	if(s==8)	return 1;
	else	return 0;
}

int judgement3(int i)
{
	if(i%8==0)	return 1;
	else return 0;
}

int main()
{
    int i,n,flag=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(judgement1(i)||judgement2(i)||judgement3(i))
        	put(i,flag++);
    }
    return 0;
}
