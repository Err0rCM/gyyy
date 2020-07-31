#include <stdio.h>
int main()
{	
	int n,i;
 	int max=0;
 	int maxtime=1,time=1; 
	 	scanf("%d",&n); 
	int a[n];
	for(i=0;i<n;i++)
	   	scanf("%d",&a[i]); 
	for(i=1;i<n;i++)
  	{
  		if(a[i]==a[i-1])
	  		time++;
		else if(time>maxtime)
    	{  
     	  maxtime=time;
     	  time=1;
     	  max=i-1;
    	}
	    else time=1;
	}
	printf("%d\n",a[max]);
 	return 0;
}
