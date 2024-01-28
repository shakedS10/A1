#include <stdio.h>
int isArmstrong(int num){
    int orgNum = num, remainder, n=0, res=0;
    while (orgNum!=0)
    {
        orgNum/=10;
        ++n;
    }
    orgNum=num;
    while (orgNum!=0)
    {
    remainder=orgNum%10 ;
    int power=1;
    for(int i=0; i<n;i++) {
        power*=remainder;
    }
    res += power;
    orgNum/=10;
    }
    if (res==num)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int num) {
    int orgNum = num, reversed = 0, remainder;

    // Reverse the number
    while (orgNum != 0) {
        remainder = orgNum % 10;
        reversed = reversed * 10 + remainder;
        orgNum /= 10;
    }
  if (reversed == num) {
       return 1;
    } 
    else {
        return 0;
    }
}