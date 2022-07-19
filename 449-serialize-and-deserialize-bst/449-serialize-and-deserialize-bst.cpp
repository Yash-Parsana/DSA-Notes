/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

       int strToint(string s){
        if(s == "0") return 0;
        int i =0,ans=0;
        while(s[i] != '\0'){
            int t = s[i++] - '0';
            ans = ans*10 + t;
        }
        return ans;
    }
    string intTostr(int n){
        string s;
        if(n == 0) return "0";
        while(n){
            char t = n%10 + '0';
            s+=t;
            n = n/10;
        }
        return s;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string ls;
        ls = intTostr(root->val) + ",";
        ls += serialize(root->left);
        ls += serialize(root->right);
        return ls;
    }
    TreeNode* build(vector<int> &pr,int &i,int bound){
        if(i == pr.size() || pr[i] > bound) return NULL;
        TreeNode* root = new TreeNode(pr[i++]);
        root->left = build(pr,i,root->val);
        root->right = build(pr,i,bound);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        vector<int> a;
        string t;
        for(int i=0;i<data.length();i++){
            char x = data[i];
            if(x == ','){ a.push_back(strToint(t)); t = "";}
            else t = x + t;
        }
        int i=0;
        return build(a,i,INT_MAX);
    }  
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;