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
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode *orig_root = root;
        TreeNode *p = root;
        while(root){
            p = root;
            root = (root->val > val) ? root->left : root->right;
        }
        TreeNode *node = new TreeNode(val);
        if(val > p->val){
            p->right = node;
        }
        else p->left = node;
        return orig_root;
    }
};