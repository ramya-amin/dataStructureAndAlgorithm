
/*
LCQ 739. Daily Temperatures

https://leetcode.com/problems/daily-temperatures/description/

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have 
to wait after the ith day to get a warmer temperature. If there is no future
day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

Approach: Utilize nearest greater element on right method of stack 

By: Ramya Amin
Date: 19-Nov-2022

*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st; // this would maitain the index of next right higher temperature
        vector<int> output(temperatures.size()); // this would store the difference between current index and the next highest temp's index on the right 

        int n = temperatures.size();
        
        for(int i = n-1 ; i >= 0; i-- ){

                while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                    st.pop();

                if(st.empty())
                    output[i] = 0;
                else
                    output[i] = st.top() - i;

                st.push(i);

        }

        return output;
    }
};