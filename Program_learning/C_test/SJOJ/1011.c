#include<stdio.h>

int main()
{

int a,b,num1,num2,temp;

scanf("%d%d",&num1,&num2);

if(num1<num2){

temp = num1;

num1 = num2;

num2 = temp;

}

a = num1;

b = num2;

while(b!=0){

temp = a%b;

a=b;

b=temp;

}

printf("%d %d",a,num1*num2/a);

return 0;
}
