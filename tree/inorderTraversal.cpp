
/*
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]

By: Ramya Amin
Date: 14-Nov-2022
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 vector<int> values;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            inorderHelper(root, ans);
            return ans;
    }

    void inorderHelper(TreeNode* root, vector<int>& ans){
        
        if(root == nullptr) return;

        if(root->left) 
            inorderHelper(root->left, ans);
        
         ans.push_back(root->val);            //this is inorder traversal logic ; to use return type as void this additiona helper was used 
        
        if(root->right)
             inorderHelper(root->right, ans);
        
    }
};