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
    int count=0;
    void getAllPath(TreeNode *root,long long targetSum){
        if(root==NULL) return;
        if(targetSum == root->val){
            count++;
        }
        getAllPath(root->left,targetSum-root->val);
        getAllPath(root->right,targetSum-root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        getAllPath(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }


};