/* 42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

*/

// Solution: Find the left and right max heights; minimum of those two makes the highest level water gets trapped. Difference between that minimum value and the height
// of the building if its non-negative then it adds up to trapped water 

class Solution {
public:
    int trap(vector<int>& height) {
        
        int totalWater=0, waterLevel;
        int n=height.size();
		
        vector <int> rightMaxHeight(n);
        vector <int> leftMaxHeight(n);
        
		leftMaxHeight[0]=0;
        rightMaxHeight[n-1]=0;
    //left highest water level per building     
		for(int i=1;i<n;i++)
			leftMaxHeight[i]=max(height[i-1], leftMaxHeight[i-1] );
		    
    //right highest water level per building     
		for(int i=n-2;i>=0;i--)
			rightMaxHeight[i]=max(rightMaxHeight[i+1],height[i+1]);
			
		for(int i=0;i<n;i++)
			{
			  waterLevel=min(leftMaxHeight[i],rightMaxHeight[i]) - height[i];
        
      // add up only positive water levels 
        if(waterLevel>0)
				    totalWater=totalWater+ waterLevel;
			
			}
	  


        return totalWater;
        
    }
    
 
};
