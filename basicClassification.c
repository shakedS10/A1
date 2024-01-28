#include <stdio.h>
int isPrime(int num)
{
    if (num==0 || num == 1)
    {
        return 0;
    }
    
    for ( int i = 2; i <= num; i++)    
    {
        if (i== num)
        {
            return 1;
        }
        
        if (num%i==0)
        {
            return 0;
        }
        
    }
    
    return 0;
}

//////////////////////////////////////////////
int factorial(int num)
{
    int ans = 1;
    for (int i = 1; i <= num; ++i) {
            ans *= i;
        }
    return ans;
    
}

int isStrong(int num)
{
    int tempdigit;
    int tempn = num;
    int sumof = 0;
    while (tempn!= 0)
    {
       tempdigit = tempn% 10;
       sumof += factorial(tempdigit);
       tempn = tempn/10;
    }
    if(sumof == num)
    {
        return 1;
    }
    return 0;
    
}