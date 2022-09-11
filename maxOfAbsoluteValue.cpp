/*
https://leetcode.com/problems/maximum-of-absolute-value-expression/

1131. Maximum of Absolute Value Expression

Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 
 ############ Solution ############
 
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

First analyze this expression.

if j == i, this expression evaluates to 0.
For simplicity, we only consider (i, j) pairs that i<j.
To get rid of these absolute expressions, consider these 4 scenarios:
arr1[i] < arr1[j] and arr2[i] < arr1[j]
arr1[i] >= arr1[j] and arr2[i] < arr2[j]
arr1[i] < arr1[j] and arr2[i] >= arr2[j]
arr1[i] >= arr1[j] and arr2[i] >= arr2[j]
Optimal value is the max of the above 4 cases.
Case 1:
original expression = arr1[j] - arr1[i] + arr2[j] - arr1[i] + j - i = (arr1[j] + arr2[j] + j) - (arr1[i] + arr2[i] + i)
=f(j) - f(i) where f(i) = arr1[i] + arr2[i] +i;

f(i) can be obtained in O(N) time.
max value of f(j) - f(i) can be obtained in O(N) time.
Other 3 Cases are similar.



*/


class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector <int> v1(n,0), v2(n,0), v3(n,0), v4(n,0);
        int res=0;
        
        for(int i=0; i < n; i++)
        {
            v1[i]=(a[i]+b[i]+i);
            v2[i]=(a[i]-b[i]-i);
            v3[i]=(a[i]-b[i]+i);
            v4[i]=(a[i]+b[i]-i);
            
        }
        
        /* debug
        for(int v:v1)
            cout<<v<<'\t';
        cout<<'\n';
        for(int v:v2)
            cout<<v<<'\t';
                cout<<'\n';

        for(int v:v2)
            cout<<v<<'\t';
                cout<<'\n';

        for(int v:v2)
            cout<<v<<'\t';
                cout<<'\n'; */

        
        // to find the maximum of  max(X) - min(Y)
        
        res=max(res, *max_element(v1.begin(),v1.end()) - *min_element(v1.begin(), v1.end()));
        res=max(res, *max_element(v2.begin(),v2.end()) - *min_element(v2.begin(), v2.end()));
        res=max(res, *max_element(v3.begin(),v3.end()) - *min_element(v3.begin(), v3.end()));
        res=max(res, *max_element(v4.begin(),v4.end()) - *min_element(v4.begin(), v4.end()));

        return res;
        
                
    }
};
