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
    
    TreeNode* solve(vector<int>&ino,vector<int> &post,int &i,int s,int e)
    {
        if(s>e)return NULL;
        
        int curr=post[i];
        
        i--;
        
        TreeNode* n=new TreeNode(curr);
        
        if(s==e)return n;
        
        int z=s;
        for(z=s;z<=e;z++)
        {
            if(curr==ino[z]) break;
        }
        
        n->right=solve(ino,post,i,z+1,e);
        n->left=solve(ino,post,i,s,z-1);

        return n;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=postorder.size()-1;
        
        TreeNode* root=solve(inorder,postorder,i,0,i);
        return root;
    }
};