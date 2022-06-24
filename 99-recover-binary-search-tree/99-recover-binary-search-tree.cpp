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
    
    void solve(TreeNode* &root,TreeNode* &f,TreeNode* &s,TreeNode* &pre)
    {
        if(!root)return;
        
        solve(root->left,f,s,pre);
        if(pre&&pre->val>root->val)
        {
            if(!f)
            {
                f=pre;
                s=root;
            }
            else
            {
                s=root;
            }
        }
        pre=root;
        solve(root->right,f,s,pre);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        TreeNode* f=NULL,*s=NULL,*pre=NULL;
        
        solve(root,f,s,pre);
        
        swap(f->val,s->val);
    }
};