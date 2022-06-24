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
    int findmax(TreeNode* root)
    {
        if(root==NULL) return INT_MIN;
        
        return max(root->val,findmax(root->right));
        
    }
    int findmin(TreeNode*root)
    {
        if(root==NULL)return INT_MAX;
        return min(root->val,findmin(root->left));
    }
        
    void solve(TreeNode* &root,int k)
    {
        if(root==NULL)return;
        
        if(root->val==k&&!root->left&&!root->right)
        {
            root=NULL;
            return;
        }
        
        if(root->val==k)
        {

            if(root->right){
                int val=findmin(root->right);
                root->val=val;
                solve(root->right,val);
            }
            else if(root->left)
            {
                int val=findmax(root->left);
                root->val=val;
                solve(root->left,val);
            }
        }
        
        if(root->val>k)
            solve(root->left,k);
        else
            solve(root->right,k);
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
    
        if(!root)return NULL;
        // if(root->val==key&&!root->left&&!root->right) return NULL;
        
        solve(root,key);
        return root;
        
    }
};