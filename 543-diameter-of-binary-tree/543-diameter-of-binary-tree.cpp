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
class Solution {
public:
    
    int solve(TreeNode* &root,int &d)
    {
        if(!root)return -1;
        
        int l=solve(root->left,d)+1,r=solve(root->right,d)+1;
        
        d=max(d,l+r);
        
        return max(l,r);
        
    }
    
    int diameterOfBinaryTree(TreeNode* &root) {
     
        int ans=0;
        
        solve(root,ans);
        return ans;
        
    }
};