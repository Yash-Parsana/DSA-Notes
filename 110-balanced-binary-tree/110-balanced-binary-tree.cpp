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
    
    int solve(TreeNode* root,bool &b)
    {
        if(root==NULL)return 0;
        
        int l=solve(root->left,b)+1;
        int r=solve(root->right,b)+1;
        
        if(abs(l-r)>1)b=0;
        
        return max(l,r);
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool ans=1;
        solve(root,ans);
        return ans;
        
    }
};