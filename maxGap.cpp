/* 
https://leetcode.com/problems/maximum-gap/
164. Maximum Gap


Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
*/



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
         //brute force : sort takes O(nlon) and then for loop O(n) - need to optimize 
        //Logic: Sort the given list of numbers and then compare the difference of consecutive number to find the max gap/difference 
        
        if(nums.size() <= 1)
            return 0;
        else
        {
        sort (nums.begin(), nums.end());
            
        
        int max=0;
        for(int i=0;i<nums.size()-1;i++){
            max=(nums[i+1]-nums[i]) > max? nums[i+1]-nums[i] : max;
        }
        
                
        return max;
        
        }
        
    }
};
