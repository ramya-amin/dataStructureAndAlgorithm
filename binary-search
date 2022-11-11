/**************************************************************
* Given an array of integers nums sorted in non-decreasing order, 
* find the starting and ending position of a given target value.
*
* If target is not found in the array, return [-1, -1].
*
*You must write an algorithm with O(log n) runtime complexity. 
****************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startpos=-1, endpos=-1;
        vector<int> result(2,-1);

        // result[-1,-1]
        
        //check for first occurence 
        startpos = search(nums, target, true);

        if(startpos != -1 )
            endpos = search(nums, target, false);
        
        result[0]=startpos;
        result[1]=endpos;
        

     return result;   
    }
    
    int search(vector<int>& nums, int target, bool searchStartIndex) {
        int start=0, end=nums.size()-1, mid, ans=-1;
 

        while ( start <= end ){
            mid= start + (end - start) / 2;
            if ( target > nums[mid])
                start=mid+1;
            else if (target < nums[mid])
                end = mid-1;
            else
            {
                ans = mid;
              
                if(searchStartIndex)
                    end=mid-1;
                else
                    start=mid+1;
                    
            }
             
        }
             return ans;   
            
        }
    
};

int  main(){

    Solution solve;
    vector<int> numbers{5,7,7,8,8,8,10};
    int target=8;

    
    numbers=solve.searchRange(numbers, target);

    for(int x: numbers)
    cout<<x<<"\n";

    return 0;
}
