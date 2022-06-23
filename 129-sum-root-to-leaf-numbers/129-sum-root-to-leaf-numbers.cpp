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
    
    void solve(TreeNode* &root,int &sum,int temp)
    {
        if(!root)return;
        
        if(!root->left&&!root->right)
        {
            temp+=root->val;
            sum+=temp;
            return;
        }
        
        temp+=root->val;
        temp*=10;
        solve(root->left,sum,temp);
        solve(root->right,sum,temp);
        
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,ans,0);
        return ans;
    }
};