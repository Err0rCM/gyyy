#include<stdio.h>
#include<math.h> 

void fun1(double a,double b,double d)
   { double x1,x2;
       x1=(b+sqrt(d))/(-1*2*a);
       x2=(b-sqrt(d))/(-1*2*a);
       printf("%lf%lf",x1,x2);
   }
void fun2(double a,double b,double d)
   {double x1,x2;
       x1=x2=(b+sqrt(d))/(-2*a);
       printf("%lf%lf",x1,x2);
   }
void fun3(double a,double b,double d)
   {double x1,x2,y1,y2;
       x1=(-b)/(2*a);
       y1=sqrt(-d)/(2*a);
       x2=(-b)/(2*a);
       y2=sqrt(-d)/(2*a);
       printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi",x1,y1,x2,y2);
   }
int main()
{
    double a,b,c,d;
    double x1,x2;
    scanf("%lf%lf%lf",&a,&b,&c);
    d=b*b-4*a*c;
    if(d>0)
       fun1(a,b,d);
    if(d==0)
       fun2(a,b,d);
    if(d<0)
       fun3(a,b,d);
    return 0;
 } 
