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
    TreeNode* xP,*yP;
    int xD,yD;
    
    void DFS(TreeNode* root,int l,TreeNode* parent,int x,int y)
    {
        if(!root)return ;
        if(root->val==x)
        {
            xD=l;
            xP=parent;
            return;
        }
        if(root->val==y)
        {
            yD=l;
            yP=parent;
            return;
        }
        DFS(root->left,l+1,root,x,y);
        DFS(root->right,l+1,root,x,y);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        xP=NULL;
        yP=NULL;
        xD=0;
        yD=0;
        
        DFS(root,0,NULL,x,y);
        if(xD==yD)
        {
            if(xP==yP)return 0;
            return 1;
        }
        return 0;
    }
};