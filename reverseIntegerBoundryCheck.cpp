/* 
7. Reverse Integer

https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 */

class Solution {
public:
    int reverse(int x) {
        
        int rev=0;
        int lastDigit;
        
        while(x != 0 )
        {
            
            lastDigit=x%10;
            
            if(rev > INT_MAX/10) // overflow integer boundry value 
                return 0;
            if(rev < INT_MIN/10)
                return 0;

            rev=rev*10 + lastDigit;
            x=x/10;
        }
        
        
        return rev;
        
    }
};
