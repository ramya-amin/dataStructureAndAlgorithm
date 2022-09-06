/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/

//Solution 1: O(n^2)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumOfDiagonals=0;
        for(int row=0;row<mat.size();row++)
        {
            for(int col=0;col<mat[row].size();col++)
            {
                //primary diagonal 
                if(col==row)
                      sumOfDiagonals=sumOfDiagonals + mat[row][col];
                                   
                //secondary diagonal | middle element (1,1) won't be considered since it gets used in above if condition ; col+row = 1 
                else if((col+row) == (mat[row].size()-1))
                      sumOfDiagonals=sumOfDiagonals + mat[row][col];
                
            

            }
            
        }

        
        return sumOfDiagonals;
    }
};

//Solution 2: O(n)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int priDiagonalSum=0, secDiagonalSum=0;
        int n=mat.size();
        for(int index=0;index<n;index++)
        {
            priDiagonalSum += mat[index][index];
            secDiagonalSum += mat[index][n-1-index];
                        
        }

            //if the matrix size is odd then the middle element get added twice
        
       if( n%2 )   
          return priDiagonalSum + secDiagonalSum - mat[n/2][n/2];
        else
            return priDiagonalSum + secDiagonalSum;
    }
};
