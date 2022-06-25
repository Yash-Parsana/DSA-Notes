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
    
    void pushLeft(TreeNode* root,stack<TreeNode*> &s)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        
    }
    void pushRight(TreeNode* root,stack<TreeNode*> &s)
    {
        while(root)
        {
            s.push(root);
            root=root->right;
        }
    }
    int front(stack<TreeNode*> &s)
    {
        TreeNode* curr=s.top();
        s.pop();
        pushLeft(curr->right,s);
        return curr->val;
    }
    int back(stack<TreeNode*> &s)
    {
        TreeNode* curr=s.top();
        s.pop();
        pushRight(curr->left,s);
        return curr->val;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        stack<TreeNode*>l,r;
        
        pushLeft(root,l);
        pushRight(root,r);
        
        int i=front(l),j=back(r);
        
        while(i<j)
        {
            if(i+j==k)return 1;
            else if(i+j>k)j=back(r);
            else i=front(l);
        }
        return 0;
        
    }
};