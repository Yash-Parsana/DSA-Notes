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

class store
{
    public:
        
    int mx,mi,sum;
    
    store(int mx,int mi,int sum)
    {
        this->mx=mx;
        this->mi=mi;
        this->sum=sum;
    }
    
};

class Solution {
public:
    
    store solve(TreeNode* root,int &ans)
    {
        if(!root) return store(INT_MIN,INT_MAX,0);
        
        store l=solve(root->left,ans);
        store r=solve(root->right,ans);
        
        // cout<<l.mx<<" l "<<l.mi<<" "<<l.sum<<endl;        
        // cout<<r.mx<<" r "<<r.mi<<" "<<r.sum<<endl;

        
        if(l.mx<root->val&&r.mi>root->val)
        {
            ans=max(ans,l.sum+r.sum+root->val);
            return store(max(root->val,r.mx),min(root->val,l.mi),l.sum+r.sum+root->val);
        }
        
        return store(INT_MAX,INT_MIN,0);
        
    }
    
    int maxSumBST(TreeNode* root) {
        
        if(!root)return 0;
        int ans=INT_MIN;
        
        solve(root,ans);
        
        
        if(ans<0)return 0;
        return ans;
        
    }
};