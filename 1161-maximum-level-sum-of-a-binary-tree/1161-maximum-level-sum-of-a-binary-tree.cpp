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
        
        int level=0,sum=INT_MIN;
        
        int l=1;
        q.push(root);q.push(NULL);
        while(!q.empty())
        {
            int temp=0;
            while(!q.empty()&&q.front()!=NULL)
            {
                TreeNode* curr=q.front();q.pop();
                temp+=curr->val;
                
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                
            }
            if(q.front()==NULL)
            {
                q.pop();
                if(temp>sum)
                {
                    sum=temp;
                    level=l;
                }
                l++;
                if(!q.empty())q.push(NULL);
            }
        }
        return level;
        
    }
};