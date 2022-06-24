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
    
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)return 0;
        
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        
        if(left>0&&right>0)
        {
            ans=max(ans,left+right+root->val);
            return max(left,right)+root->val;
        }
        if(left>0)
        {
            ans=max(ans,left+root->val);
            return left+root->val;
        }
        if(right>0)
        {
            ans=max(ans,right+root->val);
            return right+root->val;
        }
        ans=max(ans,root->val);
        return root->val;
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        
        solve(root,ans);
        return ans;
    }
};