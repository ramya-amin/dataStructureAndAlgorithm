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


