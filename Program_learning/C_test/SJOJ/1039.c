#include<stdio.h>
#define LEAP_YEAR(year) (year%4==0&&year%100!=0)||(year%400==0)?'L':'N'

int main()
{
    int year,leap;
    scanf("%d",&year);
    leap=LEAP_YEAR(year);
    printf("%c",leap);
    return 0;
 } 
