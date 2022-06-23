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
    //first->min ,second->max
    pair<int,int> solve(TreeNode* root,int &ans)
    {
        if(!root)return {INT_MAX/10000,INT_MIN/10000};
        
        pair<int,int> l=solve(root->left,ans);
        pair<int,int> r=solve(root->right,ans);
        
        ans=min({ans,abs(root->val-l.second),abs(r.first-root->val)});
        
        return {min(root->val,l.first),max(root->val,r.second)};
        
    }
    
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        
        solve(root,ans);
        return ans;
    }
};