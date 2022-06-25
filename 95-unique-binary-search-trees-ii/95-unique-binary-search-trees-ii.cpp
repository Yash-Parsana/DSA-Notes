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
    map<vector<int>,vector<TreeNode*>> ma;
    
    vector<TreeNode*> solve(int l,int r){
        if(l>r)return {NULL};
        if(ma[{l,r}].size()>0)return ma[{l,r}];
		
        if(l==r){
            TreeNode *a=new TreeNode(l);
            ma[{l,l}].push_back(a);
            return ma[{l,l}];
        }
        
        vector<TreeNode*> v;
        for(int i=l;i<=r;i++){
            auto left=solve(l,i-1);
            auto right=solve(i+1,r);
            
            for(auto &x:left){
                for(auto &y:right){
                    TreeNode *a=new TreeNode(i);
                    a->left=x;
                    a->right=y;
                    v.push_back(a);
                }
            }
        }
        return ma[{l,r}]=v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};