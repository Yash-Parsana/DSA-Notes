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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root);
        int ans=INT_MAX,sum=INT_MIN,l=0;
        while(!q.empty())
        {
            int n=q.size();
            int tempsum=0;
            l++;
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                tempsum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(tempsum>sum)
            {
                sum=tempsum;
                ans=l;
            }
        }
        return ans;
    }
};