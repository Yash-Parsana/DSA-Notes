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
    
    TreeNode* solve(vector<int> &v,int i,int j)
    {
        if(i>j)return NULL;
        
        int mid((i+j)/2);
        
        TreeNode* n=new TreeNode(v[mid]);
        
        if(i==j)return n;
        
        n->left=solve(v,i,mid-1);
        n->right=solve(v,mid+1,j);
        
        return n;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};