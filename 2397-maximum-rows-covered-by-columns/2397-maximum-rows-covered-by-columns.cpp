class Solution {
public:
    
    void solve(vector<vector<int>>&v,vector<bool>vis,int i,int col,int &n,int &m,int &ans)
    {
        // if(i==m)return;
        // cout<<col<<" "<<i<<endl;
        if(col==0||i==m)
        {
            int tempans=0;
            
            for(int j=0;j<n;j++)
            {
                bool flag=0;
                for(int k=0;k<m;k++)
                {
                    if(v[j][k]&&!vis[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    tempans++;
            }
            ans=max(ans,tempans);
            return ;
        }
        vis[i]=1;
        solve(v,vis,i+1,col-1,n,m,ans);
        vis[i]=0;
        
        solve(v,vis,i+1,col,n,m,ans);
    }
    
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int n=mat.size(),m=mat[0].size();
        int ans=-1;
        
        vector<bool> vis(m,0);
        solve(mat,vis,0,cols,n,m,ans);
        return ans;
    }
};