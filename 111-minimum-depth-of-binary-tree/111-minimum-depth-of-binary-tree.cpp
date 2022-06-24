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
    void solve(TreeNode* root,int temp,int &ans)
    {
        if(!root)return;
        if(root->left==NULL&&root->right==NULL)
        {
            ans=min(ans,temp+1);
            return;
        }
        solve(root->left,temp+1,ans);
        solve(root->right,temp+1,ans);
        
    }
    
    int minDepth(TreeNode* root) {
        
        if(root==NULL)return 0;
        int ans=INT_MAX;
        
        solve(root,0,ans);
        return ans;
    }
};