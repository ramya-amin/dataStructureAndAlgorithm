/*
Verify if the given string is palidrome or not.
Example:  abba , abcba 


By: Ramya Amin 
Date: 14-Nov-2022
*/

/* Solution Approach: 
Take 2 pointers 

c    a   b    b   a   c 
^                     ^
|                     |
start                end 


isPalindrome(start, end) = {     if (start == end) return true;  // odd length palidrome string , single mid character in that case 
                                 if (start > end) return true;  // even length palidrome string
                                 if s[start] != s[end] return false
                                 if s[start] == s[end] return isPalindrome(start+1, end-1)
                            }

*/

#include <iostream>
#include <vector>
#include<cstring>
#include<cmath>

using namespace std;

class palindrome{
    
  public:
  bool isPalindrome(char* s)
  {
    int size=strlen(s)-1;    
    return checkPalindrome(s, 0, size);  
        
  }
  
  bool checkPalindrome(char* str, int start, int end) 
  {

      if(start == end) return true;
      if(start > end ) return true;

       if(str[start] != str[end]) 
        return false;
       else
        return checkPalindrome(str, start+1, end-1); //check recursively 
  }
  
};

int main()
{
    char str[]="aba";
    palindrome obj;

    if(obj.isPalindrome(str) == 1)
    cout<<endl<<"Given string is palidrome"<<endl;
    else
    cout<<endl<<"Given string is not palindrome"<<endl;

    return 0;
}

