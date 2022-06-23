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
    
    
    TreeNode*solve(int s,int e,int &i,vector<int> &pre,vector<int>&ino)
    {
        if(s>e)return NULL;
        
        int curr=pre[i];i++;
        TreeNode* n=new TreeNode(curr);
        
        if(s==e)return n;
        
        int z=s;
        for(z=s;z<=e;z++)
        {
            if(curr==ino[z])break;
        }
       
        n->left=solve(s,z-1,i,pre,ino);        
        n->right=solve(z+1,e,i,pre,ino);

        return n;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int i=0;
        TreeNode* root=solve(0,inorder.size()-1,i,preorder,inorder);
        return root;
    }
};