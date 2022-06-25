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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
        if(!root->left&&!root->right)return 1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        int ans=0;
        
        while(!q.empty())
        {
            int n=q.size();
            int mi=q.front().second,s,e;
            
            for(int z=0;z<n;z++)
            {
                TreeNode* node=q.front().first;
                long long i=q.front().second-mi;
                
                q.pop();
                
                if(z==0)s=i;
                if(z==n-1)e=i;
                
                if(node->left)q.push({node->left,2*i+1});
                if(node->right)q.push({node->right,2*i+2});
            }
            ans=max(ans,e-s+1);
        }
        
        return ans;        
    }
};