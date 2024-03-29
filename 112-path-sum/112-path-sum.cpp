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
    
    bool hasPathSum(TreeNode* root,int target)
    {
        if(!root)return 0;
        if(root->left==NULL&&root->right==NULL)
        {
            if(target==root->val)return 1;
            return 0;
        }
        
        target-=root->val;
        return hasPathSum(root->left,target)||hasPathSum(root->right,target);
    }
    

};