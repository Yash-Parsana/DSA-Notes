class node{
  public:
    node* next[26];
    int idx;
    vector<int> pal_idx;
    
    node(){
        for(int i = 0; i < 26; i++) next[i] = NULL;
        pal_idx = vector<int>();
        idx = -1;
    }
};


bool is_palendrom(string &s,int idx){
    
    int i = idx;
    int j = s.size() - 1;
    
    while(i < j){
        
        if(s[i] != s[j]) return false;
        i++;
        j--;
    
    }
    
    return true;
    
}




void insert(node* root,string &s,int idx,int index_of_word){
    
    if(idx == s.size()){
        
        root -> pal_idx.push_back(index_of_word);
        root -> idx = index_of_word;
        return;
        
    }
    
    if(is_palendrom(s,idx)) root -> pal_idx.push_back(index_of_word);
    
    int next_idx = s[idx] - 'a';
    
    node* next;
    
    if(root -> next[next_idx] != NULL){
        
        next = root -> next[next_idx];
        
    }
    else{
        
        next = new node();
        
        root -> next[next_idx] = next;
        
    }
    
    
    
    
    insert(next,s,idx+1,index_of_word);
    
}






void find(node* root,string &s,int idx,vector<vector<int>> &ans,int i){
    
    if(s.size() == idx){
        
        for(auto j:root -> pal_idx){
            if(j != i)
            ans.push_back({j,i});
        }
        
        return;
        
    }
    
    if(root -> idx != -1 && is_palendrom(s,idx))
             
            ans.push_back({root -> idx,i});
            
        
    
    
    
    node* next = root -> next[s[idx] - 'a'];
    
    
    if(next)
        
        find(next,s,idx+1,ans,i);
   
    
}





class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& arr) {
        
        vector<vector<int>> ans;
        
        node* root = new node();
        
        for(int i = 0 ; i < arr.size() ; i++)
            
            insert(root,arr[i],0,i);
        
        for(int i = 0 ; i < arr.size(); i++){
            
            reverse(arr[i].begin(),arr[i].end());
            
            find(root,arr[i],0,ans,i);
        }
        
        return ans;
    }
};