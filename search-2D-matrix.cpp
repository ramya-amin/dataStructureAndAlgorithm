/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true


Solution:
Staircase 

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        /* 
        start from matrix[0][n-1] top right corner 
        if target < matrix[0][j] then column --
        else if target > matrix[0][j] then row ++
        else if target == matrix[i][j] return true;
        else return false;
        
        */
        
        int i=0, j=matrix[0].size()-1; //start from top right corner 
        
        while(i>=0 && i < matrix.size() && j>=0 && j < matrix[0].size() )
        {
            
            if(target == matrix[i][j])
                return true;
            else if (target < matrix[i][j])
                j--;
            else if (target > matrix[i][j])
                i++;
                   
            
        }
        return false;
        
    }
};
