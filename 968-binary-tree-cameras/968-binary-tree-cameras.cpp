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

class G
{
    public:
    int status; // -1 i need , 0 i am covered , 1 i have
    int ans;
    
    G(){}
    G(int s,int a)
    {
        status=s;
        ans=a;
    }
    
};

class Solution {
public:
    
    G solve(TreeNode* root,bool b)
    {
        G temp(-1,0),l(0,0),r(0,0);

        if(root->left!=NULL)
        {
            l=solve(root->left,0);  
        }
        if(root->right!=NULL)
        {
            r=solve(root->right,0);
        }
        
        if(l.status==-1||r.status==-1)
        {
            temp.status=1;
            temp.ans=l.ans+r.ans+1;
        }
        else if(l.status==1||r.status==1)
        {
            temp.status=0;
            temp.ans=l.ans+r.ans;
        }
        else
        {
            temp.status=-1;
            temp.ans=l.ans+r.ans;
            if(b) temp.ans++;
        }
        
        return temp;
        
    }
    
    
    int minCameraCover(TreeNode* root) {
        G ans=solve(root,1);
        
        return ans.ans;
    }
};