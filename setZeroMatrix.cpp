/*
https://leetcode.com/problems/set-matrix-zeroes/submissions/

73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector <int> col; // to store the column index which has zeros 
        vector <int> row; // to store the row index which has zero 

        // only if the matrix has more than 1 element then proced with modifying it based on which row/col has zeroes; otherwise same matrix remains 
        if(n>1 || m>1)
        {
            
             for(int i=0;i<n; i++)
                {
                     for(int j=0;j<matrix[i].size();j++)
                    if(matrix[i][j] == 0)
                    {
                        col.push_back(j);
                        row.push_back(i);
                    }           
                 }
        
            // debug purpose         
                     cout<<"\n rows : ";
                    for(int i=0;i<row.size();i++)
                        cout<<row[i]<<'\t';

                    cout<<"\n columns : ";
                    for(int i=0;i<col.size();i++)
                        cout<<col[i]<<'\t';
            
            // fill row and col with seroes if any element in it is zero

                if(row.size()>0 || col.size()>0)
                {
                    //fill the rows with zeros 
                    for(int k=0;k<row.size();k++)
                        for(int j=0;j<m; j++)
                        matrix[row[k]][j]=0;

                    //fill the columns with zeros 
                    for(int k=0;k<col.size();k++)
                        for(int i=0;i<n; i++)
                        matrix[i][col[k]]=0;
                }        
        }      
                
    }
};
