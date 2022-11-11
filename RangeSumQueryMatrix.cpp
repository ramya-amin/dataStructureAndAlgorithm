/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
Example:

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]


Solution:
Create pre-fix sum matrix first and then calculate the sum, depending on if the given query points [top][left] and [bottom][right] are starting from top or left corner 

*/

class NumMatrix {
public:
    vector<vector<int>> psm; // so that its accessible in the function as well
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        psm = vector<vector<int>> (matrix.size(), vector<int> (matrix[0].size()));
        
        //to make pre-fix sum matrix - row wise sum 
        for(int i=0; i< matrix.size();i++)
            for(int j=0;j< matrix[i].size(); j++){
                if(j==0)
                    psm[i][j]=matrix[i][j];
                else
                    psm[i][j]=psm[i][j-1]+matrix[i][j];
            }
        
        //to the above row wise sum matrix, make colum wise sums 
            for(int i=0; i< matrix.size();i++)
            for(int j=0;j< matrix[i].size(); j++){
                if(i!=0)
                   psm[i][j]=psm[i-1][j]+psm[i][j];
            }
          
    }
    
    int sumRegion(int top, int left, int bot, int right) {
        int sum=0;
        if(left==0 && top == 0)
            sum=psm[bot][right];
        else if(top==0)
            sum=psm[bot][right]-psm[bot][left-1];
        else if(left == 0)
              sum=psm[bot][right] - psm[top-1][right];  
        else
            sum=psm[bot][right] - psm[top-1][right] - psm[bot][left-1] + psm[top-1][left-1];
        
        return sum;
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
