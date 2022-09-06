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
    
    bool solve(TreeNode* &root)
    {
        // if(!root)return 0;
        
        bool l=0;
        if(root->left)
            l=solve(root->left);
        bool r=0;
        if(root->right)
            r=solve(root->right);
        
        if(!l)
            root->left=NULL;
        if(!r)
            root->right=NULL;
        
        if(l||r||root->val==1)
            return 1;
        return 0;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool b=solve(root);
        if(!b)return NULL;
        return root;
    }
};