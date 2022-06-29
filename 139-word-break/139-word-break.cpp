class Solution {
public:
    int t[301][301];
    bool util(string s, unordered_map<string,int> & m ,int i , int j){
        if(i>j)
            return false;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        if (m[s.substr(i, j-i+1)])
			return true;
        
        bool ans=false;
        for(int k=i;k<j;k++){
            bool l,r;
            
            if(t[i][k]!=-1)
                l=t[i][k];
            
            else{
                l=util(s,m,i,k);
                t[i][k]=l;
            }
           
            if(t[k+1][j]!=-1)
                r=t[k+1][j];
            
            else{
               r=util(s,m,k+1,j);
               t[k+1][j]=r;
            }
           
            if(l&&r)
                ans= true;
    
        }
        
        return t[i][j]=ans;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto i:wordDict){
            m[i]++;
        }
        
        memset(t,-1,sizeof(t));
        return util(s,m,0,s.size()-1);
    }
};