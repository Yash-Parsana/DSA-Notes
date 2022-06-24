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
    
    void solve(TreeNode* root,int val,int &ans)
    {
        if(!root)return;
        
        if(val!=root->val)
        {
            if(ans==-1)ans=root->val;
            else
                ans=min(ans,root->val);
            return;
        }
        if(root->left)
        {
            if(root->left->val==root->val)
            {
                solve(root->left,val,ans);
                solve(root->right,val,ans);
            }
            else
            {
                solve(root->right,val,ans);
                solve(root->left,val,ans);
            }
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int ans=-1;
        
        if(!root)return ans;
        
        solve(root,root->val,ans);

        return ans;
    }
};