/*
59. Spiral Matrix II

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]


*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n));
        int val=1;
        int row=0;
        int col=0;
        int leftRight=n;
        int topDown=0;
        
                
        while(val <= n * n )
        {
            //fill from left to right | row=0, col=0 till col < n
            while(col < leftRight && val <= n * n )
            {
                //row=0; 
                mat[row][col]=val;
                val++;
                col++;
            }
            
            col--;
            //fill from top to bottom | col = n-1 , row+1 till n-1 
            while(row < leftRight-1 && val <= n * n)
            {
                //col--;
                row++;
                mat[row][col]=val;
                val++;
            }
            
            
            //fill from right to left | row=n-1, col=n-2 till 0
            row=leftRight-1;
            while(col>topDown && val <= n * n)
            {
                //row=n-1;
                col--;
                mat[row][col]=val;
                val++;
            }
            
            
            //fill bottom to top | row=n-1 till 1, col=0
            col=topDown;
            while(row>topDown+1  && val <= n * n)
            {
                row--;
                mat[row][col]=val;
                val++;
            }
            
            col++;
            leftRight--;
            topDown++;


        }
                 
        return mat;
    }
};
