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
    
    void solve(TreeNode*root,vector<int>&v,int &ans)
    {
        if(!root->left&&!root->right)
        {
            v[root->val]++;
            int odd=0;
            for(int z=1;z<10;z++)
            {
                if(v[z]&1)odd++;
            }
            v[root->val]--;
            if(odd<=1)
            {
                ans++;
                // for(int i:v)
                //     cout<<i<<" ";
                // cout<<endl;
            }
            return;
                
        }
        
        v[root->val]++;
        if(root->left)
            solve(root->left,v,ans);
        if(root->right)
            solve(root->right,v,ans);
        v[root->val]--;
        
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        int ans=0;
        solve(root,v,ans);
        return ans;
    }
};