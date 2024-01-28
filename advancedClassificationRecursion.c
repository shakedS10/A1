#include <stdio.h>
int power (int num , int p)
{
    int sum = num;
    for (int i = 1; i < p; i++)
    {
        sum = sum*num;
    }
    return sum;
    
}
int armstrongHelper(int num , int p)
{
    if (num/10==0)
    {
        return power(num, p);
    }
    return armstrongHelper(num/10, p)+ power(num%10, p);
    
}
int isArmstrong(int num)
{
    
      int tempn = num;
    int numOfDig = 0;
    while (tempn!= 0)
    {
        numOfDig++;
        tempn = tempn/10;
    }
    tempn = num;
    int sumof = armstrongHelper(tempn, numOfDig);
    if (sumof == num)
    {
        return 1;
    }
    return 0;
    
}

int backwards (int num, int save)
{
    if (num == 0)
    {
        return save;
    }
    return backwards(num/10, num%10 + save*10);
   
}
int isPalindrome(int num)
{
    int bnum = backwards(num , 0);
    if(bnum == num)
    {
        return 1;
    }
    return 0;
}