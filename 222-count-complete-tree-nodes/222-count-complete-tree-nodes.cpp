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
    
    int nodes(TreeNode* root)
    {
        int l=0,r=0;
        
        TreeNode* temp=root;
        while(temp!=NULL)
        {
            temp=temp->left;
            l++;
        }
        temp=root;
        while(temp!=NULL)
        {
            temp=temp->right;
            r++;
        }
        
        if(l==r) return (1<<l)-1;
        
        return nodes(root->left)+nodes(root->right)+1;
        
    }
    
    int countNodes(TreeNode* root) {
        
        return nodes(root);
        
    }
};