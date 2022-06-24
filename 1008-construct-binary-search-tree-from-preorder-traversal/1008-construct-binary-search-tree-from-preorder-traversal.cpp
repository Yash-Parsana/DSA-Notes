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
    
    TreeNode* solve(int mi,int mx,int &i,vector<int> &pre)
    {
        if(i>=pre.size())return NULL;
        
        if(pre[i]>mi&&pre[i]<mx)
        {
            int curr=pre[i];
            TreeNode* n=new TreeNode(curr);
            i++;
            n->left=solve(mi,curr,i,pre);
            n->right=solve(curr,mx,i,pre);
            
            return n;
        }
        return NULL;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(INT_MIN,INT_MAX,i,preorder);
    }
};