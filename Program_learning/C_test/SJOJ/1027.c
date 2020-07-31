#include <stdio.h>
#include <stdlib.h>
 int sum;
int LCM(int p, int q)
{
    int lc;
    lc = p * q / sum;
    return lc;
}    
int HCF(int x, int y)
{
    int i, k, m, n;
    sum = 1;
    k = x > y ? y : x;
    i = 2;
    while (i <= k){
        m = x % i;
        n = y % i;
        if (m == 0 && n == 0){
            sum *= i;
            x /= i;
            y /= i;
            i = 2;
        }
        else
            i++;
    }    
    return sum;
}
                      
int main()
{
    int a, b, hcf, lcm;
    scanf("%d %d", &a, &b);                      
    hcf = HCF(a, b);                              
    lcm = LCM(a, b);                              
    printf("%d %d", hcf, lcm); 
    return 0;
}

