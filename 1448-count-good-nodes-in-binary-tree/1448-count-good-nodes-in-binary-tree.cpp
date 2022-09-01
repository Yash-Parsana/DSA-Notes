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
    void solve(TreeNode* &root,int mx,int &ans)
    {
        if(root==NULL)return ;
        
        if(root->val>=mx)
            ans++;
        mx=max(mx,root->val);
        solve(root->left,mx,ans);
        solve(root->right,mx,ans);
        
        
    }
    int goodNodes(TreeNode* root) {
        
        int ans=0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};